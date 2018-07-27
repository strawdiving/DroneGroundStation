#include "PIDParamSet.h"
#include "ui_PIDParamSet.h"
#include <QSettings>
#include <QDebug>

struct Properties {
    float defaultValue;
    float minValue;
    float maxValue;
    float increment;
    int decimal;
};

struct Type2Params {
    const char* moduleName;
    const char* paramName;
    Properties  paramProperties;
};

/*static const struct Type2Params type2Params[] = {
{"PITCH",         "P",                 {4.0,        -1.0,      8.0,      0.1,       1}},
{"PITCH",         "RateP",         {0.15,       -1.0,      0.5,      0.01,    2}},
{"PITCH",         "RateI",           {0.0,         -1.0,      0.1,      0.01,    2}},
{"PITCH",         "RateD",         {0.0,         -1.0,      0.01,    0.001,  3}},
{"ROLL",           "P",                 {4.0,        -1.0,      8.0,      0.1,        1}},
{"ROLL",           "RateP",         {0.15,       -1.0,      0.5,      0.01,     2}},
{"ROLL",           "RateI",           {0.0,         -1.0,      0.1,      0.01,     2}},
{"ROLL",           "RateD",         {0.0,         -1.0,      0.01,    0.001,   3}},
{"YAW",          "P",                 {3.5,        -1.0,      7.0,      0.1,            1}},
{"YAW",          "RateP",         {0.08,       -1.0,      1.0,      0.01,        2}},
{"YAW",          "RateI",           {0.0,         -1.0,      0.1,      0.01,        2}},
{"YAW",          "RateD",         {0.0,         -1.0,      0.01,    0.001,     3}},
{"X",              "P",                 {1.0,        -1.0,      2.0,      0.1,             1}},
{"X",              "RateP",         {4.0,       -1.0,      8.0,      0.1,               1}},
{"X",              "RateI",           {0.0,         -1.0,      0.5,      0.01,           2}},
{"X",              "RateD",         {0.0,         -1.0,      0.2,    0.01,             2}},
{"Y",              "P",                 {1.0,        -1.0,      2.0,      0.1,               1}},
{"Y",              "RateP",         {4.0,       -1.0,      8.0,      0.1,                1}},
{"Y",              "RateI",           {0.0,         -1.0,      0.5,      0.01,            2}},
{"Y",              "RateD",         {0.0,         -1.0,      0.2,    0.01,              2}},
{"Z",              "P",                 {2.0,        -1.0,      4.0,      0.1,                1}},
{"Z",              "RateP",         {2.5,        -1.0,       5.0,      0.1,               1}},
{"Z",              "RateI",           {0.2,         -1.0,      1.0,      0.01,             2}},
{"Z",              "RateD",         {0.0,         -1.0,      0.2,      0.01,             2}},
};
*/

static const struct Type2Params type2Params[] = {
{"PITCH",         "P",                 {4.0,        -1.0,      8.0,      0.1,       4}},
{"PITCH",         "RateP",         {0.15,       -1.0,      0.5,      0.01,    4}},
{"PITCH",         "RateI",           {0.0,         -1.0,      0.1,      0.01,    4}},
{"PITCH",         "RateD",         {0.0,         -1.0,      0.01,    0.001,  4}},
{"ROLL",           "P",                 {4.0,        -1.0,      8.0,      0.1,        4}},
{"ROLL",           "RateP",         {0.15,       -1.0,      0.5,      0.01,     4}},
{"ROLL",           "RateI",           {0.0,         -1.0,      0.1,      0.01,     4}},
{"ROLL",           "RateD",         {0.0,         -1.0,      0.01,    0.001,   4}},
{"YAW",          "P",                 {3.5,        -1.0,      7.0,      0.1,            4}},
{"YAW",          "RateP",         {0.08,       -1.0,      1.0,      0.01,        4}},
{"YAW",          "RateI",           {0.0,         -1.0,      0.1,      0.01,        4}},
{"YAW",          "RateD",         {0.0,         -1.0,      0.01,    0.001,     4}},
{"X",              "P",                 {1.0,        -1.0,      2.0,      0.1,             4}},
{"X",              "RateP",         {4.0,       -1.0,      8.0,      0.1,               4}},
{"X",              "RateI",           {0.0,         -1.0,      0.5,      0.01,           4}},
{"X",              "RateD",         {0.0,         -1.0,      0.2,    0.01,             4}},
{"Y",              "P",                 {1.0,        -1.0,      2.0,      0.1,               4}},
{"Y",              "RateP",         {4.0,       -1.0,      8.0,      0.1,                4}},
{"Y",              "RateI",           {0.0,         -1.0,      0.5,      0.01,            4}},
{"Y",              "RateD",         {0.0,         -1.0,      0.2,    0.01,              4}},
{"Z",              "P",                 {2.0,        -1.0,      4.0,      0.1,                4}},
{"Z",              "RateP",         {2.5,        -1.0,       5.0,      0.1,               4}},
{"Z",              "RateI",           {0.2,         -1.0,      1.0,      0.01,             4}},
{"Z",              "RateD",         {0.0,         -1.0,      0.2,      0.01,             4}},
};


PIDParamSet::PIDParamSet(QString name) :
    ui(new Ui::PIDParamSet),
    _name(name)
{
    ui->setupUi(this);   

    for(int i = 0; i < sizeof(type2Params)/sizeof(type2Params[0]); i++ ) {
        if(_name == type2Params[i].moduleName) {
            ui->groupBox->setTitle(type2Params[i].moduleName);
            QDoubleSpinBox* doubleSpinBox =  this->findChild<QDoubleSpinBox*>(type2Params[i].paramName);
            if(doubleSpinBox) {
                doubleSpinBox->setMaximum(type2Params[i].paramProperties.maxValue);
                doubleSpinBox->setMinimum(type2Params[i].paramProperties.minValue);
                doubleSpinBox->setSingleStep(type2Params[i].paramProperties.increment);
                doubleSpinBox->setDecimals(type2Params[i].paramProperties.decimal);

                //doubleSpinBox->setValue(type2Params[i].paramProperties.defaultValue);
            }
        }
    }
}

PIDParamSet::~PIDParamSet()
{
    _storeSettings();
    delete ui;
}

void PIDParamSet::paramConfirmed(float P,float rate_P,float rate_I,float rate_D)
{
    //qDebug()<<"PIDParamSet: paramConfirmed";
    if(ui->P->text().toFloat()<0 || ui->RateP->text().toFloat()<0 || ui->RateI->text().toFloat()<0 || ui->RateD->text().toFloat()<0)
    {
        ui->P->setValue(P);
        ui->RateP->setValue(rate_P);
        ui->RateI->setValue(rate_I);
        ui->RateD->setValue(rate_D);
        _storeInitSettings();
    }

    if( ui->P->text().toFloat()==P) {
        ui->P->setStyleSheet("border:3px solid #27c927;color:green");
    }
    if(ui->RateP->text().toFloat()==rate_P) {
        ui->RateP->setStyleSheet("border:3px solid #27c927;color:green");
    }
    if(ui->RateI->text().toFloat()==rate_I) {
        ui->RateI->setStyleSheet("border:3px solid #27c927;color:green");
    }
    if(ui->RateD->text().toFloat()==rate_D) {
        ui->RateD->setStyleSheet("border:3px solid #27c927;color:green");
    }
}

void PIDParamSet::on_pushButton_Apply_clicked()
{
    _paramName2Value.insert("P",ui->P->value());
    _paramName2Value.insert("RateP",ui->RateP->value());
    _paramName2Value.insert("RateI",ui->RateI->value());
    _paramName2Value.insert("RateD",ui->RateD->value());

    emit paramChanged(_name, _paramName2Value);
    _storeSettings();
}

void PIDParamSet::on_pushButton_Reset_clicked()
{
    _loadSettings();
}

 void PIDParamSet::_storeInitSettings()
 {
     QSettings settings("initPID.ini",QSettings::IniFormat);
     //qDebug()<<"QSettings position"<<settings.fileName();
     settings.beginGroup(_name);
     settings.setValue("P",QVariant(ui->P->value()));
     settings.setValue("Rate_P",QVariant(ui->RateP->value()));
     settings.setValue("Rate_I",QVariant(ui->RateI->value()));
     settings.setValue("Rate_D",QVariant(ui->RateD->value()));
     settings.endGroup();
 }

void PIDParamSet::_storeSettings()
{
    QSettings settings("PID.ini",QSettings::IniFormat);
    //qDebug()<<"QSettings position"<<settings.fileName();
    settings.beginGroup(_name);
    settings.setValue("P",QVariant(ui->P->value()));
    settings.setValue("Rate_P",QVariant(ui->RateP->value()));
    settings.setValue("Rate_I",QVariant(ui->RateI->value()));
    settings.setValue("Rate_D",QVariant(ui->RateD->value()));
    settings.endGroup();
}

void PIDParamSet::_loadSettings()
{
    QSettings settings("PID.ini",QSettings::IniFormat);
    settings.beginGroup(_name);
    ui->P->setValue(settings.value("P").toFloat());
    ui->RateP->setValue(settings.value("Rate_P").toFloat());
    ui->RateI->setValue(settings.value("Rate_I").toFloat());
    ui->RateD->setValue(settings.value("Rate_D").toFloat());
    settings.endGroup();
}
