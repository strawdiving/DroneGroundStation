#include "LogWidget.h"
#include "ui_LogWidget.h"

#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QVXYModelMapper>

#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

using namespace QtCharts;

LogWidget::LogWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWidget),
    _chartView(NULL),
    model(NULL),
    _tooltip(0),
    _coordX(0),
    _coordY(0),
    _chart(NULL)
{
    ui->setupUi(this);
    _init();
}

void LogWidget::_init()
{
    ui->treeWidget->setStyleSheet("QTreeWidget::item:selected {"
                               "                  border: 1px solid #567dbc;"
                               "                 background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6ea1f1, stop: 1 #567dbc);}");

    ui->treeWidget->setEnabled(false);
    connect(ui->treeWidget,&QTreeWidget::itemClicked,this,&LogWidget::plotData);

    _logAnalysis = new LogAnalysis(this);
    connect(_logAnalysis,&LogAnalysis::openFileStatusChanged,this,&LogWidget::_openFileStatusChanged);
}

LogWidget::~LogWidget()
{
    delete ui;
}

void LogWidget::on_pushButton_OpenLogFile_clicked()
{
    ui->treeWidget->setEnabled(false);
    _clear();
    _logAnalysis->logReadAndStore();
    //ui->treeWidget->setEnabled(true);
}

void LogWidget::_openFileStatusChanged(bool opened)
{
    //qDebug()<<"_openFileStatusChanged "<<opened;
    if(opened) {
        ui->pushButton_Clear->setEnabled(true);
        ui->treeWidget->setEnabled(true);
    }
}

void LogWidget::plotData(QTreeWidgetItem* item, int column)
{
    //qDebug()<<"LogWidget:plotData";
    if(item ==NULL) {
        return;
    }

    QStringList filePath;

    if(!_item2FilepathMap.contains(item)) {

        QTreeWidgetItem* itemFile = item;

        //get full path of item
        while(itemFile != NULL) {
            filePath<<itemFile->text(column);
            itemFile = itemFile->parent();
        }
        if(!filePath.isEmpty()) {
           _item2FilepathMap.insert(item,filePath);
        }
    }

     if(ui->treeWidget->selectedItems().count() > 2) {
         item->setSelected(false);
         //QMessageBox::warning(this,"Parameter Selection","You can only select less than 2 params",QMessageBox::Ok);
         return;
     }

     QList<QTreeWidgetItem*> selectedItems = ui->treeWidget->selectedItems();
     QStringList columns;
     if(!selectedItems.isEmpty()) {
         ui->tableView->setVisible(true);
         ui->scrollArea_LogDisplay->setVisible(true);

         for(int i = 0;i<selectedItems.count();i++) {
             QTreeWidgetItem* item = selectedItems.at(i);
             filePath = _item2FilepathMap.value(item);

            if(!filePath.isEmpty()) {
            QString cellName;
            QString tableName = filePath.last();
            if(filePath.size()>=2) {
                 for(int i = filePath.size() - 2; i>=0; i--) {
                     cellName += filePath.at(i);
                     if(i!=0) {
                          cellName +=  '_';
                     }
                 }
            }
            else {
                cellName = tableName;
            }
            //qDebug()<<"tablename"<<tableName<<"cellname"<<cellName;
            columns<<tableName<<cellName;
            }
         }

             model = new QSqlQueryModel(ui->tableView);
             QSqlQuery query;
             QString queryString;

             //more than 1 parameter to display
             if(columns.count()>2) {
                 //2 params have the same timestamp
                 if(columns.at(0) == columns.at(2)) {
                     queryString = QString("select %1.timestamp,%1.%2,%1.timestamp,%1.%3 from %1").arg(columns.at(0)).arg(columns.at(1)).arg(columns.at(3));
                 }
                 //2 params have different timestamps
                 else {
                     queryString = QString("select %1.timestamp,%1.%2,%3.timestamp,%3.%4 from %1,%3").arg(columns.at(0)).arg(columns.at(1)).arg(columns.at(2)).arg(columns.at(3));
                 }
             }
             else {
                 queryString = QString("select %1.timestamp,%1.%2 from %1").arg(columns.at(0)).arg(columns.at(1));
             }
            query.exec(queryString);

             model->setQuery(queryString);
             ui->tableView->setModel(model);

             _chart = new QChart();
             _chart->setTitle("Log Data");
             _chart->setAnimationOptions(QChart::AllAnimations);
             _chart->setAcceptHoverEvents(true);

             //series1
             QLineSeries * series = new QLineSeries();
             series->setName(columns.at(1));

             QVXYModelMapper* mapper = new QVXYModelMapper(this);
             mapper->setXColumn(0);
             mapper->setYColumn(1);
             mapper->setSeries(series);
             mapper->setModel(model);
             _chart->addSeries(series);
             //connect(series,SIGNAL(hovered(QPointF,bool)),this,SLOT(tooltip(QPointF,bool)));

             //series2
             if(columns.count() > 2) {
                 series = new QLineSeries();
                 series->setName(columns.at(3));

                 mapper = new QVXYModelMapper(this);
                 mapper->setXColumn(2);
                 mapper->setYColumn(3);
                 mapper->setSeries(series);
                 mapper->setModel(model);
                 _chart->addSeries(series);
                 //connect(series,SIGNAL(hovered(QPointF,bool)),this,SLOT(tooltip(QPointF,bool)));
             }


             _chart->createDefaultAxes();
             _chart->setAcceptHoverEvents(true);

             _coordX = new QGraphicsSimpleTextItem("X: ",_chart);
             _coordX->setPos(_chart->size().width()/2 - 50, _chart->size().height());

             _chartView = new chartView(_chart,this);

             ui->scrollArea_LogDisplay->setWidget(_chartView);
        }
     else {
         //qDebug()<<"No item selected";
         _chartView = NULL;
         ui->scrollArea_LogDisplay->setVisible(false);
         ui->tableView->setVisible(false);
     }
}

void LogWidget::tooltip(QPointF point, bool state)
{
    qDebug()<<point<<state;
    if (_tooltip == 0) {
       //qDebug()<<"_tooltip == 0";
        _tooltip = new Callout(_chart);
    }

    if (state) {
        _tooltip->setText(QString("X: %1 \nY: %2 ").arg(point.x()).arg(point.y()));
        _tooltip->setAnchor(point);
        _tooltip->setZValue(11);
        _tooltip->updateGeometry();
        _tooltip->show();

    } else {
       _tooltip->hide();
    }
}

void LogWidget::on_pushButton_Clear_clicked()
{
    ui->treeWidget->clearSelection();
    _clear();
}

void LogWidget::_clear()
{

    if(model) {
        model->clear();
        if(_chart) {
            _chart->removeAllSeries();
        }
        ui->tableView->setModel(model);
    }
}


