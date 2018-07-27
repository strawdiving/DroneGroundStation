#ifndef ORIENTATIONWIDGET_H
#define ORIENTATIONWIDGET_H

#include <QWidget>
#include <QLabel>

class OrientationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OrientationWidget(QString name);
    ~OrientationWidget();
    QString name(void) {return _name;}

signals:

public slots:
    void _statusChanged(bool inProgress, bool rotate, bool done);
    void _calVisibleChanged(void);

private:
    QLabel* _image;
    QLabel* _statusText;
    QString _name;
};

#endif // ORIENTATIONWIDGET_H
