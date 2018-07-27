#ifndef CALROTATIONWIDGET_H
#define CALROTATIONWIDGET_H

#include <QWidget>
#include "OrientationWidget.h"

namespace Ui {
class CalRotationWidget;
}

class CalRotationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalRotationWidget(QWidget *parent = 0);
    ~CalRotationWidget();

public slots:
    void _status(QString message);
    void _calStatusChanged(QString side,bool inProgress,bool rotate,bool done);
    void _sidesVisibleChanged(int sidesVisible);

signals:
    void calVisibleChanged(void);
    void calStatusChanged(bool inProgress,bool rotate,bool done);

private:
    Ui::CalRotationWidget *ui;
    OrientationWidget* _downWidget;
    OrientationWidget* _upsideDownWidget;
    OrientationWidget* _leftWidget;
    OrientationWidget* _rightWidget;
    OrientationWidget* _noseDownWidget;
    OrientationWidget* _tailDownWidget;

    OrientationWidget* _currentWidget;
};

#endif // CALROTATIONWIDGET_H
