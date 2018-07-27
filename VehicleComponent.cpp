#include "VehicleComponent.h"
#include "PX4AutopioltPlugins/PX4AutopilotPlugin.h"

VehicleComponent::VehicleComponent(PX4AutopilotPlugin* autopilot, QObject *parent)
    : QObject(parent),
      _autopilot(autopilot)
{

}

VehicleComponent::~VehicleComponent()
{

}

/*bool VehicleComponent::allowSetupWhileArmed(void) const
{
    return false;
}
*/

QStringList VehicleComponent::setupCompleteChangedTriggerList(void) const
{
   return QStringList();
}

void VehicleComponent::setupTriggerSignals(void)
{
    foreach (const QString paramName, setupCompleteChangedTriggerList()) {
        if (_autopilot->paramExists(-1,paramName)) {
            Fact* paramFact = _autopilot->getParamFact(-1,paramName);
            connect(paramFact,&Fact::valueChanged, this, &VehicleComponent::_triggerUpdated);
        }
    }
}

void VehicleComponent::_triggerUpdated(QVariant value)
{
    QStringList incompleteComponents = setupComplete();
    qDebug()<<" Incomplete setup components:  "<<incompleteComponents;
    //emit setupCompleteChanged(setupComplete());
}
