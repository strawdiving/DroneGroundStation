#include "UAS.h"
#include "Vehicle.h"
#include "linkmanager.h"
#include "PX4AutopioltPlugins/PX4AutopilotPlugin.h"
#include <QDebug>

UAS::UAS(Vehicle *vehicle)
    : _uasId(vehicle->id())
    , _parameterLoader(NULL)
    , _vehicle(vehicle)
{

}

UAS::~UAS()
{

}

void UAS::startCalibration(CalibrationType calType)
{
    qDebug()<<"UAS:startCalibration"<<calType;
    if(!_vehicle) {
        return;
    }

    int gyroCal = 0;
    int magCal = 0;
    int magDetailCal = 0;
    int accelDetailCal = 0;
    int accelCal = 0;
    int gyroTmpCal = 0;
    int accelTmpCal = 0;

    switch(calType) {
    case CalibrationGyro:
        gyroCal = 1;
        break;
    case CalibrationMag:
        magCal = 1;
        break;
    case CalibrationMagDetail:
        magDetailCal = 1;
        break;
    case CalibrationAccelDetail:
        accelDetailCal = 1;
        break;
    case CalibrationAccel:
        accelCal = 1;
        break;
    case CalibrationGyroTmp:
        gyroTmpCal = 1;
        break;
    case CalibrationAccelTmp:
        accelTmpCal = 1;
        break;
    }

    mavlink_message_t msg;
    mavlink_command_long_t command;
    command.target_system = _uasId;
    command.target_component = 0;
    command.command = MAV_CMD_PREFLIGHT_CALIBRATION;
    command.confirmation = 0; // 0 = first transmission of command
    command.param1 = gyroCal; //gyro cal
    command.param2 = magCal; //mag cal
    command.param3 = magDetailCal; //mag detail cal
    command.param4 = accelDetailCal; //accel detail cal
    command.param5 = accelCal; //accel cal
    command.param6 = gyroTmpCal; //gyro temp cal
    command.param7 = accelTmpCal; //accel temp cal
    mavlink_msg_command_long_encode(_uasId,defaultComponentId,&msg,&command);
    _vehicle->linkManager()->sendMessage(msg);
}

void UAS::stopCalibration(void)
{
    if(!_vehicle) {
        return;
    }

    mavlink_message_t msg;
    mavlink_command_long_t command;
    command.target_system = _uasId;
    command.target_component = 0;
    command.command = MAV_CMD_PREFLIGHT_CALIBRATION;
    command.confirmation = 0; // 0 = first transmission of command
    command.param1 = 0; //gyro cal
    command.param2 = 0; //mag cal
    command.param3 = 0; //ground pressure
    command.param4 = 0; //radio cal
    command.param5 = 0; //accel cal
    command.param6 = 0; //airspeed cal (compass/motor interference cal)
    command.param7 = 0; //empty?
    mavlink_msg_command_long_encode(_uasId,defaultComponentId,&msg,&command);
    _vehicle->linkManager()->sendMessage(msg);
}

void UAS::receiveMessage(SerialLink*link, mavlink_message_t &message)
{
    Q_UNUSED(link)
    //qDebug()<<"uas:receiveMessage"<<message.sysid<<message.compid;
    if(message.sysid == _uasId) {
        switch(message.msgid) {

        case MAVLINK_MSG_ID_PARAM_VALUE:
        {
            //qDebug()<<"Param_Value message received";
            mavlink_param_value_t param_value;
            mavlink_msg_param_value_decode(&message,&param_value);
            //QByteArray(const char *data, int size = -1)
            QByteArray bytes(param_value.param_id,MAVLINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN);
            QString paramName(bytes);

            mavlink_param_union_t paramUnion;
            paramUnion.param_float = param_value.param_value;
            paramUnion.type = param_value.param_type;

            _processParamValueMsg(message,paramName,param_value,paramUnion);
        }
            break;

        case MAVLINK_MSG_ID_STATUSTEXT:
        {
            //qDebug()<<"STATUSTEXT received";
            mavlink_statustext_t statustext;
            mavlink_msg_statustext_decode(&message,&statustext);
            //Status text message, without null termination character
            QByteArray b(statustext.text);
            b.append('\0');
            QString text = b;
            //QGC source code
            /*
            QByteArray b;
            b.resize(MAVLINK_MSG_STATUSTEXT_FIELD_TEXT_LEN+1);
            mavlink_msg_statustext_get_text(&message, b.data());

            // Ensure NUL-termination
            b[b.length()-1] = '\0';
            QString text = QString(b);
            int severity = mavlink_msg_statustext_get_severity(&message);
            */

            // If the message is NOTIFY or higher severity, or starts with a '#',
            // then read it aloud.
            emit textMessageReceived(message.compid,text);
        }
            break;
        }
    }
}

void UAS::_processParamValueMsg(mavlink_message_t &message,const QString &paramName,const mavlink_param_value_t &rawValue,mavlink_param_union_t &paramUnion)
{
    int componentId = message.compid;
    QVariant paramValue;
    paramValue = paramUnion.param_float;

   /* switch(rawValue.param_type)
    {
    case MAV_PARAM_TYPE_UINT8:
        paramValue = QVariant(paramUnion.param_uint8);
        break;
    case MAV_PARAM_TYPE_INT8:
        paramValue = QVariant(paramUnion.param_int8);
        break;
    case MAV_PARAM_TYPE_UINT16:
        paramValue = QVariant(paramUnion.param_uint16);
        break;
    case MAV_PARAM_TYPE_INT16:
        paramValue = QVariant(paramUnion.param_int16);
        break;
    case MAV_PARAM_TYPE_UINT32:
        paramValue = QVariant(paramUnion.param_uint32);
        break;
    case MAV_PARAM_TYPE_INT32:
        paramValue = QVariant(paramUnion.param_int32);
        break;
    case MAV_PARAM_TYPE_REAL32:
        paramValue = QVariant(paramUnion.param_float);
        break;

        default:
            qCritical() << "INVALID DATA TYPE USED AS PARAMETER VALUE: " << rawValue.param_type;
    }
*/
    //qDebug() << "Received PARAM_VALUE" << paramName << paramValue << rawValue.param_type;
    emit parameterUpdate(componentId, paramName,rawValue.param_count,rawValue.param_index,rawValue.param_type,paramValue);
}

void UAS::shutdownVehicle(void)
{
    _vehicle = NULL;
}

void UAS::readParameterRaw(int componentId, const QString& paramName, int paramIndex)
{
    Q_UNUSED(paramIndex)
    mavlink_message_t msg;
    mavlink_param_request_read_t param;

    Q_UNUSED(msg)
    Q_UNUSED(param)
    char fixedParamName[MAVLINK_MSG_PARAM_REQUEST_READ_FIELD_PARAM_ID_LEN];
    strncpy(fixedParamName,paramName.toStdString().c_str(),sizeof(fixedParamName));

    //255,0 our system and component id
    // _vehicle->id(), componentId , target system and component id
    mavlink_msg_param_request_read_pack(255,0,&msg,_vehicle->id(),componentId,fixedParamName,paramIndex);
    _vehicle->linkManager()->sendMessage(msg);
}

void UAS::writeParameterRaw(int componentId, const QString& paramName, const QVariant& value)
{
    mavlink_param_set_t paramSet;
    mavlink_param_union_t unionValue;
    FactMetaData::ValueType_t factType = _vehicle->autopilotPlugin()->getParamFact(componentId,paramName)->type();

    paramSet.param_type = _factTypeToMavType(factType);

    switch(factType) {
    case FactMetaData::typeUint8:
        unionValue.param_uint8 = (uint8_t)value.toUInt();
        break;

    case FactMetaData::typeInt8:
        unionValue.param_int8 = (int8_t)value.toInt();
        break;

    case FactMetaData::typeUint16:
        unionValue.param_uint16 = (uint16_t)value.toUInt();
        break;

    case FactMetaData::typeInt16:
        unionValue.param_int16 = (int16_t)value.toInt();
        break;

    case FactMetaData::typeUint32:
        unionValue.param_uint32 = (uint32_t)value.toUInt();
        break;

    case FactMetaData::typeFloat:
        unionValue.param_float = value.toFloat();
        break;

    default:
        qDebug()<<"Unsupported fact type: "<<factType;

    case FactMetaData::typeInt32:
        unionValue.param_int32 = (int32_t)value.toInt();
        break;
    }

    paramSet.param_value = unionValue.param_float;
    paramSet.target_system = (uint8_t)_vehicle->id();
    paramSet.target_component = (uint8_t)componentId;

    strncpy(paramSet.param_id,paramName.toStdString().c_str(),sizeof(paramSet.param_id));
    mavlink_message_t message;
    // id of this system and component
    mavlink_msg_param_set_encode(255,0,&message,&paramSet);
    _vehicle->linkManager()->sendMessage(message);
}

MAV_PARAM_TYPE UAS::_factTypeToMavType(FactMetaData::ValueType_t valueType)
{
    switch(valueType) {
    case FactMetaData::typeUint8:
        return MAV_PARAM_TYPE_UINT8;
    case FactMetaData::typeUint16:
        return MAV_PARAM_TYPE_UINT16;
    case FactMetaData::typeUint32:
        return MAV_PARAM_TYPE_UINT32;
    case FactMetaData::typeInt8:
        return MAV_PARAM_TYPE_INT8;
    case FactMetaData::typeInt16:
        return MAV_PARAM_TYPE_INT16;
    case FactMetaData::typeInt32:
        return MAV_PARAM_TYPE_INT32;
    case FactMetaData::typeFloat:
        return MAV_PARAM_TYPE_REAL32;
    default:
        qDebug()<<"Unsupported fact type: "<<valueType;
        return MAV_PARAM_TYPE_INT32;
    }
}

 void UAS::writePIDParams(QString moduleName,QMap<QString,float>paramValue)
 {
     mavlink_message_t msg;

     if(moduleName == "PITCH") {
         mavlink_attitude_pitch_pid_t pitch_pid;
         pitch_pid.MC_PITCH_P = paramValue.value("P");
         pitch_pid.MC_PITCHRATE_P = paramValue.value("RateP");
         pitch_pid.MC_PITCHRATE_I = paramValue.value("RateI");
         pitch_pid.MC_PITCHRATE_D = paramValue.value("RateD");
         mavlink_msg_attitude_pitch_pid_encode(255,0,&msg,&pitch_pid);
     }
     else if (moduleName == "ROLL") {
         mavlink_attitude_roll_pid_t roll_pid;
         roll_pid.MC_ROLL_P = paramValue.value("P");
         roll_pid.MC_ROLLRATE_P = paramValue.value("RateP");
         roll_pid.MC_ROLLRATE_I = paramValue.value("RateI");
         roll_pid.MC_ROLLRATE_D = paramValue.value("RateD");
         mavlink_msg_attitude_roll_pid_encode(255,0,&msg,&roll_pid);
     }
     else if (moduleName == "YAW") {
         mavlink_attitude_yaw_pid_t yaw_pid;
         yaw_pid.MC_YAW_P = paramValue.value("P");
         yaw_pid.MC_YAWRATE_P = paramValue.value("RateP");
         yaw_pid.MC_YAWRATE_I = paramValue.value("RateI");
         yaw_pid.MC_YAWRATE_D = paramValue.value("RateD");
         mavlink_msg_attitude_yaw_pid_encode(255,0,&msg,&yaw_pid);
     }
     else if (moduleName == "X") {
         mavlink_position_x_pid_t x_pid;
         x_pid.MPC_X_P= paramValue.value("P");
         x_pid.MPC_XRATE_P = paramValue.value("RateP");
         x_pid.MPC_XRATE_I = paramValue.value("RateI");
         x_pid.MPC_XRATE_D = paramValue.value("RateD");
         mavlink_msg_position_x_pid_encode(255,0,&msg,&x_pid);
     }
     else if (moduleName == "Y") {
         mavlink_position_y_pid_t y_pid;
         y_pid.MPC_Y_P= paramValue.value("P");
         y_pid.MPC_YRATE_P = paramValue.value("RateP");
         y_pid.MPC_YRATE_I = paramValue.value("RateI");
         y_pid.MPC_YRATE_D = paramValue.value("RateD");
         mavlink_msg_position_y_pid_encode(255,0,&msg,&y_pid);
     }
     else if (moduleName == "Z") {
         mavlink_position_z_pid_t z_pid;
         z_pid.MPC_Z_P= paramValue.value("P");
         z_pid.MPC_ZRATE_P = paramValue.value("RateP");
         z_pid.MPC_ZRATE_I = paramValue.value("RateI");
         z_pid.MPC_ZRATE_D = paramValue.value("RateD");
         mavlink_msg_position_z_pid_encode(255,0,&msg,&z_pid);
     }
     _vehicle->linkManager()->sendMessage(msg);
 }
