#include "SensorsGroupPage.h"
#include "ui_SensorsGroupPage.h"

#include <QGridLayout>
#include <QDebug>
#include <QMessageBox>

SensorsGroupPage::SensorsGroupPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SensorsGroupPage),
    _sensorsController(NULL),
    _calOrientationWidget(NULL),
    _accelCalInProgress(false),
    _magCalInProgress(false),
    _gyroCalInProgress(false),
    _magDetailCalInProgress(false),
    _calInProgress(false),
    _calDone(false),
    _sidesVisible(false),
    m_calProgress(0)
{
    ui->setupUi(this);
    _sidesList <<"down"<<"up"<< "left"<<"right"<<"front"<<"back";
    ui->label_StatusText->setText(statusTextDefault);
    _calOrientationWidget = new CalRotationWidget;
    ui->stackedWidget_Orientations->addWidget(_calOrientationWidget);

    connect(this,&SensorsGroupPage::status,_calOrientationWidget,&CalRotationWidget::_status);
    connect(this,&SensorsGroupPage::calStatusChanged,_calOrientationWidget,&CalRotationWidget::_calStatusChanged);
    //connect(this,&SensorsGroupPage::sidesVisibleChanged,_calOrientationWidget,&CalRotationWidget::_sidesVisibleChanged);
}

SensorsGroupPage::~SensorsGroupPage()
{
    delete ui;
}

void SensorsGroupPage::initSensorsController()
{    
    //qDebug()<<"SensorsGroupPage::initSensorsController";
    if(!_sensorsController) {
        _sensorsController = new SensorsComponentController;

        connect(ui->pushButton_Mag,&QPushButton::clicked,this,&SensorsGroupPage::_calibrate);
        connect(ui->pushButton_Gyro,&QPushButton::clicked,this,&SensorsGroupPage::_calibrate);
        connect(ui->pushButton_Accel,&QPushButton::clicked,this,&SensorsGroupPage::_calibrate);

        //for detail calibration
        connect(ui->pushButton_Mag_Detail,&QPushButton::clicked,this,&SensorsGroupPage::_calibrate);
        connect(ui->pushButton_Accel_Detail,&QPushButton::clicked,this,&SensorsGroupPage::_calibrate);

        //for temperature calibration
        connect(ui->pushButton_Gyro_Tmp,&QPushButton::clicked,this,&SensorsGroupPage::_calibrate);
        connect(ui->pushButton_Accel_Tmp,&QPushButton::clicked,this,&SensorsGroupPage::_calibrate);

        connect(_sensorsController,&SensorsComponentController::handleUASTextMessage,this,&SensorsGroupPage::_handleUASTextMessage);
        connect(this,&SensorsGroupPage::stopCalibration,_sensorsController,&SensorsComponentController::_stopCalibration);
        connect(this,&SensorsGroupPage::sidesVisibleChanged,_calOrientationWidget,&CalRotationWidget::_sidesVisibleChanged);
     }
}

void SensorsGroupPage::_handleUASTextMessage(QString text)
{    
    qDebug()<<"text"<<text;
    if(text.contains("progress <")) {
        QString p = text.split('<').last().split('>').first();
        bool ok = false;
        int num = p.toInt(&ok);
        if(ok) {
            ui->progressBar_CalProgress->setProperty("value",float(num));
        }
        return;
    }

    //text "[cal] calibration started: 2 accel". All calibration messages start with [cal]

    //append text to statusTextArea
    /*QString calPrefix("[cal] ");
    if(!text.startsWith(calPrefix)) {
        return;
    }
    text = text.right(text.length() - calPrefix.length());
*/
    QString calStartPrefix("start calibration: ");
    if(text.startsWith(calStartPrefix)) {

        text = text.right(text.length() - calStartPrefix.length());
        text = text.split(" ").last();

        _startVisualCalibration();

        if(text == "accel" || text == "mag" || text == "gyro" || text == "accel_detail"
                || text == "mag_detail"  || text == "accel_tmp"  || text == "gyro_tmp") {

            //All red ,"Incompleted
            m_calProgress = 0;
            _calInProgress = false;
            _calDone = false;
            _sidesVisible = 0;

            for(int i = 0; i < _sidesList.count();i++) {
                emit calStatusChanged(_sidesList.at(i),_calInProgress,_calRotate,_calDone);
            }
            emit status(calStartedText);

            if(text == "accel" || text =="accel_detail") {
                _accelCalInProgress = true;
                _sidesVisible = 63;  // 111111 == 63
            }
            /*else if (text == "accel_detail") {
                _accelCalInProgress = true;
                _sidesVisible = 63;
            }*/
            else if(text == "gyro" || text =="accel_tmp" || text =="gyro_tmp") {
                _gyroCalInProgress = true; //3 calibration mode, the same effect
                _sidesVisible = 16;//010000,'up'——Downside Visible
            }
            else if (text == "mag") {
                _magCalInProgress = true;
                _sidesVisible = 63;
            }
            else if (text == "mag_detail") {
                _magCalInProgress = true;
                _magDetailCalInProgress = true;
                _sidesVisible = 18; //010010,up & noseDownSide(front) Visible
            }
            else {
                Q_ASSERT(false);
            }
            _setVisualState(_sidesVisible);//set relevant sides visible
        }
        return;
    }

    QString coarseCalPrefix("coarse calib ");
    if(text.startsWith(coarseCalPrefix)) {
        QMessageBox::warning(this,"Calibration","coarse calibration first!",QMessageBox::Ok);
        _sidesVisible = 0;
        _setVisualState(_sidesVisible);
        return;
    }

    if(text.endsWith("orientation detected")) {
        QString side = text.section(" ",0,0);

        if(side == "down" || side == "up" || side == "left"
                || side == "right" || side == "front" || side == "back") {
            _calInProgress = true;
           if(_magCalInProgress) {
               _calRotate = true;
           }
            emit calStatusChanged(side,_calInProgress,_calRotate,_calDone);
        }

        if(_magCalInProgress || _magDetailCalInProgress) {
           emit status(magOrientationDetectedText);
        } else {
           emit status(otherOrientationDetectedText);
        }
        return;
    }

    if(text.endsWith("side done, rotate to a different side")) {
        QString side = text.section(" ",0,0);
        if(_lastSide == side) {
            return;
        }
        if(side == "down" || side == "up" || side == "left"
                || side == "right" || side == "front" || side == "back") {
            _lastSide = side;
            _calInProgress = false;
            _calRotate = false;
            _calDone = true;
            if(_magDetailCalInProgress) {
                m_calProgress +=50;
            } else {
                m_calProgress+=16;
            }

            qDebug()<<"progress: "<<m_calProgress;
            ui->progressBar_CalProgress->setProperty("value",m_calProgress);

            emit calStatusChanged(side,_calInProgress,_calRotate,_calDone);
        }
        emit status(oneSideDoneText);
        return;
    }

    if(text.startsWith("calibration success: ")) {
        text = text.split(" ").last();
        _stopCalibration(StopCalibrationSuccess,text);
        return;
    } 

    if(text.startsWith("calibration failed: ")) {
        text = text.split(" ").last();
        _stopCalibration(StopCalibrationFailed,text);
        return;
    }
}

void SensorsGroupPage::_stopCalibration(StopCalibrationCode code,QString text)
{
    emit stopCalibration();

    ui->pushButton_Accel->setEnabled(true);    
    ui->pushButton_Mag->setEnabled(true);
    ui->pushButton_Gyro->setEnabled(true);    
    ui->pushButton_Mag_Detail->setEnabled(true);
    ui->pushButton_Accel_Detail->setEnabled(true);
    ui->pushButton_Accel_Tmp->setEnabled(true);
    ui->pushButton_Gyro_Tmp->setEnabled(true);

    if(code == StopCalibrationSuccess) {
        _resetVisualState();
        m_calProgress = 100;
        ui->progressBar_CalProgress->setProperty("value",100);
    } else {
        m_calProgress = 0;
        ui->progressBar_CalProgress->setProperty("value",0);
    }

    if(code == StopCalibrationSuccess) {
        if(text == "mag") {
            emit status(tr("磁力计已校准完成."));
        }  else if(text == "gyro") {
            emit status(tr("陀螺仪已校准完成."));
        } else if(text == "accel") {
            emit status(tr("加速度计校准完成."));
        } else if(text == "mag_detail") {
            emit status(tr("磁力计细调已校准完成."));
        } else if(text == "accel_detail") {
            emit status(tr("加速度计细调已校准完成."));
        } else if(text == "gyro_tmp") {
            emit status(tr("陀螺仪温度已校准完成."));
        } else if(text == "accel_tmp") {
            emit status(tr("加速度计温度已校准完成."));
        }
        ui->label_StatusText->setText(statusTextDefault);

    } else if(code == StopCalibrationFailed) {
        ui->label_StatusText->setText(statusTextDefault);
        ui->stackedWidget_Orientations->setCurrentWidget(ui->nullWidget);
        ui->label_StatusText->setVisible(true);
        ui->label_StatusText->setStyleSheet("color: red");
        if(text == "mag") {
            ui->label_StatusText->setText(tr("磁力计校准失败."));
        }  else if(text == "accel") {
            ui->label_StatusText->setText(tr("加速度计校准失败."));
        } else if(text == "gyro") {
            ui->label_StatusText->setText(tr("陀螺仪校准失败."));
        }else if(text == "mag_detail") {
            emit status(tr("磁力计细调校准失败."));
        } else if(text == "accel_detail") {
            emit status(tr("加速度计细调校准失败."));
        } else if(text == "gyro_tmp") {
            emit status(tr("陀螺仪温度校准失败."));
        } else if(text == "accel_tmp") {
            emit status(tr("加速度计温度校准失败."));
        }

    }
    _magCalInProgress = false;
    _accelCalInProgress = false;
    _gyroCalInProgress = false;
    _magDetailCalInProgress = false;
}

void SensorsGroupPage::_startVisualCalibration()
{
    ui->pushButton_Accel->setEnabled(false);
    ui->pushButton_Mag->setEnabled(false);
    ui->pushButton_Gyro->setEnabled(false);
    ui->pushButton_Accel_Detail->setEnabled(false);
    ui->pushButton_Mag_Detail->setEnabled(false);
    ui->pushButton_Accel_Tmp->setEnabled(false);
    ui->pushButton_Gyro_Tmp->setEnabled(false);

    ui->label_StatusText->setVisible(false);
    ui->progressBar_CalProgress->setProperty("value",0);

    _resetVisualState();
}

void SensorsGroupPage::_resetVisualState()
{
    //All green ,"Completed"
    _calInProgress = false;
     _calRotate = false;
     _calDone = true;
     for(int i = 0; i < _sidesList.count();i++) {
         emit calStatusChanged(_sidesList.at(i),_calInProgress,_calRotate,_calDone);
     }
}

void SensorsGroupPage::_setVisualState(int sidesVisible)
{
    if(sidesVisible!=0) {
       ui->stackedWidget_Orientations->setCurrentWidget(_calOrientationWidget);
   }
   emit sidesVisibleChanged(sidesVisible);
}

void SensorsGroupPage::_calibrate()
{
    //qDebug()<<"SensorsGroupPage::_calibrate()";
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    QString btnName = btn->text();

    //hide all calibration area
    //ui->label_CalAreaHelpText->setVisible(false);

    if (btnName == "Mag") {
         _sensorsController->calibrateMag();
    }
    else if (btnName == "Gyro") {
        _sensorsController->calibrateGyro();
    }
    else if (btnName == "Accel") {
        _sensorsController->calibrateAccel();
    }
    else if (btnName == "Mag_Detail") {
        _sensorsController->calibrateMagDetail();
    }
    else if (btnName == "Accel_Detail") {
        _sensorsController->calibrateAccelDetail();
    }
    else if (btnName == "Gyro_Tmp") {
        _sensorsController->calibrateGyroTmp();
    }
    else if (btnName == "Accel_Tmp") {
        _sensorsController->calibrateAccelTmp();
    }
}
