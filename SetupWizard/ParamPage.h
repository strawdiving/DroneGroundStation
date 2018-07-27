#ifndef PARAMPAGE_H
#define PARAMPAGE_H

#include <QWidget>
#include "PX4AutopioltPlugins/ParamEditController.h"
#include <QMap>
#include "PIDParamSet.h"

class ParamPage : public QWidget
{
    Q_OBJECT

public:
    explicit ParamPage(QWidget *parent = 0);
    ~ParamPage();
    void initParamController(void);

signals:
    void paramChanged(QString moduleName,QMap<QString,float> paramValue);

private slots:
    void _paramChanged(QString moduleName,QMap<QString,float> paramValue);
    void _PIDSetConfirm(mavlink_pid_set_confirm_t pid_set_confirm);

private:    
    ParamEditController* _paramEditController;

    enum PID_NAME
    {
        PITCH,
        ROLL,
        YAW,
        X,
        Y,
        Z
    };

    PIDParamSet* _pitchPIDSetWgt;
    PIDParamSet* _rollPIDSetWgt;
    PIDParamSet* _yawPIDSetWgt;
    PIDParamSet* _xPIDSetWgt;
    PIDParamSet* _yPIDSetWgt;
    PIDParamSet* _zPIDSetWgt;
    QList<PIDParamSet*> _widgets;
};

#endif // PARAMPAGE_H
