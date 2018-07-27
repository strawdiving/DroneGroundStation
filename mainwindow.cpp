#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>
#include <QtDebug>
#include <QtCore>
#include <QMessageBox>
#include <QCloseEvent>
#include <QLayout>
#include <QFile>
#include "linkmanager.h"

#include "QuadApplication.h"
#include "VehicleManager.h"
#include "Vehicle.h"

#include "PX4AutopioltPlugins/PX4AutopilotPlugin.h"

static MainWindow* _instance = NULL;

MainWindow* MainWindow::_create()
{
    Q_ASSERT(_instance == NULL);
    _instance = new MainWindow();
    Q_ASSERT(_instance);
    return _instance;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , port_open(false)
  , connectionLost(true)
  , bool_flying(false)
  , _armed(0)
  , _status(0)
  , _fly_distance(0.0)
  , _fly_velocity(0.0)
  , systemId(DEFAULT_SYSTEM_ID)
  , _vehicle(NULL)

{
    ui->setupUi(this);
    setFixedSize(960,600);
    this->setStyleSheet("QPushButton {background: #cfe2f3}"
                        "QPushButton:pressed {background: 6699cc}");

    ui->pushButton_Connect->setFixedWidth(100);

    c_palette.setColor(QPalette::WindowText,Qt::black);
    w_palette.setColor(QPalette::WindowText,Qt::red);

    // Invalidate the timer to signal first announce
    _lowBatteryAnnounceTimer.invalidate();
    _attitude_indicator = new Attitude_Indicator();
    _audio = new Audio_Worker();

    ui->gridLayout_Gauge->setSpacing( 2 );
    ui->gridLayout_Gauge->setMargin( 0 );
    ui->gridLayout_Gauge->addWidget(_attitude_indicator,0,0,1,1);

    _calWidget = new SetupWidget(this);
    ui->stackedWidget_Summary->addWidget(_calWidget);
    ui->stackedWidget_Summary->setCurrentWidget(_calWidget);

    connect(&_portListTimer, &QTimer::timeout, this, &MainWindow::init);
    _portListTimer.start(1000);

    _linkMgr = qgcApp()->toolbox()->linkManager();    

    connect(qgcApp()->toolbox()->vehicleManager(),&VehicleManager::activeVehicleChanged,this,&MainWindow::_activeVehicleChanged);
    connect(qgcApp()->toolbox()->vehicleManager(),&VehicleManager::activeVehicleChanged,_calWidget,&SetupWidget::_activeVehicleChanged);
    show();
}

void MainWindow::_activeVehicleChanged(Vehicle* vehicle)
{
    if(vehicle) {
        _vehicle = vehicle;

        connect(_vehicle, &Vehicle::modeChanged,this,&MainWindow::_modeChange);
        connect(_vehicle, &Vehicle::attitudeChanged,this, &MainWindow::_attitudeChange);
        connect(_vehicle, &Vehicle::telemetryChanged,this, &MainWindow::_telemetryChange);
        connect(_vehicle, &Vehicle::batteryChanged,this, &MainWindow::_batteryChange);
        connect(_vehicle, &Vehicle::GPSStatusChanged,this,&MainWindow::_GPSStatusChange);
        connect(_vehicle, &Vehicle::globalPositionChanged,this,&MainWindow::_globalPositionChange);
        connect(_vehicle, &Vehicle::localPositionChanged,this,&MainWindow::_localPositionChange);
        connect(_vehicle, &Vehicle::groundSpeedChanged,this,&MainWindow::_groundSpeedChange);   
        connect(_vehicle, &Vehicle::statusChanged,this,&MainWindow::_statusChange);        
        connect(_vehicle, &Vehicle::armedChanged,this,&MainWindow::_armedChange);
  }
}

 MainWindow* MainWindow::instance(void)
 {
     return _instance;
 }

//display config description and baudrate
void MainWindow::init()
{
    _linkMgr->_updateConfigurationList();

    QList<SerialConfiguration*> configs = _linkMgr->getSerialConfigurationList();
    foreach (SerialConfiguration* config, configs)
    {
     if(ui->label_Portname->text()!=config->description())
     {
     ui->label_Portname->setText(config->description());
     ui->label_Baudrate->setText(QString::number(config->baud()));
     qDebug()<<config->description()<<config->baud();
      }
    _portListTimer.stop();
    _config = config;
    ui->pushButton_Connect->setEnabled(true);
     }

    /*SerialConfiguration* config = new SerialConfiguration("SIASUN");
    config->setPortName("COM4");
    config->setBaud(57600);
    ui->label_Portname->setText(config->portName());
    ui->label_Baudrate->setText(QString::number(config->baud()));
    _portListTimer.stop();

    _config = config;
    ui->pushButton_Connect->setEnabled(true);
*/
}

//create serial link, start thread, open serial port
void MainWindow::on_pushButton_Connect_clicked()
{
     Q_ASSERT(_currentLink);
     if(port_open == false)
     {
     if(_config) {
        _linkMgr->createConnectedLink(_config);
        if(_currentLink=_linkMgr->getLink()) {
          port_open = true;
          ui->pushButton_Connect->setText("断开连接");
          //enableAllDataTransmission(_currentLink);
          connect(&_statusTimer,&QTimer::timeout,this,&MainWindow::_updateState);
          _statusTimer.start(500);
         }
        else {
            qDebug()<<"can‘t create link!";
         }
       }
     }
     else{
         if (_currentLink->isConnected()) {
            _linkMgr->disconnectLink(_currentLink);
            port_open = false;
            ui->pushButton_Connect->setText("连接");
         }
      }
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    Q_UNUSED(event)
    /*QMessageBox::StandardButton button;
    button = QMessageBox::question(this,tr("关闭程序"),
                           tr("确认退出程序？"),
                                   QMessageBox::Yes | QMessageBox::No);
     if(button == QMessageBox::Yes){
         event->accept();
     }
     if(button == QMessageBox::No){
         event->ignore();
     }
     */
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
}

void MainWindow::_updateState()
{
    quint64 curTime =static_cast<quint64>(QDateTime::currentMSecsSinceEpoch());

    quint64 lastHeartbeat = _linkMgr->getHeartbeatTime();
    quint64 heartbeatInterval = (curTime - lastHeartbeat)/1000.0;
    //qDebug()<<"last time"<<lastHeartbeat<<"now time: "<<curTime<<"interval"<<heartbeatInterval;

    // Check if heartbeat timed out
    if(!connectionLost && (heartbeatInterval>timeoutIntervalHeartbeat))
    {
        connectionLost = true;
        ui->label_Message->setPalette(w_palette);
        ui->label_Message->setText("链接丢失!");

        if (_currentLink->isConnected()) {
           _linkMgr->disconnectLink(_currentLink);
           port_open = false;
           ui->pushButton_Connect->setText("连接");
         }
    }

    // Update connection loss time on each iteration
        if (connectionLost && (heartbeatInterval > timeoutIntervalHeartbeat))
        {
            quint64 connectionLossTime = heartbeatInterval;
            ui->label_Message->setPalette(w_palette);
            ui->label_Message->setText("链接丢失: "+QString::number(connectionLossTime));
        }
    // Connection gained
    if(connectionLost && (heartbeatInterval<timeoutIntervalHeartbeat))
    {
        connectionLost = false;
        ui->label_Message->setPalette(c_palette);
        ui->label_Message->setText("连接成功!");
    }
}

MainWindow::~MainWindow()
{
    _instance = NULL;
    delete ui;
    if (_currentLink) {
        _linkMgr->disconnectLink(_currentLink);
      }
}

void  MainWindow::_telemetryChange(uint8_t rssi)
{
    ui->progressBar_RC->setValue(rssi);
    ui->label_RC->setText(QString::number(rssi));
}

void MainWindow::_modeChange(QString shortModeText)
{
    //qDebug()<<"_mode Change";
    ui->label_Mode->setText(shortModeText);
}

void MainWindow::_statusChange(uint8_t status)
{    
    _status = status;

    //flying
    if(_status == 4) {
        if(!bool_flying) {
            bool_flying = true;
            _lastTakeoffTime = static_cast<quint64>(QDateTime::currentMSecsSinceEpoch());
        }
        _showFlytime();
    }
    else {
        if(bool_flying) {
            //bool_flying = false;
            // hide bool_flying = false ,time
            _showFlytime();
        }
    }

    if(status == 0||status==1) {
        ui->tabWidget->setTabEnabled(0,true);
    }
    else {
        ui->tabWidget->setTabEnabled(0,false);
    }

    QString fltStatus;
    switch (status) {
    case 0 :
        fltStatus = "Landed";
        break;
    case 1:
        fltStatus = "Initiating";
        break;
    case 2:
        fltStatus = "Taking off";
        break;
    case 3:
        fltStatus = "Landing";
        break;
    case 4:
        fltStatus = "Flying";
        break;
    case 5:
        fltStatus = "Hovering";
        break;
    case 6:
        fltStatus = "FreeFall";
        break;
    case 7:
        fltStatus = "UpsideDown";
        break;
    case 8:
        fltStatus = "Tumble";
        break;
    }
    ui->label_Status->setText(fltStatus);
}

void MainWindow::_showFlytime(void)
{
    quint64 currentTime= static_cast<quint64>(QDateTime::currentMSecsSinceEpoch());
    quint64 flytime = currentTime-_lastTakeoffTime;

    uint32_t min = flytime/(1000*60);
    uint32_t sec = flytime/1000 - min*60;
    QTime time(0,min,sec);
    ui->label_Fly_Time->setText(time.toString("mm:ss"));
}

void MainWindow::_armedChange(uint32_t armed)
{
  ui->label_Armed->setText(QString("%1").arg((armed==1)? QStringLiteral("Armed"):QStringLiteral("Disarmed")));
  _armed = armed;
}

void MainWindow::_batteryChange(int8_t battery_remaining)
{
    ui->progressBar_Battery->setValue(battery_remaining);

    QString battery =QString::number(battery_remaining)+"%";
    if(battery_remaining<=battery_lowbound)
    {
        QPalette palette;
        palette.setColor(QPalette::WindowText,Qt::red);

        if (!_lowBatteryAnnounceTimer.isValid() || _lowBatteryAnnounceTimer.elapsed() > 5 * 1000) { // 5s, amount of time in between each low battery announcement
            _lowBatteryAnnounceTimer.restart();
        }
        //_audio->say(tr("电量过低"));
        ui->label_Message->setText(tr("警告! 电量不足, 请立即返航！"));
    }
    ui->label_Battery_Volt->setText(battery);
}

void MainWindow::_attitudeChange(mavlink_attitude_t* attitude)
{
    //qDebug()<<"mainwindow: attitude";

    _attitude_indicator->rollLP = attitude->roll;
    _attitude_indicator->pitchLP = attitude->pitch;
    _attitude_indicator->yaw = attitude->yaw;

    QString attitude_text;
    attitude_text = QString::number(attitude->roll*180.0/M_PI,'f',1)+",";
    attitude_text +=QString::number(attitude->pitch*180.0/M_PI,'f',1);
    attitude_text +=",";
    if((attitude->yaw*180/M_PI)<0){
        attitude_text +=QString::number((attitude->yaw*180.0/M_PI + 360),'f',1);
    }
    else{
        attitude_text +=QString::number(attitude->yaw*180.0/M_PI ,'f',1);
    }    
    ui->label_Attitude->setText(attitude_text);
}

void MainWindow::_GPSStatusChange(mavlink_gps_raw_int_t* gps_raw_int)
{
    //qDebug()<<"GPS satellites visible: "<<gps_raw_int->satellites_visible;
    uint8_t fix_type = gps_raw_int->fix_type;
    QString fix;
    switch(fix_type){
    //fix 0: lost, 1: 2D local position hold, 2: 2D localization, 3: 3D localization
    case 0:
    case 1: fix = "No Fix";         break;
    case 2:fix = "2D Fix";          break;
    case 3:fix = "3D Fix";          break;
    case 4:fix = "DGPS";          break;
    case 5:fix = "RTK";             break;
    default:                              break;
    }

    uint8_t val = gps_raw_int->satellites_visible;

    ui->label_GPS_Fix->setText(QString::number(val));
    ui->progressBar_GPS->setValue(val);
}

void MainWindow::_globalPositionChange(mavlink_global_position_int_t *global_position_int)
{      
    Q_UNUSED(global_position_int)
    //ui->label_Rel_Alt->setText(QString::number(global_position_int->relative_alt/1000.0));
}

void MainWindow::_localPositionChange(mavlink_local_position_ned_t *local_position_t)
{
    //Q_UNUSED(local_position_t)
    //qDebug()<<"local position x y z :"<<local_position_t->x<<local_position_t->y<<local_position_t->z;


    //判断是否起飞
    if(!connectionLost) {
        if(_armed == 1)  {

            ui->label_Rel_Alt->setText(QString::number(local_position_t->z));

            _fly_velocity = qSqrt(qPow(local_position_t->vx,2)+qPow(local_position_t->vy,2)+qPow(local_position_t->vz,2));
            ui->label_Speed->setText(QString::number(_fly_velocity));

            _fly_distance = qSqrt(qPow(local_position_t->x,2)+qPow(local_position_t->y,2));
            ui->label_Distance->setText(QString::number(_fly_distance));

            /*if(fabs(local_position_t->z)>=1.0) {
                if(!bool_flying) {
                    bool_flying = true;
                    _lastTakeoffTime = static_cast<quint64>(QDateTime::currentMSecsSinceEpoch());
                }
                _showFlytime();
            }
            else {
                if(bool_flying) {
                    bool_flying = false;
                    _showFlytime();
                }
            } */
         }        
    }
}

void MainWindow::_groundSpeedChange(float fly_speed)
{
    Q_UNUSED(fly_speed)
    //ui->label_Speed->setText(QString::number(fly_speed,'g',6));
}
