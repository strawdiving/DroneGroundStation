/********************************************************************************
** Form generated from reading UI file 'FlightModeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTMODEWIDGET_H
#define UI_FLIGHTMODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlightModeWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_FltModeName;
    QComboBox *comboBox_Channel;
    QLabel *label_Description;

    void setupUi(QWidget *FlightModeWidget)
    {
        if (FlightModeWidget->objectName().isEmpty())
            FlightModeWidget->setObjectName(QStringLiteral("FlightModeWidget"));
        FlightModeWidget->resize(492, 85);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        FlightModeWidget->setFont(font);
        gridLayout = new QGridLayout(FlightModeWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_FltModeName = new QLabel(FlightModeWidget);
        label_FltModeName->setObjectName(QStringLiteral("label_FltModeName"));
        label_FltModeName->setMinimumSize(QSize(125, 0));
        label_FltModeName->setMaximumSize(QSize(125, 16777215));

        gridLayout->addWidget(label_FltModeName, 0, 0, 1, 1);

        comboBox_Channel = new QComboBox(FlightModeWidget);
        comboBox_Channel->setObjectName(QStringLiteral("comboBox_Channel"));

        gridLayout->addWidget(comboBox_Channel, 0, 1, 1, 1);

        label_Description = new QLabel(FlightModeWidget);
        label_Description->setObjectName(QStringLiteral("label_Description"));
        QFont font1;
        font1.setPointSize(10);
        label_Description->setFont(font1);
        label_Description->setWordWrap(true);

        gridLayout->addWidget(label_Description, 0, 2, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 8);

        retranslateUi(FlightModeWidget);

        QMetaObject::connectSlotsByName(FlightModeWidget);
    } // setupUi

    void retranslateUi(QWidget *FlightModeWidget)
    {
        FlightModeWidget->setWindowTitle(QApplication::translate("FlightModeWidget", "Form", 0));
        label_FltModeName->setText(QString());
        label_Description->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FlightModeWidget: public Ui_FlightModeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTMODEWIDGET_H
