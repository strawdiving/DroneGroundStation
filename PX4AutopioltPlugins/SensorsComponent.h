#ifndef SENSORSCOMPONENT_H
#define SENSORSCOMPONENT_H

#include "VehicleComponent.h"

class SensorsComponent: public VehicleComponent
{
    Q_OBJECT
public:
    SensorsComponent(PX4AutopilotPlugin* autopilot, QObject* parent = NULL);
    ~SensorsComponent();

    // Virtuals from VehicleComponent
    virtual QStringList setupCompleteChangedTriggerList(void) const;

    virtual QString name(void) const;
    virtual QString iconResource(void) const;
    virtual bool requiresSetup(void) const;
    virtual QStringList setupComplete(void) const;

private:
    QString _name;
};

#endif // SENSORSCOMPONENT_H
