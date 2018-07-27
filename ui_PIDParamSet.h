/********************************************************************************
** Form generated from reading UI file 'PIDParamSet.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIDPARAMSET_H
#define UI_PIDPARAMSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PIDParamSet
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_18;
    QDoubleSpinBox *P;
    QLabel *label_21;
    QDoubleSpinBox *RateP;
    QPushButton *pushButton_Apply;
    QLabel *label_19;
    QDoubleSpinBox *RateI;
    QPushButton *pushButton_Reset;
    QLabel *label_20;
    QDoubleSpinBox *RateD;

    void setupUi(QWidget *PIDParamSet)
    {
        if (PIDParamSet->objectName().isEmpty())
            PIDParamSet->setObjectName(QStringLiteral("PIDParamSet"));
        PIDParamSet->resize(400, 300);
        gridLayout_2 = new QGridLayout(PIDParamSet);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(PIDParamSet);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);

        gridLayout->addWidget(label_18, 0, 0, 1, 1);

        P = new QDoubleSpinBox(groupBox);
        P->setObjectName(QStringLiteral("P"));
        P->setMinimum(-1);
        P->setValue(-1);

        gridLayout->addWidget(P, 0, 1, 1, 1);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);

        gridLayout->addWidget(label_21, 1, 0, 1, 1);

        RateP = new QDoubleSpinBox(groupBox);
        RateP->setObjectName(QStringLiteral("RateP"));
        RateP->setMinimum(-1);
        RateP->setValue(-1);

        gridLayout->addWidget(RateP, 1, 1, 1, 1);

        pushButton_Apply = new QPushButton(groupBox);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        pushButton_Apply->setFont(font1);

        gridLayout->addWidget(pushButton_Apply, 1, 2, 1, 1);

        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        gridLayout->addWidget(label_19, 2, 0, 1, 1);

        RateI = new QDoubleSpinBox(groupBox);
        RateI->setObjectName(QStringLiteral("RateI"));
        RateI->setMinimum(-1);
        RateI->setValue(-1);

        gridLayout->addWidget(RateI, 2, 1, 1, 1);

        pushButton_Reset = new QPushButton(groupBox);
        pushButton_Reset->setObjectName(QStringLiteral("pushButton_Reset"));
        pushButton_Reset->setFont(font1);

        gridLayout->addWidget(pushButton_Reset, 2, 2, 1, 1);

        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        gridLayout->addWidget(label_20, 3, 0, 1, 1);

        RateD = new QDoubleSpinBox(groupBox);
        RateD->setObjectName(QStringLiteral("RateD"));
        RateD->setMinimum(-1);
        RateD->setValue(-1);

        gridLayout->addWidget(RateD, 3, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(PIDParamSet);

        QMetaObject::connectSlotsByName(PIDParamSet);
    } // setupUi

    void retranslateUi(QWidget *PIDParamSet)
    {
        PIDParamSet->setWindowTitle(QApplication::translate("PIDParamSet", "Form", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_18->setText(QApplication::translate("PIDParamSet", "P", Q_NULLPTR));
        label_21->setText(QApplication::translate("PIDParamSet", "Rate_P", Q_NULLPTR));
        pushButton_Apply->setText(QApplication::translate("PIDParamSet", "Apply", Q_NULLPTR));
        label_19->setText(QApplication::translate("PIDParamSet", "Rate_I", Q_NULLPTR));
        pushButton_Reset->setText(QApplication::translate("PIDParamSet", "Reset", Q_NULLPTR));
        label_20->setText(QApplication::translate("PIDParamSet", "Rate_D", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PIDParamSet: public Ui_PIDParamSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIDPARAMSET_H
