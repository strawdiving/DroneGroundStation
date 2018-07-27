#ifndef SETUPWIDGET_H
#define SETUPWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QListWidget>
#include <QPushButton>

#include "FactMetaData.h"
#include "PX4ParameterMetaData.h"

class SensorsGroupPage;
class SummaryViewPage;
class Vehicle;
class ComponentController;
class MessagePanel;
class ParamPage;

namespace Ui {
class SetupWidget;
}

class SetupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetupWidget(QWidget *parent = 0);
    ~SetupWidget();

signals:
     void showMessage(const QString text);

public slots:
     void _activeVehicleChanged(Vehicle* vehicle);

private slots:
     void _showPanel();
     void _showCompPanel(QString compName);
     void _parametersReadyChanged(bool parametersReady);

private:
     void _showComponentPanel(QString name);

      Ui::SetupWidget *ui;
      Vehicle* _vehicle;

      SensorsGroupPage* _sensorsPage;
      SummaryViewPage* _summaryPage;
      ParamPage* _paramPage;

      MessagePanel*  _messagePanel;
      QPushButton* _selectedBtn;

      const QString _disconnectedVehicleText = QString(tr("连接飞机，地面站将会自动检测到飞机 "));
};

#endif // SETUPWIDGET_H
