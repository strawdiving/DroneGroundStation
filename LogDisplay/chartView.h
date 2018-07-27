#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QChartView>
//#include <QRubberBand>


using namespace QtCharts;

class chartView : public QChartView
{
    Q_OBJECT
public:
    chartView(QChart *chart, QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* event);
    void keyPressEvent(QKeyEvent *event);

};

#endif // CHARTVIEW_H
