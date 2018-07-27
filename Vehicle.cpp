#include "Vehicle.h"
#include "PX4FirmwarePlugin.h"
#include "PX4AutopioltPlugins/PX4AutopilotPlugin.h"

#include "ParameterLoader.h"
#include "QuadApplication.h"
#include "linkmanager.h"
#include "UAS.h"
#include <QDebug>

Vehicle::Vehicle(SerialLink* link, int vehicleId,PX4FirmwarePlugin *firmwarePlugin)
    : _autopilotPlugin(NULL)
    , _vehicleId(vehicleId)
    , _link(NULL)
    , _uas(NULL)
    , _parameterLoader(NULL)
    , _base_mode(0)
    , _system_status(-1)
    , _firmwarePlugin(firmwarePlugin)
{
    //qDebug()<<"vehicle";
    _addLink(link);

    _autopilotPlugin = new PX4AutopilotPlugin(this,this);

    _linkMgr = qgcApp()->toolbox()->linkManager();
    connect(_linkMgr,&LinkManager::messageReceived,this,&Vehicle::_mavlinkMessageReceived);

    _uas = new UAS(this);

    _parameterLoader = new ParameterLoader(this,this);
    connect(_parameterLoader,&ParameterLoader::paramsReady,_autopilotPlugin,&PX4AutopilotPlugin:: _parametersReadyChanged);
}

Vehicle::~Vehicle()
{
delete _parameterLoader;
}

 void Vehicle::_addLink(SerialLink* link)
 {
     if(!_link) {
         _link = link;
         connect(qgcApp()->toolbox()->linkManager(),&LinkManager::linkDisconnected,this,&Vehicle::_linkDeleted);
     }
 }

void Vehicle::_linkDeleted(SerialLink* link)
{
    Q_UNUSED(link)
    _link = NULL;
    qDebug()<<"Vehicle : link deleted";
    emit linkDeleted(this);
}

void Vehicle::_mavlinkMessageReceived(SerialLink*link, mavlink_message_t &message)
{
    //qDebug()<<"vehicle: mavlinkMessageReceived";
    if(_link != link){
        _addLink(link);
    }

    switch(message.msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT:
        _handleHeartbeat(message);
        break;
    //#1
    case MAVLINK_MSG_ID_SYS_STATUS:
    {
        mavlink_sys_status_t sys_status;
        mavlink_msg_sys_status_decode(&message,&sys_status);
        emit batteryChanged(sys_status.battery_remaining);
    }
        break;

    //#24
     case MAVLINK_MSG_ID_GPS_RAW_INT:
    {
        mavlink_gps_raw_int_t gps_raw_int;
        mavlink_msg_gps_raw_int_decode(&message,&gps_raw_int);
        emit GPSStatusChanged(&gps_raw_int);
    }
        break;

    //#30
    case MAVLINK_MSG_ID_ATTITUDE:
    {
        mavlink_attitude_t attitude;
        mavlink_msg_attitude_decode(&message, &attitude);
        emit attitudeChanged(&attitude);
     }
        break;

    //#32
    case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
    {
        mavlink_local_position_ned_t local_position;
        mavlink_msg_local_position_ned_decode(&message, &local_position);
        emit localPositionChanged(&local_position);
     }
        break;

    //#33
    case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
    {
        mavlink_global_position_int_t global_position_int;
        mavlink_msg_global_position_int_decode(&message, &global_position_int);

        emit globalPositionChanged(&global_position_int);
     }
        break;

        //#65
      case MAVLINK_MSG_ID_RC_CHANNELS:
      {
         mavlink_rc_channels_t rc_channels;
         mavlink_msg_rc_channels_decode(&message,&rc_channels);

         emit telemetryChanged(rc_channels.rssi);
      }
         break;

    case MAVLINK_MSG_ID_PID_SET_Confirm:
    {
        //qDebug()<<"Vehicle: PID_SET_Confirm message received";
        mavlink_pid_set_confirm_t pid_set_confirm_t;
        mavlink_msg_pid_set_confirm_decode(&message,&pid_set_confirm_t);
        emit PIDSetConfirm(pid_set_confirm_t);
    }

    default:
        break;
    }
    if((message.msgid == MAVLINK_MSG_ID_PARAM_VALUE) || (message.msgid == MAVLINK_MSG_ID_STATUSTEXT))
    {
        _uas->receiveMessage(link,message);
    }
}

void Vehicle::_handleHeartbeat(mavlink_message_t& message)
{
    mavlink_heartbeat_t heartbeat;
    mavlink_msg_heartbeat_decode(&message, &heartbeat);

    if(_system_status != heartbeat.system_status) {
        _system_status = heartbeat.system_status;
        emit statusChanged(heartbeat.system_status);
    }

    uint32_t armed = heartbeat.custom_mode;
    if(_armed != armed)
    {
        _armed = armed;
        emit armedChanged(_armed);
    }

    if (_base_mode != heartbeat.base_mode)
    {
        _base_mode = heartbeat.base_mode;
        QString shortModeText = _flightMode(_base_mode);

        emit modeChanged(shortModeText);
    }
}

QString Vehicle::_flightMode(uint8_t baseMode)
{
    QString flightMode = "Unknown";
    //qDebug()<<"baseMode"<<baseMode;
    switch(baseMode){
    case 2:
        flightMode = QString(tr("手动"));
        break;
    case 3:
        flightMode = QString(tr("定高"));
        break;
    case 4:
        flightMode = QString(tr("定点"));
        break;
    default:
        qDebug()<<"Unknown flight mode:";
        break;
        }
    return flightMode;
}
