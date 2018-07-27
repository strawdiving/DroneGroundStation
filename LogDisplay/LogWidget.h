#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include "LogAnalysis.h"
#include "chartView.h"
#include <QTreeWidget>
#include <QPair>
#include <QMap>
#include <QGraphicsSimpleTextItem>
#include <QSqlQueryModel>
#include "Callout.h"

namespace Ui {
class LogWidget;
}

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = 0);
    ~LogWidget();

private slots:
    void on_pushButton_OpenLogFile_clicked();
    void plotData(QTreeWidgetItem* item, int column);
   //void keepCallout();
    void tooltip(QPointF point, bool state);
    void _openFileStatusChanged(bool opened);


    void on_pushButton_Clear_clicked();

protected:
    //void mouseMoveEvent(QMouseEvent* event);

private:
    void _init();
    void _clear();
    Ui::LogWidget *ui;
    LogAnalysis* _logAnalysis;
    chartView* _chartView;
    QSqlQueryModel *model;
    QChart* _chart;
    QGraphicsSimpleTextItem *_coordX;
    QGraphicsSimpleTextItem *_coordY;
    Callout *_tooltip;

    ///key: QTreeWidgetItem
    /// value: filePath
    QMap<QTreeWidgetItem*,QStringList> _item2FilepathMap;
};

#endif // LOGWIDGET_H
