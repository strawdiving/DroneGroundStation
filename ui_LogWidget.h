/********************************************************************************
** Form generated from reading UI file 'LogWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWIDGET_H
#define UI_LOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWidget
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_OpenLogFile;
    QTreeWidget *treeWidget;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea_LogDisplay;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_Clear;

    void setupUi(QWidget *LogWidget)
    {
        if (LogWidget->objectName().isEmpty())
            LogWidget->setObjectName(QStringLiteral("LogWidget"));
        LogWidget->resize(511, 397);
        LogWidget->setMouseTracking(false);
        gridLayout_2 = new QGridLayout(LogWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(10);
        pushButton_OpenLogFile = new QPushButton(LogWidget);
        pushButton_OpenLogFile->setObjectName(QStringLiteral("pushButton_OpenLogFile"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        pushButton_OpenLogFile->setFont(font);

        gridLayout_2->addWidget(pushButton_OpenLogFile, 0, 0, 1, 1);

        treeWidget = new QTreeWidget(LogWidget);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        __qtreewidgetitem->setFont(0, font1);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        QBrush brush(QColor(85, 0, 255, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(85, 0, 255, 255));
        brush1.setStyle(Qt::NoBrush);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setFlags(Qt::ItemIsEnabled);
        __qtreewidgetitem3->setBackground(0, brush);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem3);
        __qtreewidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem4->setBackground(0, brush1);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem3);
        __qtreewidgetitem5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem6->setFlags(Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem7->setFlags(Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem10->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem11 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem11->setFlags(Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem12 = new QTreeWidgetItem(__qtreewidgetitem11);
        __qtreewidgetitem12->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem13 = new QTreeWidgetItem(__qtreewidgetitem11);
        __qtreewidgetitem13->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem14 = new QTreeWidgetItem(__qtreewidgetitem11);
        __qtreewidgetitem14->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem15 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem15->setFlags(Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem16 = new QTreeWidgetItem(__qtreewidgetitem15);
        __qtreewidgetitem16->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem17 = new QTreeWidgetItem(__qtreewidgetitem15);
        __qtreewidgetitem17->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem18 = new QTreeWidgetItem(__qtreewidgetitem15);
        __qtreewidgetitem18->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem19 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem19->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem19);
        new QTreeWidgetItem(__qtreewidgetitem19);
        new QTreeWidgetItem(__qtreewidgetitem19);
        new QTreeWidgetItem(__qtreewidgetitem19);
        new QTreeWidgetItem(__qtreewidgetitem19);
        new QTreeWidgetItem(__qtreewidgetitem19);
        new QTreeWidgetItem(__qtreewidgetitem19);
        new QTreeWidgetItem(__qtreewidgetitem19);
        QTreeWidgetItem *__qtreewidgetitem20 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem20->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        new QTreeWidgetItem(__qtreewidgetitem20);
        QTreeWidgetItem *__qtreewidgetitem21 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem21->setFlags(Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem22 = new QTreeWidgetItem(__qtreewidgetitem21);
        __qtreewidgetitem22->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem22);
        new QTreeWidgetItem(__qtreewidgetitem22);
        new QTreeWidgetItem(__qtreewidgetitem22);
        QTreeWidgetItem *__qtreewidgetitem23 = new QTreeWidgetItem(__qtreewidgetitem21);
        __qtreewidgetitem23->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem23);
        new QTreeWidgetItem(__qtreewidgetitem23);
        new QTreeWidgetItem(__qtreewidgetitem23);
        QTreeWidgetItem *__qtreewidgetitem24 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem24->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem24);
        QTreeWidgetItem *__qtreewidgetitem25 = new QTreeWidgetItem(__qtreewidgetitem24);
        __qtreewidgetitem25->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem25);
        new QTreeWidgetItem(__qtreewidgetitem25);
        new QTreeWidgetItem(__qtreewidgetitem25);
        QTreeWidgetItem *__qtreewidgetitem26 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem26->setFlags(Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem27 = new QTreeWidgetItem(__qtreewidgetitem26);
        __qtreewidgetitem27->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem27);
        new QTreeWidgetItem(__qtreewidgetitem27);
        new QTreeWidgetItem(__qtreewidgetitem27);
        QTreeWidgetItem *__qtreewidgetitem28 = new QTreeWidgetItem(__qtreewidgetitem26);
        __qtreewidgetitem28->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem28);
        new QTreeWidgetItem(__qtreewidgetitem28);
        new QTreeWidgetItem(__qtreewidgetitem28);
        QTreeWidgetItem *__qtreewidgetitem29 = new QTreeWidgetItem(__qtreewidgetitem26);
        __qtreewidgetitem29->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem29);
        new QTreeWidgetItem(__qtreewidgetitem29);
        new QTreeWidgetItem(__qtreewidgetitem29);
        new QTreeWidgetItem(__qtreewidgetitem26);
        QTreeWidgetItem *__qtreewidgetitem30 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem30->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem30);
        new QTreeWidgetItem(__qtreewidgetitem30);
        QTreeWidgetItem *__qtreewidgetitem31 = new QTreeWidgetItem(__qtreewidgetitem30);
        __qtreewidgetitem31->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem31);
        new QTreeWidgetItem(__qtreewidgetitem31);
        new QTreeWidgetItem(__qtreewidgetitem31);
        QTreeWidgetItem *__qtreewidgetitem32 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem32->setFlags(Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem33 = new QTreeWidgetItem(__qtreewidgetitem32);
        __qtreewidgetitem33->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem33);
        new QTreeWidgetItem(__qtreewidgetitem33);
        new QTreeWidgetItem(__qtreewidgetitem33);
        QTreeWidgetItem *__qtreewidgetitem34 = new QTreeWidgetItem(__qtreewidgetitem32);
        __qtreewidgetitem34->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem34);
        new QTreeWidgetItem(__qtreewidgetitem34);
        new QTreeWidgetItem(__qtreewidgetitem34);
        QTreeWidgetItem *__qtreewidgetitem35 = new QTreeWidgetItem(__qtreewidgetitem32);
        __qtreewidgetitem35->setFlags(Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem35);
        new QTreeWidgetItem(__qtreewidgetitem35);
        new QTreeWidgetItem(__qtreewidgetitem35);
        QTreeWidgetItem *__qtreewidgetitem36 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem36->setFlags(Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem37 = new QTreeWidgetItem(__qtreewidgetitem36);
        __qtreewidgetitem37->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem38 = new QTreeWidgetItem(__qtreewidgetitem36);
        __qtreewidgetitem38->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setEnabled(false);
        treeWidget->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        treeWidget->setColumnCount(1);
        treeWidget->header()->setVisible(false);

        gridLayout_2->addWidget(treeWidget, 1, 0, 1, 1);

        tableView = new QTableView(LogWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(tableView, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea_LogDisplay = new QScrollArea(LogWidget);
        scrollArea_LogDisplay->setObjectName(QStringLiteral("scrollArea_LogDisplay"));
        scrollArea_LogDisplay->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        scrollArea_LogDisplay->setMouseTracking(true);
        scrollArea_LogDisplay->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 302, 338));
        scrollArea_LogDisplay->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea_LogDisplay, 0, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 1, 2, 1, 1);

        pushButton_Clear = new QPushButton(LogWidget);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setEnabled(false);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        pushButton_Clear->setFont(font2);

        gridLayout_2->addWidget(pushButton_Clear, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 2);
        gridLayout_2->setColumnStretch(1, 3);
        gridLayout_2->setColumnStretch(2, 10);

        retranslateUi(LogWidget);

        QMetaObject::connectSlotsByName(LogWidget);
    } // setupUi

    void retranslateUi(QWidget *LogWidget)
    {
        LogWidget->setWindowTitle(QApplication::translate("LogWidget", "Form", Q_NULLPTR));
        pushButton_OpenLogFile->setText(QApplication::translate("LogWidget", "\345\257\274\345\205\245Log\346\225\260\346\215\256", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("LogWidget", "Mode", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem1->setText(0, QApplication::translate("LogWidget", "FlightStatus", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem2->setText(0, QApplication::translate("LogWidget", "Baro", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("LogWidget", "altitude", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("LogWidget", "temperature", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem5->setText(0, QApplication::translate("LogWidget", "IMU", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("LogWidget", "acc", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem6->child(0);
        ___qtreewidgetitem7->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem6->child(1);
        ___qtreewidgetitem8->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem6->child(2);
        ___qtreewidgetitem9->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem10->setText(0, QApplication::translate("LogWidget", "gyro", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem10->child(0);
        ___qtreewidgetitem11->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem10->child(1);
        ___qtreewidgetitem12->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem10->child(2);
        ___qtreewidgetitem13->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem5->child(2);
        ___qtreewidgetitem14->setText(0, QApplication::translate("LogWidget", "mag", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem14->child(0);
        ___qtreewidgetitem15->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem14->child(1);
        ___qtreewidgetitem16->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem14->child(2);
        ___qtreewidgetitem17->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem18 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem18->setText(0, QApplication::translate("LogWidget", "GPS", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem18->child(0);
        ___qtreewidgetitem19->setText(0, QApplication::translate("LogWidget", "lat", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem18->child(1);
        ___qtreewidgetitem20->setText(0, QApplication::translate("LogWidget", "lon", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem21 = ___qtreewidgetitem18->child(2);
        ___qtreewidgetitem21->setText(0, QApplication::translate("LogWidget", "azm", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem22 = ___qtreewidgetitem18->child(3);
        ___qtreewidgetitem22->setText(0, QApplication::translate("LogWidget", "vel", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem23 = ___qtreewidgetitem18->child(4);
        ___qtreewidgetitem23->setText(0, QApplication::translate("LogWidget", "alt", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem24 = ___qtreewidgetitem18->child(5);
        ___qtreewidgetitem24->setText(0, QApplication::translate("LogWidget", "sat", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem25 = ___qtreewidgetitem18->child(6);
        ___qtreewidgetitem25->setText(0, QApplication::translate("LogWidget", "date", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem26 = ___qtreewidgetitem18->child(7);
        ___qtreewidgetitem26->setText(0, QApplication::translate("LogWidget", "time", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem27 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem27->setText(0, QApplication::translate("LogWidget", "RC", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem28 = ___qtreewidgetitem27->child(0);
        ___qtreewidgetitem28->setText(0, QApplication::translate("LogWidget", "ch1", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem29 = ___qtreewidgetitem27->child(1);
        ___qtreewidgetitem29->setText(0, QApplication::translate("LogWidget", "ch2", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem30 = ___qtreewidgetitem27->child(2);
        ___qtreewidgetitem30->setText(0, QApplication::translate("LogWidget", "ch3", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem31 = ___qtreewidgetitem27->child(3);
        ___qtreewidgetitem31->setText(0, QApplication::translate("LogWidget", "ch4", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem32 = ___qtreewidgetitem27->child(4);
        ___qtreewidgetitem32->setText(0, QApplication::translate("LogWidget", "ch5", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem33 = ___qtreewidgetitem27->child(5);
        ___qtreewidgetitem33->setText(0, QApplication::translate("LogWidget", "ch6", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem34 = ___qtreewidgetitem27->child(6);
        ___qtreewidgetitem34->setText(0, QApplication::translate("LogWidget", "ch7", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem35 = ___qtreewidgetitem27->child(7);
        ___qtreewidgetitem35->setText(0, QApplication::translate("LogWidget", "ch8", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem36 = ___qtreewidgetitem27->child(8);
        ___qtreewidgetitem36->setText(0, QApplication::translate("LogWidget", "ch9", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem37 = ___qtreewidgetitem27->child(9);
        ___qtreewidgetitem37->setText(0, QApplication::translate("LogWidget", "ch10", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem38 = ___qtreewidgetitem27->child(10);
        ___qtreewidgetitem38->setText(0, QApplication::translate("LogWidget", "ch11", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem39 = ___qtreewidgetitem27->child(11);
        ___qtreewidgetitem39->setText(0, QApplication::translate("LogWidget", "ch12", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem40 = ___qtreewidgetitem27->child(12);
        ___qtreewidgetitem40->setText(0, QApplication::translate("LogWidget", "ch13", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem41 = ___qtreewidgetitem27->child(13);
        ___qtreewidgetitem41->setText(0, QApplication::translate("LogWidget", "ch14", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem42 = ___qtreewidgetitem27->child(14);
        ___qtreewidgetitem42->setText(0, QApplication::translate("LogWidget", "ch15", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem43 = ___qtreewidgetitem27->child(15);
        ___qtreewidgetitem43->setText(0, QApplication::translate("LogWidget", "ch16", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem44 = treeWidget->topLevelItem(6);
        ___qtreewidgetitem44->setText(0, QApplication::translate("LogWidget", "Attitude", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem45 = ___qtreewidgetitem44->child(0);
        ___qtreewidgetitem45->setText(0, QApplication::translate("LogWidget", "rate", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem46 = ___qtreewidgetitem45->child(0);
        ___qtreewidgetitem46->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem47 = ___qtreewidgetitem45->child(1);
        ___qtreewidgetitem47->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem48 = ___qtreewidgetitem45->child(2);
        ___qtreewidgetitem48->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem49 = ___qtreewidgetitem44->child(1);
        ___qtreewidgetitem49->setText(0, QApplication::translate("LogWidget", "euler", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem50 = ___qtreewidgetitem49->child(0);
        ___qtreewidgetitem50->setText(0, QApplication::translate("LogWidget", "R", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem51 = ___qtreewidgetitem49->child(1);
        ___qtreewidgetitem51->setText(0, QApplication::translate("LogWidget", "P", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem52 = ___qtreewidgetitem49->child(2);
        ___qtreewidgetitem52->setText(0, QApplication::translate("LogWidget", "Y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem53 = treeWidget->topLevelItem(7);
        ___qtreewidgetitem53->setText(0, QApplication::translate("LogWidget", "Manual_Setpoint", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem54 = ___qtreewidgetitem53->child(0);
        ___qtreewidgetitem54->setText(0, QApplication::translate("LogWidget", "throttle", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem55 = ___qtreewidgetitem53->child(1);
        ___qtreewidgetitem55->setText(0, QApplication::translate("LogWidget", "euler", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem56 = ___qtreewidgetitem55->child(0);
        ___qtreewidgetitem56->setText(0, QApplication::translate("LogWidget", "R", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem57 = ___qtreewidgetitem55->child(1);
        ___qtreewidgetitem57->setText(0, QApplication::translate("LogWidget", "P", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem58 = ___qtreewidgetitem55->child(2);
        ___qtreewidgetitem58->setText(0, QApplication::translate("LogWidget", "Y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem59 = treeWidget->topLevelItem(8);
        ___qtreewidgetitem59->setText(0, QApplication::translate("LogWidget", "PosCtrl_Setpoint", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem60 = ___qtreewidgetitem59->child(0);
        ___qtreewidgetitem60->setText(0, QApplication::translate("LogWidget", "position_setpoint", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem61 = ___qtreewidgetitem60->child(0);
        ___qtreewidgetitem61->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem62 = ___qtreewidgetitem60->child(1);
        ___qtreewidgetitem62->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem63 = ___qtreewidgetitem60->child(2);
        ___qtreewidgetitem63->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem64 = ___qtreewidgetitem59->child(1);
        ___qtreewidgetitem64->setText(0, QApplication::translate("LogWidget", "vel_ff", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem65 = ___qtreewidgetitem64->child(0);
        ___qtreewidgetitem65->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem66 = ___qtreewidgetitem64->child(1);
        ___qtreewidgetitem66->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem67 = ___qtreewidgetitem64->child(2);
        ___qtreewidgetitem67->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem68 = ___qtreewidgetitem59->child(2);
        ___qtreewidgetitem68->setText(0, QApplication::translate("LogWidget", "acc_ff", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem69 = ___qtreewidgetitem68->child(0);
        ___qtreewidgetitem69->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem70 = ___qtreewidgetitem68->child(1);
        ___qtreewidgetitem70->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem71 = ___qtreewidgetitem68->child(2);
        ___qtreewidgetitem71->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem72 = ___qtreewidgetitem59->child(3);
        ___qtreewidgetitem72->setText(0, QApplication::translate("LogWidget", "yaw_setpoint", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem73 = treeWidget->topLevelItem(9);
        ___qtreewidgetitem73->setText(0, QApplication::translate("LogWidget", "AltCtrl_Setpoint", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem74 = ___qtreewidgetitem73->child(0);
        ___qtreewidgetitem74->setText(0, QApplication::translate("LogWidget", "pos_sp_z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem75 = ___qtreewidgetitem73->child(1);
        ___qtreewidgetitem75->setText(0, QApplication::translate("LogWidget", "vel_ff_z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem76 = ___qtreewidgetitem73->child(2);
        ___qtreewidgetitem76->setText(0, QApplication::translate("LogWidget", "euler", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem77 = ___qtreewidgetitem76->child(0);
        ___qtreewidgetitem77->setText(0, QApplication::translate("LogWidget", "R", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem78 = ___qtreewidgetitem76->child(1);
        ___qtreewidgetitem78->setText(0, QApplication::translate("LogWidget", "P", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem79 = ___qtreewidgetitem76->child(2);
        ___qtreewidgetitem79->setText(0, QApplication::translate("LogWidget", "Y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem80 = treeWidget->topLevelItem(10);
        ___qtreewidgetitem80->setText(0, QApplication::translate("LogWidget", "Position", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem81 = ___qtreewidgetitem80->child(0);
        ___qtreewidgetitem81->setText(0, QApplication::translate("LogWidget", "pos", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem82 = ___qtreewidgetitem81->child(0);
        ___qtreewidgetitem82->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem83 = ___qtreewidgetitem81->child(1);
        ___qtreewidgetitem83->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem84 = ___qtreewidgetitem81->child(2);
        ___qtreewidgetitem84->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem85 = ___qtreewidgetitem80->child(1);
        ___qtreewidgetitem85->setText(0, QApplication::translate("LogWidget", "acc", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem86 = ___qtreewidgetitem85->child(0);
        ___qtreewidgetitem86->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem87 = ___qtreewidgetitem85->child(1);
        ___qtreewidgetitem87->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem88 = ___qtreewidgetitem85->child(2);
        ___qtreewidgetitem88->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem89 = ___qtreewidgetitem80->child(2);
        ___qtreewidgetitem89->setText(0, QApplication::translate("LogWidget", "vel", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem90 = ___qtreewidgetitem89->child(0);
        ___qtreewidgetitem90->setText(0, QApplication::translate("LogWidget", "x", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem91 = ___qtreewidgetitem89->child(1);
        ___qtreewidgetitem91->setText(0, QApplication::translate("LogWidget", "y", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem92 = ___qtreewidgetitem89->child(2);
        ___qtreewidgetitem92->setText(0, QApplication::translate("LogWidget", "z", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem93 = treeWidget->topLevelItem(11);
        ___qtreewidgetitem93->setText(0, QApplication::translate("LogWidget", "Battery_Info", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem94 = ___qtreewidgetitem93->child(0);
        ___qtreewidgetitem94->setText(0, QApplication::translate("LogWidget", "voltage", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem95 = ___qtreewidgetitem93->child(1);
        ___qtreewidgetitem95->setText(0, QApplication::translate("LogWidget", "battery_remaining", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        pushButton_Clear->setText(QApplication::translate("LogWidget", "\346\270\205\351\231\244\347\273\230\345\233\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogWidget: public Ui_LogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
