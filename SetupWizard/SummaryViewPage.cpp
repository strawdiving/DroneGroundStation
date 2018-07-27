#include "SummaryViewPage.h"
#include "ui_SummaryViewPage.h"
#include <QGridLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>

SummaryViewPage::SummaryViewPage(SetupWidget *calWidget, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SummaryViewPage)
{
    Q_UNUSED(calWidget)
    ui->setupUi(this);

    ui->label_helpText->setText(needSetupText);
    ui->listWidget->setVisible(false);
    ui->listWidget->setDragEnabled(false);

    _components.insert(":/qmlImages/qmlImages/gyro.jpg",                                                 "Gyro");
    _components.insert(":/qmlImages/qmlImages/4AHRS.png",                                          "Accel");
    _components.insert(":/qmlImages/qmlImages/compass3.jpg",                                      "Mag");
}

void SummaryViewPage::_showPanel(QModelIndex)
{
    //qDebug()<<"listwisget clicked";
    QString compName = ui->listWidget->currentIndex().data().toString();
    if(!compName.isEmpty()) {
        emit showPanel(compName);
    }
}

SummaryViewPage::~SummaryViewPage()
{
    delete ui;
}

void SummaryViewPage::_setupCompleteChange(bool setupComplete)
{
    if(setupComplete) {
       ui->label_helpText->setStyleSheet("color:black");
       ui->label_helpText->setText(setupCompleteText);
    }
}

void SummaryViewPage::_setupCompleteStatus(QStringList incomplete)
{
    _incompleteComps = incomplete;
    ui->listWidget->clear();

    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setFlow(QListView::LeftToRight);
    ui->listWidget->setSpacing(10);
    //ui->listWidget->setStyleSheet("QListWidget::item:selected{color:black; background-color: lightgreen;}");

    foreach (QString iconSource, _components.keys()) {
        QListWidgetItem* item = new QListWidgetItem(QIcon(iconSource),_components.value(iconSource));
        item->setSizeHint(QSize(160,160));
        item->setTextAlignment(Qt::AlignCenter);
        item->setFont(QFont("Microsoft Yahei",12,25));
        if(_incompleteComps.contains(_components.value(iconSource)))
        {
            item->setBackgroundColor(Qt::yellow);
            item->setTextColor(Qt::red);
        }
        else {
            item->setBackgroundColor(Qt::white);
        }
         ui->listWidget->addItem(item);
    }
    ui->listWidget->setIconSize(QSize(130,130));
    ui->listWidget->setVisible(true);
    connect(ui->listWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(_showPanel(QModelIndex)));
}
