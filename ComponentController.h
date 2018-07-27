#ifndef COMPONENTCONTROLLER_H
#define COMPONENTCONTROLLER_H

#include <QObject>

#include "Fact.h"
#include "PX4AutopioltPlugins/PX4AutopilotPlugin.h"
#include "UAS.h"

class ComponentController : public QObject
{
    Q_OBJECT
public:
    explicit ComponentController(QObject *parent = 0);
    ~ComponentController();

signals:

public slots:

protected:
    Fact* getParamFact(int compId,const QString paramName);
    bool _allParamsExist(int compId,QStringList params);
    UAS* _uas;
    PX4AutopilotPlugin *_autopilot;
    Vehicle* _vehicle;
};

#endif // COMPONENTCONTROLLER_H
