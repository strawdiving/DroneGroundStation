#ifndef PIDPARAMSET_H
#define PIDPARAMSET_H

#include <QWidget>
#include <QMap>

namespace Ui {
class PIDParamSet;
}

class PIDParamSet : public QWidget
{
    Q_OBJECT

public:
    PIDParamSet(QString name);
    ~PIDParamSet();
    QString name() {return _name;}
    void paramConfirmed(float P,float rate_P,float rate_I,float rate_D);

signals:
    void paramChanged(QString moduleName,QMap<QString,float> paramValue);

private slots:
    void on_pushButton_Apply_clicked();
    void on_pushButton_Reset_clicked();

private:
    void _storeSettings();
    void _loadSettings();

    void _storeInitSettings();

    Ui::PIDParamSet *ui;
    QString _name;

    QMap<QString,float> _paramName2Value;
};

#endif // PIDPARAMSET_H
