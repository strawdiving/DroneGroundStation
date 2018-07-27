#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T09:26:30
#
#-------------------------------------------------

QT       += core \
                  gui \
                  serialport \
                  charts \
                  sql \
                  axcontainer \
                  multimedia

!MobileBuild {4
QT += \
    printsupport \
    serialport \
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Drones
TEMPLATE = app

include(./qextserialport/src/qextserialport.pri)
INCLUDEPATH +=./qextserialport/src/qextserialport

include(./MAVLinkLib.pri)
INCLUDEPATH +=./libs/mavlink/include/mavlink/v1.0

SOURCES += main.cpp\
        mainwindow.cpp \
    linkmanager.cpp \
    SerialCommunication.cpp \
    Fact.cpp \
    FactMetaData.cpp \
    ParameterLoader.cpp \
    PX4ParameterMetaData.cpp \
    VehicleComponent.cpp \
    PX4AutopioltPlugins/PX4AutopilotPlugin.cpp \
    PX4AutopioltPlugins/SensorsComponent.cpp \
    PX4FirmwarePlugin.cpp \
    Vehicle.cpp \
    PX4AutopioltPlugins/SensorsComponentController.cpp \
    QuadApplication.cpp \
    Toolbox.cpp \
    VehicleManager.cpp \
    UAS.cpp \
    ComponentController.cpp \
    SetupWizard/MessagePanel.cpp \
    SetupWidget.cpp \
    SetupWizard/SummaryViewPage.cpp \
    SetupWizard/SensorsGroupPage.cpp \
    SetupWizard/CalRotationWidget.cpp \
    SetupWizard/OrientationWidget.cpp \
    SetupWizard/ParamPage.cpp \
    PX4AutopioltPlugins/ParamEditController.cpp \
    SetupWizard/PIDParamSet.cpp \
    LogDisplay/LogAnalysis.cpp \
    LogDisplay/chartView.cpp \
    attitude_indicator.cpp \
    audio_worker.cpp \
    LogDisplay/LogWidget.cpp \
    LogDisplay/Callout.cpp


HEADERS  += mainwindow.h \
    linkmanager.h \
    SerialCommunication.h \
    Fact.h \
    FactMetaData.h \
    ParameterLoader.h \
    PX4ParameterMetaData.h \
    VehicleComponent.h \
    PX4AutopioltPlugins/PX4AutopilotPlugin.h \
    PX4AutopioltPlugins/SensorsComponent.h \
    PX4FirmwarePlugin.h \
    Vehicle.h \
    PX4AutopioltPlugins/SensorsComponentController.h \
    QuadApplication.h \
    Toolbox.h \
    VehicleManager.h \
    UAS.h \
    ComponentController.h \
    SetupWizard/MessagePanel.h \
    SetupWidget.h \
    SetupWizard/SummaryViewPage.h \
    SetupWizard/SensorsGroupPage.h \
    SetupWizard/CalRotationWidget.h \
    SetupWizard/OrientationWidget.h \
    SetupWizard/ParamPage.h \
    PX4AutopioltPlugins/ParamEditController.h \
    SetupWizard/PIDParamSet.h \
    LogDisplay/basic_types.h \
    LogDisplay/messages.h \
    LogDisplay/sdfiles.h \
    LogDisplay/LogAnalysis.h \
    LogDisplay/chartView.h \
    attitude_indicator.h \
    audio_worker.h \
    LogDisplay/LogWidget.h \
    LogDisplay/Callout.h

FORMS    += mainwindow.ui \
    SetupWidget.ui \
    SetupWizard/SummaryViewPage.ui \
    SetupWizard/SensorsGroupPage.ui \
    SetupWizard/CalRotationWidget.ui \
    SetupWizard/PIDParamSet.ui \
    LogDisplay/LogWidget.ui

UI_DIR  += E:/baseModule-05.12
RESOURCES += \
    attitude.qrc \
    qml.qrc


