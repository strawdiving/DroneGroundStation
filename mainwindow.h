#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#define M_PI (3.14159265358979323846)

#include <QMainWindow>
#include <QSerialPort>
#include<QTimer>
#include <QElapsedTimer>
#include "SerialCommunication.h"
#include "common/mavlink.h"
#include "ParameterLoader.h"
#include "SetupWidget.h"
#include "attitude_indicator.h"
#include "audio_worker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static MainWindow*  _create();
    ~MainWindow();

    MainWindow* instance(void);
    //MessagePanel* messagePanel(void) {return _messagePanel;}

    void paintEvent(QPaintEvent* event);
    void closeEvent(QCloseEvent* event);
    void init();
    //void enableAllDataTransmission(SerialLink *link);//pack message, and send message to FC to request param list

    int    getSystemId() {return systemId;}

private slots:
    void _updateState();

public slots:
    /// Signals from LinkManager
    void _telemetryChange(uint8_t rssi);
    void _modeChange(QString shortModeText);
    void _attitudeChange(mavlink_attitude_t *attitude);
    void _batteryChange(int8_t battery_remaining);
    void _GPSStatusChange(mavlink_gps_raw_int_t* gps_raw_int);
    void _globalPositionChange(mavlink_global_position_int_t* global_position_int);
    void _localPositionChange(mavlink_local_position_ned_t* local_position);
    void _groundSpeedChange(float fly_speed);
    void _statusChange(uint8_t status);
    void _armedChange(uint32_t);
    void on_pushButton_Connect_clicked();

    void _activeVehicleChanged(Vehicle* vehicle);

protected:


private:
    void _showFlytime(void);

    Ui::MainWindow *ui;
    QPalette w_palette; //warning
    QPalette c_palette; //common
    bool                   port_open;
    bool                   link_connected;
    bool                   connectionLost;
    bool                   bool_flying;
    uint32_t            _armed;
    float                  _fly_distance;
    float                  _fly_velocity;
    static const uint16_t   battery_lowbound = 25;// 25% remaining
    // TIMEOUT CONSTANTS
    static const unsigned int timeoutIntervalHeartbeat = 6; ///< Heartbeat timeout is 3.5 seconds
    SerialConfiguration* _config;
    LinkManager* _linkMgr;//manage serial links
    SerialLink* _currentLink;//currently connected link
    Vehicle* _vehicle;

    SetupWidget* _calWidget;

    QTimer             _portListTimer;//time to search for valid port
    QTimer             _statusTimer;
    quint64             _lastTakeoffTime;

    int systemId;
    QString             _mode;
    int8_t               _status;

    Attitude_Indicator *_attitude_indicator;//display gauge instruments
    QElapsedTimer _lowBatteryAnnounceTimer;
    Audio_Worker* _audio;
};

#endif // MAINWINDOW_H
