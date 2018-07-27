#include "SensorsComponent.h"
#include "PX4AutopilotPlugin.h"

SensorsComponent::SensorsComponent(PX4AutopilotPlugin *autopilot, QObject *parent)
    :VehicleComponent(autopilot,parent),
      _name("Sensors")
{

}

SensorsComponent::~SensorsComponent()
{

}

QStringList SensorsComponent::setupCompleteChangedTriggerList(void) const
{
    QStringList list;
    list<<QStringLiteral("CAL_MAG0_ID")<<QStringLiteral("CAL_GYRO0_ID")
       <<QStringLiteral("CAL_ACC0_ID");
    return list;
}

QString SensorsComponent::name(void) const
{
    return _name;
}

QString SensorsComponent::iconResource(void) const
{
    return "qmlImages/qmlImages/SensorsComponentIcon";
}

bool SensorsComponent::requiresSetup(void) const
{
    return true;
}

QStringList SensorsComponent::setupComplete(void) const
{
    QStringList incompleteComps;
    if((_autopilot->getParamFact(-1,"CAL_MAG0_ID")->rawValue().toInt() != 0) &&
            (_autopilot->getParamFact(-1,"CAL_GYRO0_ID")->rawValue().toInt() != 0)&&
            (_autopilot->getParamFact(-1,"CAL_ACC0_ID")->rawValue().toInt() != 0)) {
        return QStringList();
    }

    if((_autopilot->getParamFact(-1,"CAL_MAG0_ID")->rawValue().toFloat() == 0)) {
        incompleteComps<<"Mag";
    }
    if((_autopilot->getParamFact(-1,"CAL_GYRO0_ID")->rawValue().toFloat() == 0)) {
        incompleteComps<<"Gyro";
    }
    if((_autopilot->getParamFact(-1,"CAL_ACC0_ID")->rawValue().toFloat() == 0)) {
        incompleteComps<<"Accel";
    }
    return incompleteComps;    
}
