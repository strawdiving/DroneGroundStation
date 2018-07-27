/********************************************************************************
** Form generated from reading UI file 'ParamPage.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMPAGE_H
#define UI_PARAMPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParamPage
{
public:
    QGridLayout *gridLayout_14;
    QLabel *label_10;
    QGridLayout *gridLayout_13;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_10;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *label_20;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_Pitch_P;
    QDoubleSpinBox *doubleSpinBox_Pitch_RP;
    QDoubleSpinBox *doubleSpinBox_Pitch_RI;
    QDoubleSpinBox *doubleSpinBox_Pitch_RD;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_8;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_Roll_P;
    QDoubleSpinBox *doubleSpinBox_Roll_RP;
    QDoubleSpinBox *doubleSpinBox_Roll_RI;
    QDoubleSpinBox *doubleSpinBox_Roll_RD;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_12;
    QLabel *label_25;
    QLabel *label_24;
    QLabel *label_23;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_Yaw_P;
    QDoubleSpinBox *doubleSpinBox_Yaw_RP;
    QDoubleSpinBox *doubleSpinBox_Yaw_RI;
    QDoubleSpinBox *doubleSpinBox_Yaw_RD;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_X_P;
    QDoubleSpinBox *doubleSpinBox_X_RP;
    QDoubleSpinBox *doubleSpinBox_X_RI;
    QDoubleSpinBox *doubleSpinBox_X_RD;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_Y_P;
    QDoubleSpinBox *doubleSpinBox_Y_RP;
    QDoubleSpinBox *doubleSpinBox_Y_RI;
    QDoubleSpinBox *doubleSpinBox_Y_RD;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_Z_P;
    QDoubleSpinBox *doubleSpinBox_Z_RP;
    QDoubleSpinBox *doubleSpinBox_Z_RI;
    QDoubleSpinBox *doubleSpinBox_Z_RD;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Reset;

    void setupUi(QWidget *ParamPage)
    {
        if (ParamPage->objectName().isEmpty())
            ParamPage->setObjectName(QStringLiteral("ParamPage"));
        ParamPage->resize(702, 472);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        ParamPage->setFont(font);
        gridLayout_14 = new QGridLayout(ParamPage);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label_10 = new QLabel(ParamPage);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 30));
        label_10->setMaximumSize(QSize(16777215, 30));
        label_10->setFont(font);

        gridLayout_14->addWidget(label_10, 0, 0, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_5 = new QGroupBox(ParamPage);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setFont(font);
        gridLayout_9 = new QGridLayout(groupBox_5);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        gridLayout_10->addWidget(label_19, 4, 0, 1, 1);

        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);

        gridLayout_10->addWidget(label_18, 0, 0, 1, 1);

        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        gridLayout_10->addWidget(label_20, 5, 0, 1, 1);

        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);

        gridLayout_10->addWidget(label_21, 2, 0, 1, 1);

        doubleSpinBox_Pitch_P = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_Pitch_P->setObjectName(QStringLiteral("doubleSpinBox_Pitch_P"));
        doubleSpinBox_Pitch_P->setDecimals(1);
        doubleSpinBox_Pitch_P->setMaximum(8);
        doubleSpinBox_Pitch_P->setSingleStep(0.1);
        doubleSpinBox_Pitch_P->setValue(4);

        gridLayout_10->addWidget(doubleSpinBox_Pitch_P, 0, 1, 1, 1);

        doubleSpinBox_Pitch_RP = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_Pitch_RP->setObjectName(QStringLiteral("doubleSpinBox_Pitch_RP"));
        doubleSpinBox_Pitch_RP->setMaximum(0.5);
        doubleSpinBox_Pitch_RP->setSingleStep(0.01);
        doubleSpinBox_Pitch_RP->setValue(0.15);

        gridLayout_10->addWidget(doubleSpinBox_Pitch_RP, 2, 1, 1, 1);

        doubleSpinBox_Pitch_RI = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_Pitch_RI->setObjectName(QStringLiteral("doubleSpinBox_Pitch_RI"));
        doubleSpinBox_Pitch_RI->setMaximum(0.1);
        doubleSpinBox_Pitch_RI->setSingleStep(0.01);

        gridLayout_10->addWidget(doubleSpinBox_Pitch_RI, 4, 1, 1, 1);

        doubleSpinBox_Pitch_RD = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_Pitch_RD->setObjectName(QStringLiteral("doubleSpinBox_Pitch_RD"));
        doubleSpinBox_Pitch_RD->setDecimals(3);
        doubleSpinBox_Pitch_RD->setMaximum(0.1);
        doubleSpinBox_Pitch_RD->setSingleStep(0.01);

        gridLayout_10->addWidget(doubleSpinBox_Pitch_RD, 5, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_10, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_5);

        groupBox_4 = new QGroupBox(ParamPage);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font);
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        gridLayout_8->addWidget(label_15, 4, 0, 1, 1);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        gridLayout_8->addWidget(label_14, 1, 0, 1, 1);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        gridLayout_8->addWidget(label_16, 5, 0, 1, 1);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);

        gridLayout_8->addWidget(label_17, 2, 0, 1, 1);

        doubleSpinBox_Roll_P = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_Roll_P->setObjectName(QStringLiteral("doubleSpinBox_Roll_P"));
        doubleSpinBox_Roll_P->setDecimals(1);
        doubleSpinBox_Roll_P->setMaximum(8);
        doubleSpinBox_Roll_P->setSingleStep(0.1);
        doubleSpinBox_Roll_P->setValue(4);

        gridLayout_8->addWidget(doubleSpinBox_Roll_P, 1, 1, 1, 1);

        doubleSpinBox_Roll_RP = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_Roll_RP->setObjectName(QStringLiteral("doubleSpinBox_Roll_RP"));
        doubleSpinBox_Roll_RP->setMaximum(0.5);
        doubleSpinBox_Roll_RP->setSingleStep(0.01);
        doubleSpinBox_Roll_RP->setValue(0.15);

        gridLayout_8->addWidget(doubleSpinBox_Roll_RP, 2, 1, 1, 1);

        doubleSpinBox_Roll_RI = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_Roll_RI->setObjectName(QStringLiteral("doubleSpinBox_Roll_RI"));
        doubleSpinBox_Roll_RI->setMaximum(0.1);
        doubleSpinBox_Roll_RI->setSingleStep(0.01);

        gridLayout_8->addWidget(doubleSpinBox_Roll_RI, 4, 1, 1, 1);

        doubleSpinBox_Roll_RD = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_Roll_RD->setObjectName(QStringLiteral("doubleSpinBox_Roll_RD"));
        doubleSpinBox_Roll_RD->setDecimals(3);
        doubleSpinBox_Roll_RD->setMaximum(0.1);
        doubleSpinBox_Roll_RD->setSingleStep(0.001);

        gridLayout_8->addWidget(doubleSpinBox_Roll_RD, 5, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_8, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_4);

        groupBox_6 = new QGroupBox(ParamPage);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setFont(font);
        gridLayout_11 = new QGridLayout(groupBox_6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        label_25 = new QLabel(groupBox_6);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font);

        gridLayout_12->addWidget(label_25, 1, 0, 1, 1);

        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);

        gridLayout_12->addWidget(label_24, 4, 0, 1, 1);

        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font);

        gridLayout_12->addWidget(label_23, 3, 0, 1, 1);

        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font);

        gridLayout_12->addWidget(label_22, 0, 0, 1, 1);

        doubleSpinBox_Yaw_P = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_Yaw_P->setObjectName(QStringLiteral("doubleSpinBox_Yaw_P"));
        doubleSpinBox_Yaw_P->setDecimals(1);
        doubleSpinBox_Yaw_P->setMaximum(7);
        doubleSpinBox_Yaw_P->setSingleStep(0.1);
        doubleSpinBox_Yaw_P->setValue(3.5);

        gridLayout_12->addWidget(doubleSpinBox_Yaw_P, 0, 1, 1, 1);

        doubleSpinBox_Yaw_RP = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_Yaw_RP->setObjectName(QStringLiteral("doubleSpinBox_Yaw_RP"));
        doubleSpinBox_Yaw_RP->setMaximum(1);
        doubleSpinBox_Yaw_RP->setSingleStep(0.01);
        doubleSpinBox_Yaw_RP->setValue(0.08);

        gridLayout_12->addWidget(doubleSpinBox_Yaw_RP, 1, 1, 1, 1);

        doubleSpinBox_Yaw_RI = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_Yaw_RI->setObjectName(QStringLiteral("doubleSpinBox_Yaw_RI"));
        doubleSpinBox_Yaw_RI->setMaximum(0.1);
        doubleSpinBox_Yaw_RI->setSingleStep(0.01);

        gridLayout_12->addWidget(doubleSpinBox_Yaw_RI, 3, 1, 1, 1);

        doubleSpinBox_Yaw_RD = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_Yaw_RD->setObjectName(QStringLiteral("doubleSpinBox_Yaw_RD"));
        doubleSpinBox_Yaw_RD->setDecimals(3);
        doubleSpinBox_Yaw_RD->setMaximum(0.01);
        doubleSpinBox_Yaw_RD->setSingleStep(0.001);

        gridLayout_12->addWidget(doubleSpinBox_Yaw_RD, 4, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_12, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_6);


        gridLayout_13->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(ParamPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        doubleSpinBox_X_P = new QDoubleSpinBox(groupBox);
        doubleSpinBox_X_P->setObjectName(QStringLiteral("doubleSpinBox_X_P"));
        doubleSpinBox_X_P->setDecimals(1);
        doubleSpinBox_X_P->setMaximum(2);
        doubleSpinBox_X_P->setSingleStep(0.1);
        doubleSpinBox_X_P->setValue(1);

        gridLayout->addWidget(doubleSpinBox_X_P, 0, 1, 1, 1);

        doubleSpinBox_X_RP = new QDoubleSpinBox(groupBox);
        doubleSpinBox_X_RP->setObjectName(QStringLiteral("doubleSpinBox_X_RP"));
        doubleSpinBox_X_RP->setDecimals(1);
        doubleSpinBox_X_RP->setMaximum(8);
        doubleSpinBox_X_RP->setSingleStep(0.1);
        doubleSpinBox_X_RP->setValue(4);

        gridLayout->addWidget(doubleSpinBox_X_RP, 1, 1, 1, 1);

        doubleSpinBox_X_RI = new QDoubleSpinBox(groupBox);
        doubleSpinBox_X_RI->setObjectName(QStringLiteral("doubleSpinBox_X_RI"));
        doubleSpinBox_X_RI->setMaximum(0.5);
        doubleSpinBox_X_RI->setSingleStep(0.01);

        gridLayout->addWidget(doubleSpinBox_X_RI, 3, 1, 1, 1);

        doubleSpinBox_X_RD = new QDoubleSpinBox(groupBox);
        doubleSpinBox_X_RD->setObjectName(QStringLiteral("doubleSpinBox_X_RD"));
        doubleSpinBox_X_RD->setMaximum(0.2);
        doubleSpinBox_X_RD->setSingleStep(0.01);

        gridLayout->addWidget(doubleSpinBox_X_RD, 4, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ParamPage);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        doubleSpinBox_Y_P = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_Y_P->setObjectName(QStringLiteral("doubleSpinBox_Y_P"));
        doubleSpinBox_Y_P->setDecimals(1);
        doubleSpinBox_Y_P->setMaximum(2);
        doubleSpinBox_Y_P->setSingleStep(0.1);
        doubleSpinBox_Y_P->setValue(1);

        gridLayout_2->addWidget(doubleSpinBox_Y_P, 0, 1, 1, 1);

        doubleSpinBox_Y_RP = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_Y_RP->setObjectName(QStringLiteral("doubleSpinBox_Y_RP"));
        doubleSpinBox_Y_RP->setDecimals(1);
        doubleSpinBox_Y_RP->setMaximum(8);
        doubleSpinBox_Y_RP->setSingleStep(0.1);
        doubleSpinBox_Y_RP->setValue(4);

        gridLayout_2->addWidget(doubleSpinBox_Y_RP, 1, 1, 1, 1);

        doubleSpinBox_Y_RI = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_Y_RI->setObjectName(QStringLiteral("doubleSpinBox_Y_RI"));
        doubleSpinBox_Y_RI->setMaximum(0.5);
        doubleSpinBox_Y_RI->setSingleStep(0.01);

        gridLayout_2->addWidget(doubleSpinBox_Y_RI, 3, 1, 1, 1);

        doubleSpinBox_Y_RD = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_Y_RD->setObjectName(QStringLiteral("doubleSpinBox_Y_RD"));
        doubleSpinBox_Y_RD->setMaximum(0.2);
        doubleSpinBox_Y_RD->setSingleStep(0.01);

        gridLayout_2->addWidget(doubleSpinBox_Y_RD, 4, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(ParamPage);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout_3->addWidget(label_8, 3, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        gridLayout_3->addWidget(label_9, 4, 0, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        doubleSpinBox_Z_P = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_Z_P->setObjectName(QStringLiteral("doubleSpinBox_Z_P"));
        doubleSpinBox_Z_P->setDecimals(1);
        doubleSpinBox_Z_P->setMaximum(4);
        doubleSpinBox_Z_P->setSingleStep(0.1);
        doubleSpinBox_Z_P->setValue(2);

        gridLayout_3->addWidget(doubleSpinBox_Z_P, 0, 1, 1, 1);

        doubleSpinBox_Z_RP = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_Z_RP->setObjectName(QStringLiteral("doubleSpinBox_Z_RP"));
        doubleSpinBox_Z_RP->setDecimals(1);
        doubleSpinBox_Z_RP->setMaximum(5);
        doubleSpinBox_Z_RP->setSingleStep(0.1);
        doubleSpinBox_Z_RP->setValue(2.5);

        gridLayout_3->addWidget(doubleSpinBox_Z_RP, 1, 1, 1, 1);

        doubleSpinBox_Z_RI = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_Z_RI->setObjectName(QStringLiteral("doubleSpinBox_Z_RI"));
        doubleSpinBox_Z_RI->setMaximum(1);
        doubleSpinBox_Z_RI->setSingleStep(0.01);
        doubleSpinBox_Z_RI->setValue(0.2);

        gridLayout_3->addWidget(doubleSpinBox_Z_RI, 3, 1, 1, 1);

        doubleSpinBox_Z_RD = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_Z_RD->setObjectName(QStringLiteral("doubleSpinBox_Z_RD"));
        doubleSpinBox_Z_RD->setMaximum(0.2);
        doubleSpinBox_Z_RD->setSingleStep(0.01);

        gridLayout_3->addWidget(doubleSpinBox_Z_RD, 4, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);


        gridLayout_13->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_13, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_Apply = new QPushButton(ParamPage);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));
        pushButton_Apply->setFont(font);

        horizontalLayout_3->addWidget(pushButton_Apply);

        pushButton_Reset = new QPushButton(ParamPage);
        pushButton_Reset->setObjectName(QStringLiteral("pushButton_Reset"));
        pushButton_Reset->setFont(font);

        horizontalLayout_3->addWidget(pushButton_Reset);


        gridLayout_14->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        retranslateUi(ParamPage);

        QMetaObject::connectSlotsByName(ParamPage);
    } // setupUi

    void retranslateUi(QWidget *ParamPage)
    {
        ParamPage->setWindowTitle(QApplication::translate("ParamPage", "Form", 0));
        label_10->setText(QApplication::translate("ParamPage", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        groupBox_5->setTitle(QApplication::translate("ParamPage", "Pitch", 0));
        label_19->setText(QApplication::translate("ParamPage", "Rate_I", 0));
        label_18->setText(QApplication::translate("ParamPage", "P", 0));
        label_20->setText(QApplication::translate("ParamPage", "Rate_D", 0));
        label_21->setText(QApplication::translate("ParamPage", "Rate_P", 0));
        groupBox_4->setTitle(QApplication::translate("ParamPage", "Roll", 0));
        label_15->setText(QApplication::translate("ParamPage", "Rate_I", 0));
        label_14->setText(QApplication::translate("ParamPage", "P", 0));
        label_16->setText(QApplication::translate("ParamPage", "Rate_D", 0));
        label_17->setText(QApplication::translate("ParamPage", "Rate_P", 0));
        groupBox_6->setTitle(QApplication::translate("ParamPage", "Yaw", 0));
        label_25->setText(QApplication::translate("ParamPage", "Rate_P", 0));
        label_24->setText(QApplication::translate("ParamPage", "Rate_D", 0));
        label_23->setText(QApplication::translate("ParamPage", "Rate_I", 0));
        label_22->setText(QApplication::translate("ParamPage", "P", 0));
        groupBox->setTitle(QApplication::translate("ParamPage", "X", 0));
        label->setText(QApplication::translate("ParamPage", "P", 0));
        label_2->setText(QApplication::translate("ParamPage", "Rate_I", 0));
        label_3->setText(QApplication::translate("ParamPage", "Rate_D", 0));
        label_11->setText(QApplication::translate("ParamPage", "Rate_P", 0));
        groupBox_2->setTitle(QApplication::translate("ParamPage", "Y", 0));
        label_4->setText(QApplication::translate("ParamPage", "P", 0));
        label_5->setText(QApplication::translate("ParamPage", "Rate_I", 0));
        label_6->setText(QApplication::translate("ParamPage", "Rate_D", 0));
        label_12->setText(QApplication::translate("ParamPage", "Rate_P", 0));
        groupBox_3->setTitle(QApplication::translate("ParamPage", "Z", 0));
        label_7->setText(QApplication::translate("ParamPage", "P", 0));
        label_8->setText(QApplication::translate("ParamPage", "Rate_I", 0));
        label_9->setText(QApplication::translate("ParamPage", "Rate_D", 0));
        label_13->setText(QApplication::translate("ParamPage", "Rate_P", 0));
        pushButton_Apply->setText(QApplication::translate("ParamPage", "Apply", 0));
        pushButton_Reset->setText(QApplication::translate("ParamPage", "Reset", 0));
    } // retranslateUi

};

namespace Ui {
    class ParamPage: public Ui_ParamPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMPAGE_H
