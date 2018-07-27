#include "PX4AutopilotPlugin.h"
#include "ParameterLoader.h"
#include "Vehicle.h"

PX4AutopilotPlugin::PX4AutopilotPlugin(Vehicle* vehicle,QObject *parent)
    : QObject(parent),
      _sensorsComponent(NULL),
      _vehicle(vehicle),
      _setupComplete(false)
{

}

const QVariantList& PX4AutopilotPlugin::vehicleComponents(void)
{
    if(_vehicleComponents.count() == 0) {
        _sensorsComponent = new SensorsComponent(this);
        _sensorsComponent->setupTriggerSignals();

        _vehicleComponents.append(QVariant::fromValue((VehicleComponent*)_sensorsComponent));
    }
    return _vehicleComponents;
}

PX4AutopilotPlugin::~PX4AutopilotPlugin()
{

}

void PX4AutopilotPlugin::_parametersReadyChanged(bool parametersReady)
{
    qDebug()<<"PX4AutopilotPlugin::_parametersReadyChanged: "<<parametersReady;
    if(parametersReady) {
        _recalcSetupComplete();
        emit parametersReadyChanged(parametersReady);
    }

    if(!_setupComplete)
    {
        emit showMessage(QString("One or more vehicle components require setup prior to flight."));
    }
}

void PX4AutopilotPlugin::_recalcSetupComplete(void)
{
    QStringList incomplete;
    bool newSetupComplete = true;
    foreach (QVariant componentVariant, vehicleComponents()) {
        VehicleComponent* component = qobject_cast<VehicleComponent*>(qvariant_cast<QObject *>(componentVariant));
        Q_ASSERT(component);

        incomplete = component->setupComplete();

        if(!component->setupComplete().isEmpty()) {
            newSetupComplete = false;
            emit showMessage(QString("%1 component requires setup prior to flight.").arg(component->name()));
        }

        if(_setupComplete!=newSetupComplete) {
            _setupComplete = newSetupComplete;
            emit  setupCompleteChanged(_setupComplete);
        }
    }
    emit setupCompleteStatus(incomplete);
}

bool PX4AutopilotPlugin::paramExists(int componentId,const QString& name)
{
    return _vehicle->parameterLoader()->paramExists(componentId,name);
}

Fact* PX4AutopilotPlugin::getParamFact(int componentId, const QString& name)
{
    return _vehicle->parameterLoader()->getFact(componentId,name);
}

void PX4AutopilotPlugin::refreshParameters(void)
{
    _vehicle->parameterLoader()->refreshParameters();
}
