#ifndef PX4AUTOPILOTPLUGIN_H
#define PX4AUTOPILOTPLUGIN_H

#include "SensorsComponent.h"
#include "Fact.h"
#include "PX4ParameterMetaData.h"
//#include "Vehicle.h"

class Vehicle;

class PX4AutopilotPlugin : public QObject
{
    Q_OBJECT

public:
    PX4AutopilotPlugin(Vehicle* vehicle, QObject* parent);
    ~PX4AutopilotPlugin();

    Fact* getParamFact(int componentId, const QString& name);
    bool paramExists(int componentId,const QString& name);
    void refreshParameters(void);

    const QVariantList& vehicleComponents(void);

    static const int defaultCompId = -1;

signals:
    void setupCompleteChanged(bool setupComplete);
    void showMessage(const QString text);
    void parametersReadyChanged(bool parametersReady);

    void setupCompleteStatus(QStringList incomplete);

public slots:
    void _parametersReadyChanged(bool parametersReady);

private:
    void _recalcSetupComplete(void);

    SensorsComponent* _sensorsComponent;

    Vehicle* _vehicle;
    bool _setupComplete;

    QVariantList _vehicleComponents;
};

#endif // PX4AUTOPILOTPLUGIN_H
