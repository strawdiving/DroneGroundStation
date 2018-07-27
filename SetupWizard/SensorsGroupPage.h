#ifndef SENSORSGROUPPAGE_H
#define SENSORSGROUPPAGE_H

#include <QWidget>
#include "PX4AutopioltPlugins/SensorsComponentController.h"
#include "CalRotationWidget.h"

class SetupWidget;

namespace Ui {
class SensorsGroupPage;
}

class SensorsGroupPage : public QWidget
{
    Q_OBJECT

public:
    explicit SensorsGroupPage(QWidget *parent = 0);
    ~SensorsGroupPage();
    void initSensorsController();

signals:
    void stopCalibration(void);

    void calStatusChanged(QString side,bool inProgress,bool rotate,bool done);
    void sidesVisibleChanged(int sidesVisible);

    void status(QString message);

private slots:
    void _calibrate(void);
    void _handleUASTextMessage(QString text);

private:
    Ui::SensorsGroupPage *ui;

    enum StopCalibrationCode {
        StopCalibrationSuccess,
        StopCalibrationFailed,
    };
    void _resetVisualState();
    void _setVisualState(int sidesVisible);
    void _startVisualCalibration();

    void _stopCalibration(StopCalibrationCode code,QString text);

    bool _accelCalInProgress;
    bool _magCalInProgress;
    bool _gyroCalInProgress;
    bool _magDetailCalInProgress;

    const QString  statusTextDefault = QString(tr("点击上方按钮开始校准 "));

    const QString compassHelp = QString(tr("开始采集数据   \n 请按OK按钮确认,并将飞机绕各个轴旋转360直至校准完成."));
    //const QString calStartedText = QString(tr("将飞机按以下任意未完成的方向放置,并保持不动."));
    const QString calStartedText = QString(tr("将飞机按以下任意未完成的方向放置."));
    const QString otherOrientationDetectedText = QString(tr("将飞机保持在当前方向不动"));
    const QString magOrientationDetectedText = QString(tr("按图示将飞机持续转动直至校准完成"));
    const QString oneSideDoneText = QString(tr("将飞机按以下任意未完成的方向放置."));


    SensorsComponentController* _sensorsController ;
    CalRotationWidget* _calOrientationWidget;

    bool _calInProgress;
    bool _calRotate;
    bool _calDone;

    bool _allSidesDone;
    int _sidesVisible;

    QStringList _sidesList;
    QString _lastSide;

    uint8_t m_calProgress;
};
#endif // SENSORSGROUPPAGE_H
