#include "ComponentController.h"

#include "QuadApplication.h"
#include "VehicleManager.h"

ComponentController::ComponentController(QObject *parent)
    : QObject(parent)
    , _vehicle(NULL)
    , _autopilot(NULL)
    , _uas(NULL)

{    
    _vehicle = qgcApp()->toolbox()->vehicleManager()->activeVehicle();

    if(_vehicle) {
        _autopilot = _vehicle->autopilotPlugin();
        _uas = _vehicle->uas();
    }
}

ComponentController::~ComponentController()
{

}

Fact* ComponentController::getParamFact(int compId,const QString paramName)
{
    if(_autopilot && _autopilot->paramExists(compId,paramName)) {
        Fact* fact = _autopilot->getParamFact(compId,paramName);
        //qDebug()<<"ComponentController: get ParamFact";
        return fact;
    }
    return NULL;
}

bool ComponentController::_allParamsExist(int compId,QStringList params)
{
    bool noFactsMissing = true;
    foreach(QString paramName,params) {
        if(_autopilot && !_autopilot->paramExists(compId,paramName)) {
            noFactsMissing = false;
            qDebug()<<QString("Parameter : %1 Missing").arg(paramName);
        }
    }
    return noFactsMissing;
}
