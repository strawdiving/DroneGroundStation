#ifndef PARAMETERLOADER_H
#define PARAMETERLOADER_H

#include <QObject>
#include <QVariant>
#include <common/mavlink.h>
#include <QMutex>
#include <QMap>
#include <QTimer>

#include "PX4FirmwarePlugin.h"
#include "Fact.h"
#include "PX4ParameterMetaData.h"

class Vehicle;

class ParameterLoader : public QObject
{
    Q_OBJECT
public:
    explicit ParameterLoader(Vehicle *vehicle, QObject *parent = 0);
    ~ParameterLoader();

    bool paramExists(int componentId,const QString& name);
    Fact* getFact(int componentId, const QString& name);
    void refreshParameters(void);

signals:
    void paramsReady(bool noMissingParams);
    void paramLoadProgress(int currentCount,int totalCount);

private slots:
    void _valueUpdated(const QVariant& value);
    void _parameterUpdate(int componentId, QString paramName, int paramCount, int paramId, int type,QVariant value);
    void _initialParamRequestTimeout();

private:
    int _actualCompId(int componentId);
    void _refreshAllParameters();
    void _addMetaDataToDefaultComponent(void);
    void _checkInitialLoadComplete(void);

    Vehicle* _vehicle;
    PX4FirmwarePlugin *_px4FirmwarePlugin;
    PX4ParameterMetaData* _parameterMetaData;
    static Fact _defaultFact;   ///< Used to return default fact, when parameter not found

    QTimer _initialParamRequestTimer;
    QMutex _dataMutex;

    QMap<QString,QVariant> _mapParamName2Variant;

    int _defaultCompId;
    bool _compParamsComplete;
    int _currentParamCount;
    int _totalParamCount;
};

#endif // PARAMETERLOADER_H
