#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>
#include <common/mavlink.h>
#include "SerialCommunication.h"
#include <QVariant>
#include <mavlink_types.h>
#include "FactMetaData.h"

class PX4FirmwarePlugin;
class PX4AutopilotPlugin;
class Vehicle;
class LinkManager;
class UAS;
class ParameterLoader;

class Vehicle : public QObject
{
    Q_OBJECT
public:
    explicit Vehicle(SerialLink* link, int vehicleId, PX4FirmwarePlugin* firmwarePlugin);
    ~Vehicle();

    PX4AutopilotPlugin* autopilotPlugin(void) {return _autopilotPlugin;}
    UAS* uas(void) {return _uas;}
    ParameterLoader* parameterLoader(void) {return _parameterLoader;}
    PX4FirmwarePlugin* firmwarePlugin(void) {return _firmwarePlugin;}
    LinkManager* linkManager(void) { return _linkMgr;}

    int id(void) { return _vehicleId;}

private:
    QString _flightMode(uint8_t baseMode);
    void _addLink(SerialLink* link);
    void _handleHeartbeat(mavlink_message_t& message);

    PX4FirmwarePlugin* _firmwarePlugin;
    PX4AutopilotPlugin* _autopilotPlugin;
    SerialLink* _link;
    LinkManager * _linkMgr;
    UAS* _uas;
    ParameterLoader* _parameterLoader;

    int                     _vehicleId;
    //flight modes
    uint8_t             _base_mode;
    uint32_t           _armed;
    int8_t               _system_status;

signals:
    void linkDeleted(Vehicle* vehicle);

    void modeChanged(QString shortModeText);
    void telemetryChanged(uint8_t rssi);
    void attitudeChanged(mavlink_attitude_t* attitude);
    void altitudeChanged(float pressure_alt);
    void batteryChanged(int8_t voltage_battery);
    void GPSStatusChanged(mavlink_gps_raw_int_t* gps_raw_int);
    void globalPositionChanged(mavlink_global_position_int_t* global_position_int);
    void localPositionChanged(mavlink_local_position_ned_t* local_position);
    void groundSpeedChanged(float);
    void statusChanged(uint8_t status);
    void armedChanged(uint32_t);

    void PIDSetConfirm(mavlink_pid_set_confirm_t pid_set_confirm);

public slots:
    void _linkDeleted(SerialLink* link);
    void _mavlinkMessageReceived(SerialLink*link, mavlink_message_t &message);
};

#endif // VEHICLE_H
