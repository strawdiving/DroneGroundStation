#include "SetupWidget.h"
#include "ui_SetupWidget.h"

#include <QModelIndex>
#include <QGridLayout>
#include<QMessageBox>

#include "ComponentController.h"
#include "SetupWizard/MessagePanel.h"
#include "QuadApplication.h"
#include "VehicleManager.h"
#include "SetupWizard/SummaryViewPage.h"
#include "SetupWizard/SensorsGroupPage.h"
#include "SetupWizard/ParamPage.h"

SetupWidget::SetupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetupWidget)
  , _messagePanel(NULL)
  , _sensorsPage(NULL)
  , _paramPage(NULL)
  , _summaryPage(NULL)
  , _selectedBtn(NULL)
  , _vehicle(NULL)
{
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {background: #cfe2f3}"
                        "QPushButton:pressed {background: #6699cc}");

    _messagePanel = new MessagePanel();
    _summaryPage = new SummaryViewPage(this);

    ui->stackedWidget->addWidget(_summaryPage);
    ui->stackedWidget->addWidget(_messagePanel);
    ui->stackedWidget->setCurrentWidget(_messagePanel);

    connect(this,&SetupWidget::showMessage,_messagePanel,&MessagePanel::_showMessage);
    connect(ui->pushButton_Sensors,&QPushButton::clicked,this,&SetupWidget::_showPanel);
    connect(ui->pushButton_Param,&QPushButton::clicked,this,&SetupWidget::_showPanel);
    connect(ui->pushButton_Summary,&QPushButton::clicked,this,&SetupWidget::_showPanel);
}

SetupWidget::~SetupWidget()
{
    delete ui;
}

void SetupWidget::_activeVehicleChanged(Vehicle* vehicle)
 {
    qDebug()<<"SetupWidget::_activeVehicleChanged";
    _vehicle = vehicle;
    if(_vehicle) {
        connect(_vehicle->autopilotPlugin(),&PX4AutopilotPlugin::setupCompleteChanged,_summaryPage,&SummaryViewPage::_setupCompleteChange);
        connect(_vehicle->autopilotPlugin(),&PX4AutopilotPlugin::setupCompleteStatus,_summaryPage,&SummaryViewPage::_setupCompleteStatus);
        connect(_vehicle->autopilotPlugin(),&PX4AutopilotPlugin::showMessage,_messagePanel,&MessagePanel::_showMessage);

        connect(_vehicle->parameterLoader(),&ParameterLoader::paramLoadProgress,_messagePanel,&MessagePanel::_paramLoadProgress);
        connect(_vehicle->autopilotPlugin(),&PX4AutopilotPlugin:: parametersReadyChanged,this,&SetupWidget::_parametersReadyChanged);

        _sensorsPage = new SensorsGroupPage(this);

        _paramPage = new ParamPage(this);
        _paramPage->initParamController();

        ui->stackedWidget->addWidget(_sensorsPage);
        ui->stackedWidget->addWidget(_paramPage);
        connect(_summaryPage,&SummaryViewPage::showPanel,this,&SetupWidget::_showCompPanel);
   }
   else {
       ui->stackedWidget->setCurrentWidget(_messagePanel);
       emit showMessage(_disconnectedVehicleText);
       ui->pushButton_Param->setEnabled(false);
       ui->pushButton_Sensors->setEnabled(false);
       ui->pushButton_Summary->setEnabled(false);
       this->setStyleSheet("QPushButton {background: #cfe2f3}"
                           "QPushButton:pressed {background: #6699cc}");
   }
 }

void SetupWidget::_parametersReadyChanged(bool parametersReady)
{
    if(parametersReady) {
        ui->pushButton_Summary->setEnabled(true);
        ui->pushButton_Sensors->setEnabled(true);
        ui->pushButton_Param->setEnabled(true);
        ui->stackedWidget->setCurrentWidget(_summaryPage);
    }
}

void SetupWidget::_showCompPanel(QString compName)
{
    _showComponentPanel(compName);
}

void SetupWidget::_showPanel()
{
    //qDebug()<<"SetupWidget::_showPanel()";
    QPushButton* selectedBtn = qobject_cast<QPushButton*>(sender());
    if(!_selectedBtn) {
        _selectedBtn = selectedBtn;
        _selectedBtn->setStyleSheet("background-color:#6699cc; border-color:green");
    }
    if(_selectedBtn && _selectedBtn != selectedBtn) {
        _selectedBtn->setStyleSheet("background-color: #cfe2f3");
        _selectedBtn = selectedBtn;
        _selectedBtn->setStyleSheet("background-color:#6699cc; border-color:green");
    }

    QString btnName = _selectedBtn->text();
    if(!btnName.isEmpty()) {
        _showComponentPanel(btnName);
    }
}

void SetupWidget::_showComponentPanel(QString name)
{
    if(name == "Summary") {
        ui->stackedWidget->setCurrentWidget(_summaryPage);
        qDebug()<<"summary";
    } else if(_vehicle->autopilotPlugin()) {
        if(name == "Params") {
            //_paramPage->initParamController();
            ui->stackedWidget->setCurrentWidget(_paramPage);
        }
        else {
            _sensorsPage->initSensorsController();
            ui->stackedWidget->setCurrentWidget(_sensorsPage);
        }
    }
}
