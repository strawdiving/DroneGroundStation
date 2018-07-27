#ifndef PARAMEDITCONTROLLER_H
#define PARAMEDITCONTROLLER_H

#include "ComponentController.h"

class ParamEditController: public ComponentController
{
    Q_OBJECT
public:
    ParamEditController();
    ~ParamEditController();

signals:
    void PIDSetConfirm(mavlink_pid_set_confirm_t pid_set_confirm);

public slots:
    void _paramChanged(QString moduleName,QMap<QString,float> paramValue);
    void _PIDSetConfirm(mavlink_pid_set_confirm_t pid_set_confirm);
};

#endif // PARAMEDITCONTROLLER_H
