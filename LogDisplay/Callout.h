#ifndef CALLOUT_H
#define CALLOUT_H

#include <QGraphicsItem>
#include <QtCharts>
#include <QtCharts/QChartGlobal>
#include <QtWidgets/QGraphicsItem>
#include <QtGui/QFont>

using namespace QtCharts;

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Callout : public QGraphicsItem
{
public:
    Callout(QChart* chart);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setText(const QString &text);
    void setAnchor(QPointF point);
    void updateGeometry();



protected:
    QRectF boundingRect() const;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QChart* _chart;
    QString _text;

    QRectF _textRect;
    QRectF _rect;
    QPointF _anchor;
    QFont _font;
};

#endif // CALLOUT_H
