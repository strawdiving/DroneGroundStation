#include "ParamPage.h"
#include <QSettings>
#include <QGridLayout>

ParamPage::ParamPage(QWidget *parent) :
    QWidget(parent),
    _paramEditController(NULL),
    _pitchPIDSetWgt(NULL),
    _rollPIDSetWgt(NULL),
    _yawPIDSetWgt(NULL),
    _xPIDSetWgt(NULL),
    _yPIDSetWgt(NULL),
    _zPIDSetWgt(NULL)
{
    //_storeSettings();

    _pitchPIDSetWgt = new PIDParamSet("PITCH");
    _rollPIDSetWgt = new PIDParamSet("ROLL");
    _yawPIDSetWgt = new PIDParamSet("YAW");
    _xPIDSetWgt = new PIDParamSet("X");
    _yPIDSetWgt = new PIDParamSet("Y");
    _zPIDSetWgt = new PIDParamSet("Z");

    _widgets<<_pitchPIDSetWgt<<_rollPIDSetWgt<<_yawPIDSetWgt<<_xPIDSetWgt<<_yPIDSetWgt<<_zPIDSetWgt;

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(_pitchPIDSetWgt,0,0);
    layout->addWidget(_rollPIDSetWgt,0,1);
    layout->addWidget(_yawPIDSetWgt,0,2);
    layout->addWidget(_xPIDSetWgt,1,0);
    layout->addWidget(_yPIDSetWgt,1,1);
    layout->addWidget(_zPIDSetWgt,1,2);
    this->setLayout(layout);

    connect(_pitchPIDSetWgt,&PIDParamSet::paramChanged,this,&ParamPage::_paramChanged);
    connect(_rollPIDSetWgt,&PIDParamSet::paramChanged,this,&ParamPage::_paramChanged);
    connect(_yawPIDSetWgt,&PIDParamSet::paramChanged,this,&ParamPage::_paramChanged);
    connect(_xPIDSetWgt,&PIDParamSet::paramChanged,this,&ParamPage::_paramChanged);
    connect(_yPIDSetWgt,&PIDParamSet::paramChanged,this,&ParamPage::_paramChanged);
    connect(_zPIDSetWgt,&PIDParamSet::paramChanged,this,&ParamPage::_paramChanged);
}

ParamPage::~ParamPage()
{

}

void ParamPage::initParamController(void)
{
    _paramEditController = new ParamEditController;
    connect(this,&ParamPage::paramChanged,_paramEditController,&ParamEditController::_paramChanged);
    connect(_paramEditController,&ParamEditController::PIDSetConfirm,this,&ParamPage::_PIDSetConfirm);
}

 void ParamPage::_paramChanged(QString moduleName,QMap<QString,float> paramValue)
 {
     emit paramChanged(moduleName,paramValue);
 }

 void ParamPage::_PIDSetConfirm(mavlink_pid_set_confirm_t pid_set_confirm)
 {
     //qDebug()<<"ParamPage::_PIDSetConfirm";
     QString pid_name;
     switch (pid_set_confirm.PID_NAME) {
     case PITCH:
         pid_name = "PITCH";
         break;
     case ROLL:
         pid_name = "ROLL";
         break;
     case YAW:
         pid_name = "YAW";
         break;
     case X:
         pid_name = "X";
         break;
     case Y:
         pid_name = "Y";
         break;
     case Z:
         pid_name = "Z";
         break;
     default:
         break;
     }
     foreach (PIDParamSet* widget, _widgets) {
         if(widget->name() == pid_name) {
             widget->paramConfirmed(pid_set_confirm.param_1,pid_set_confirm.param_2,
                                    pid_set_confirm.param_3,pid_set_confirm.param_4);
             //qDebug()<<"ParamPage: "<<widget->name();
         }
     }
 }
