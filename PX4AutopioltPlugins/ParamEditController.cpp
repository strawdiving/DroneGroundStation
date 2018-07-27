#include "ParamEditController.h"
#include "linkmanager.h"

ParamEditController::ParamEditController()
{
    connect(_vehicle,&Vehicle::PIDSetConfirm,this,&ParamEditController::_PIDSetConfirm);
}

ParamEditController::~ParamEditController()
{

}

void ParamEditController::_paramChanged(QString moduleName,QMap<QString,float> paramValue)
{
    _uas->writePIDParams(moduleName,paramValue);
}

void ParamEditController::_PIDSetConfirm(mavlink_pid_set_confirm_t pid_set_confirm)
{
     //qDebug()<<"ParamEditController::_PIDSetConfirm";
     emit PIDSetConfirm(pid_set_confirm);
}
