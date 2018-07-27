#include "SensorsComponentController.h"
#include "UAS.h"

SensorsComponentController::SensorsComponentController()
{
    connect(_uas,&UAS::textMessageReceived,this,&SensorsComponentController::_handleUASTextMessage);
}

SensorsComponentController::~SensorsComponentController()
{

}

void SensorsComponentController::calibrateGyro(void)
{
    _uas->startCalibration(UAS::CalibrationGyro);
}

void SensorsComponentController::calibrateMag(void)
{
    _uas->startCalibration(UAS::CalibrationMag);
}

void SensorsComponentController::calibrateAccel(void)
{    
    _uas->startCalibration(UAS::CalibrationAccel);
}

void SensorsComponentController::calibrateMagDetail(void)
{
    _uas->startCalibration(UAS::CalibrationMagDetail);
}

void SensorsComponentController::calibrateAccelDetail(void)
{
    _uas->startCalibration(UAS::CalibrationAccelDetail);
}

void SensorsComponentController::calibrateGyroTmp(void)
{
    _uas->startCalibration(UAS::CalibrationGyroTmp);
}

void SensorsComponentController::calibrateAccelTmp(void)
{
    _uas->startCalibration(UAS::CalibrationAccelTmp);
}

void SensorsComponentController::_handleUASTextMessage(int compId, QString text)
{
    Q_UNUSED(compId)
    emit handleUASTextMessage(text);
}

void SensorsComponentController::_stopCalibration(void)
{
    //disconnect(_uas,&UAS::textMessageReceived,this,&SensorsComponentController::_handleUASTextMessage);
    _uas->stopCalibration();
    //_autopilot->refreshParameters();
}
