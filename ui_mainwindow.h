/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LogDisplay/LogWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Message_2;
    QLabel *label_Portname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_Baudrate;
    QLabel *label_Message;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLabel *label_Mode;
    QPushButton *pushButton_Connect;
    QTabWidget *tabWidget;
    QWidget *setup;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QStackedWidget *stackedWidget_Summary;
    QWidget *page;
    QWidget *page_2;
    QWidget *view;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_Gauge;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QLabel *label_7;
    QProgressBar *progressBar_RC;
    QLabel *label_RC;
    QLabel *label_20;
    QProgressBar *progressBar_GPS;
    QLabel *label_GPS_Fix;
    QLabel *label_3;
    QProgressBar *progressBar_Battery;
    QLabel *label_Battery_Volt;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_Fly_Time;
    QLabel *label_Rel_Alt;
    QLabel *label_9;
    QLabel *yawLabel;
    QLabel *label_Speed;
    QLabel *label_Distance;
    QLabel *statusLabel_2;
    QLabel *statusLabel;
    QLabel *label_Armed;
    QLabel *label_Status;
    QLabel *label_Attitude;
    QLabel *label_13;
    QWidget *log;
    QGridLayout *gridLayout_2;
    LogWidget *widget_Log;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1039, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_8 = new QGridLayout(centralWidget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Message_2 = new QLabel(centralWidget);
        label_Message_2->setObjectName(QStringLiteral("label_Message_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_Message_2->sizePolicy().hasHeightForWidth());
        label_Message_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label_Message_2->setFont(font);
        label_Message_2->setFrameShape(QFrame::Box);
        label_Message_2->setTextFormat(Qt::AutoText);
        label_Message_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_Message_2);

        label_Portname = new QLabel(centralWidget);
        label_Portname->setObjectName(QStringLiteral("label_Portname"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Portname->sizePolicy().hasHeightForWidth());
        label_Portname->setSizePolicy(sizePolicy1);
        label_Portname->setFont(font);
        label_Portname->setFrameShape(QFrame::NoFrame);
        label_Portname->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_Portname);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 3);

        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 170, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_2->setPalette(palette);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setFrameShape(QFrame::Box);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        label_Baudrate = new QLabel(centralWidget);
        label_Baudrate->setObjectName(QStringLiteral("label_Baudrate"));
        sizePolicy.setHeightForWidth(label_Baudrate->sizePolicy().hasHeightForWidth());
        label_Baudrate->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush6(QColor(0, 255, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush7(QColor(0, 212, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush7);
        QBrush brush8(QColor(0, 85, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush8);
        QBrush brush9(QColor(0, 113, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush10(QColor(127, 212, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_Baudrate->setPalette(palette1);
        label_Baudrate->setFont(font);
        label_Baudrate->setStyleSheet(QStringLiteral("border-color: rgb(0, 170, 0);"));
        label_Baudrate->setFrameShape(QFrame::NoFrame);
        label_Baudrate->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_Baudrate);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3->setStretch(0, 5);
        horizontalLayout_3->setStretch(1, 4);

        gridLayout_5->addLayout(horizontalLayout_3, 0, 2, 1, 1);

        label_Message = new QLabel(centralWidget);
        label_Message->setObjectName(QStringLiteral("label_Message"));
        label_Message->setFont(font);
        label_Message->setTextFormat(Qt::AutoText);

        gridLayout_5->addWidget(label_Message, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font);
        label_8->setFrameShape(QFrame::Box);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_8);

        label_Mode = new QLabel(centralWidget);
        label_Mode->setObjectName(QStringLiteral("label_Mode"));
        sizePolicy.setHeightForWidth(label_Mode->sizePolicy().hasHeightForWidth());
        label_Mode->setSizePolicy(sizePolicy);
        QPalette palette2;
        QBrush brush11(QColor(85, 85, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush12(QColor(120, 120, 120, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_Mode->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        label_Mode->setFont(font1);
        label_Mode->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_Mode);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        gridLayout_5->addLayout(horizontalLayout_5, 0, 1, 1, 1);

        pushButton_Connect = new QPushButton(centralWidget);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_Connect->sizePolicy().hasHeightForWidth());
        pushButton_Connect->setSizePolicy(sizePolicy2);
        pushButton_Connect->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/attitude/attitude/wifi.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Connect->setIcon(icon);
        pushButton_Connect->setIconSize(QSize(24, 24));

        gridLayout_5->addWidget(pushButton_Connect, 0, 3, 1, 1);

        gridLayout_5->setColumnStretch(0, 4);

        gridLayout_8->addLayout(gridLayout_5, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tabWidget->setPalette(palette3);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QStringLiteral("background-image: url(:/attitude/attitude/background-new.jpg);"));
        tabWidget->setIconSize(QSize(24, 24));
        tabWidget->setMovable(false);
        setup = new QWidget();
        setup->setObjectName(QStringLiteral("setup"));
        gridLayout = new QGridLayout(setup);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        stackedWidget_Summary = new QStackedWidget(setup);
        stackedWidget_Summary->setObjectName(QStringLiteral("stackedWidget_Summary"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget_Summary->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget_Summary->addWidget(page_2);

        horizontalLayout_4->addWidget(stackedWidget_Summary);

        horizontalLayout_4->setStretch(0, 6);

        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(setup, QString());
        view = new QWidget();
        view->setObjectName(QStringLiteral("view"));
        gridLayout_6 = new QGridLayout(view);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_Gauge = new QGridLayout();
        gridLayout_Gauge->setSpacing(6);
        gridLayout_Gauge->setObjectName(QStringLiteral("gridLayout_Gauge"));

        gridLayout_3->addLayout(gridLayout_Gauge, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(view);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        groupBox->setFont(font2);
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_7, 0, 0, 1, 1);

        progressBar_RC = new QProgressBar(groupBox);
        progressBar_RC->setObjectName(QStringLiteral("progressBar_RC"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        progressBar_RC->setPalette(palette4);
        progressBar_RC->setFont(font);
        progressBar_RC->setMaximum(100);
        progressBar_RC->setValue(0);
        progressBar_RC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(progressBar_RC, 0, 1, 1, 1);

        label_RC = new QLabel(groupBox);
        label_RC->setObjectName(QStringLiteral("label_RC"));

        gridLayout_7->addWidget(label_RC, 0, 2, 1, 1);

        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_20, 1, 0, 1, 1);

        progressBar_GPS = new QProgressBar(groupBox);
        progressBar_GPS->setObjectName(QStringLiteral("progressBar_GPS"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        progressBar_GPS->setPalette(palette5);
        progressBar_GPS->setFont(font);
        progressBar_GPS->setMaximum(16);
        progressBar_GPS->setValue(0);
        progressBar_GPS->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(progressBar_GPS, 1, 1, 1, 1);

        label_GPS_Fix = new QLabel(groupBox);
        label_GPS_Fix->setObjectName(QStringLiteral("label_GPS_Fix"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_GPS_Fix->setPalette(palette6);
        label_GPS_Fix->setFont(font1);

        gridLayout_7->addWidget(label_GPS_Fix, 1, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_3, 2, 0, 1, 1);

        progressBar_Battery = new QProgressBar(groupBox);
        progressBar_Battery->setObjectName(QStringLiteral("progressBar_Battery"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        progressBar_Battery->setPalette(palette7);
        progressBar_Battery->setFont(font);
        progressBar_Battery->setMinimum(0);
        progressBar_Battery->setMaximum(100);
        progressBar_Battery->setValue(0);
        progressBar_Battery->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(progressBar_Battery, 2, 1, 1, 1);

        label_Battery_Volt = new QLabel(groupBox);
        label_Battery_Volt->setObjectName(QStringLiteral("label_Battery_Volt"));
        QPalette palette8;
        QBrush brush13(QColor(205, 205, 205, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush13);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush13);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush13);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush13);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_Battery_Volt->setPalette(palette8);
        label_Battery_Volt->setFont(font1);
        label_Battery_Volt->setStyleSheet(QStringLiteral("color: rgb(205, 205, 205);"));

        gridLayout_7->addWidget(label_Battery_Volt, 2, 2, 1, 1);

        gridLayout_7->setColumnStretch(0, 2);
        gridLayout_7->setColumnStretch(1, 2);
        gridLayout_7->setColumnStretch(2, 1);

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(view);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font2);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("border-color: rgb(0, 170, 0);"));
        label_6->setFrameShape(QFrame::NoFrame);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("border-color: rgb(0, 170, 0);"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_5, 0, 1, 1, 1);

        label_Fly_Time = new QLabel(groupBox_2);
        label_Fly_Time->setObjectName(QStringLiteral("label_Fly_Time"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_Fly_Time->setPalette(palette9);
        label_Fly_Time->setFont(font1);
        label_Fly_Time->setFrameShape(QFrame::NoFrame);
        label_Fly_Time->setFrameShadow(QFrame::Raised);
        label_Fly_Time->setTextFormat(Qt::AutoText);
        label_Fly_Time->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Fly_Time, 1, 0, 1, 1);

        label_Rel_Alt = new QLabel(groupBox_2);
        label_Rel_Alt->setObjectName(QStringLiteral("label_Rel_Alt"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_Rel_Alt->setPalette(palette10);
        label_Rel_Alt->setFont(font1);
        label_Rel_Alt->setFrameShape(QFrame::NoFrame);
        label_Rel_Alt->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Rel_Alt, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("border-color: rgb(0, 170, 0);"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        yawLabel = new QLabel(groupBox_2);
        yawLabel->setObjectName(QStringLiteral("yawLabel"));
        yawLabel->setFont(font);
        yawLabel->setStyleSheet(QStringLiteral("border-color: rgb(0, 170, 0);"));
        yawLabel->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(yawLabel, 2, 1, 1, 1);

        label_Speed = new QLabel(groupBox_2);
        label_Speed->setObjectName(QStringLiteral("label_Speed"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_Speed->setPalette(palette11);
        label_Speed->setFont(font1);
        label_Speed->setFrameShape(QFrame::NoFrame);
        label_Speed->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Speed, 3, 0, 1, 1);

        label_Distance = new QLabel(groupBox_2);
        label_Distance->setObjectName(QStringLiteral("label_Distance"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_Distance->setPalette(palette12);
        label_Distance->setFont(font1);
        label_Distance->setFrameShape(QFrame::NoFrame);
        label_Distance->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Distance, 3, 1, 1, 1);

        statusLabel_2 = new QLabel(groupBox_2);
        statusLabel_2->setObjectName(QStringLiteral("statusLabel_2"));
        statusLabel_2->setFont(font);
        statusLabel_2->setStyleSheet(QStringLiteral("border-color: rgb(0, 170, 0);"));
        statusLabel_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(statusLabel_2, 4, 0, 1, 1);

        statusLabel = new QLabel(groupBox_2);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setFont(font);
        statusLabel->setStyleSheet(QStringLiteral("border-color: rgb(0, 170, 0);"));
        statusLabel->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(statusLabel, 4, 1, 1, 1);

        label_Armed = new QLabel(groupBox_2);
        label_Armed->setObjectName(QStringLiteral("label_Armed"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_Armed->setPalette(palette13);
        label_Armed->setFont(font1);
        label_Armed->setFrameShape(QFrame::NoFrame);
        label_Armed->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Armed, 5, 0, 1, 1);

        label_Status = new QLabel(groupBox_2);
        label_Status->setObjectName(QStringLiteral("label_Status"));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_Status->setPalette(palette14);
        label_Status->setFont(font1);
        label_Status->setFrameShape(QFrame::NoFrame);
        label_Status->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Status, 5, 1, 1, 1);

        label_Attitude = new QLabel(groupBox_2);
        label_Attitude->setObjectName(QStringLiteral("label_Attitude"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_Attitude->sizePolicy().hasHeightForWidth());
        label_Attitude->setSizePolicy(sizePolicy3);
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_Attitude->setPalette(palette15);
        label_Attitude->setFont(font1);
        label_Attitude->setFrameShape(QFrame::NoFrame);
        label_Attitude->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Attitude, 7, 0, 1, 2);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        label_13->setFont(font3);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_13, 6, 0, 1, 2);


        verticalLayout->addWidget(groupBox_2);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 3);
        gridLayout_3->setColumnStretch(1, 1);

        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(view, QString());
        log = new QWidget();
        log->setObjectName(QStringLiteral("log"));
        gridLayout_2 = new QGridLayout(log);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget_Log = new LogWidget(log);
        widget_Log->setObjectName(QStringLiteral("widget_Log"));

        gridLayout_2->addWidget(widget_Log, 0, 0, 1, 1);

        tabWidget->addTab(log, QString());

        gridLayout_8->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1039, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_Message_2->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243:", Q_NULLPTR));
        label_Portname->setText(QApplication::translate("MainWindow", "Pixhawk on COM3", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", Q_NULLPTR));
        label_Baudrate->setText(QApplication::translate("MainWindow", "57600", Q_NULLPTR));
        label_Message->setText(QApplication::translate("MainWindow", "  \346\234\252\350\277\236\346\216\245", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\351\243\236\350\241\214\346\250\241\345\274\217", Q_NULLPTR));
        label_Mode->setText(QApplication::translate("MainWindow", "Unknown", Q_NULLPTR));
        pushButton_Connect->setText(QApplication::translate("MainWindow", "  \350\277\236\346\216\245", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(setup), QApplication::translate("MainWindow", "\351\243\236\345\211\215\350\256\276\347\275\256", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\256\211\345\205\250\344\277\241\346\201\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\351\201\245\346\216\247\344\277\241\345\217\267", Q_NULLPTR));
        label_RC->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "GPS\344\277\241\345\217\267", Q_NULLPTR));
        label_GPS_Fix->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\347\224\265\351\207\217", Q_NULLPTR));
        label_Battery_Volt->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\351\243\236\350\241\214\347\212\266\346\200\201", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\351\243\236\350\241\214\346\227\266\351\227\264\357\274\210min\357\274\211", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\351\243\236\350\241\214\351\253\230\345\272\246\357\274\210m\357\274\211", Q_NULLPTR));
        label_Fly_Time->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_Rel_Alt->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\351\243\236\350\241\214\351\200\237\345\272\246\357\274\210m/s\357\274\211", Q_NULLPTR));
        yawLabel->setText(QApplication::translate("MainWindow", "\351\243\236\350\241\214\350\267\235\347\246\273\357\274\210m\357\274\211", Q_NULLPTR));
        label_Speed->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_Distance->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        statusLabel_2->setText(QApplication::translate("MainWindow", "Arm\347\212\266\346\200\201", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("MainWindow", "\351\243\236\350\241\214\347\212\266\346\200\201", Q_NULLPTR));
        label_Armed->setText(QString());
        label_Status->setText(QString());
        label_Attitude->setText(QApplication::translate("MainWindow", "0.0\357\274\2140.0\357\274\2140.0", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\345\247\277\346\200\201\357\274\210R,P,Y\357\274\211", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(view), QApplication::translate("MainWindow", "\351\243\236\350\241\214\347\233\221\346\216\247", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(log), QApplication::translate("MainWindow", "log\345\210\206\346\236\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
