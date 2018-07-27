/********************************************************************************
** Form generated from reading UI file 'CalVehicleRotation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALVEHICLEROTATION_H
#define UI_CALVEHICLEROTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalVehicleRotation
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_name;
    QSpacerItem *horizontalSpacer_2;
    QLabel *image;

    void setupUi(QWidget *CalVehicleRotation)
    {
        if (CalVehicleRotation->objectName().isEmpty())
            CalVehicleRotation->setObjectName(QStringLiteral("CalVehicleRotation"));
        CalVehicleRotation->resize(200, 200);
        gridLayout = new QGridLayout(CalVehicleRotation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label_name = new QLabel(CalVehicleRotation);
        label_name->setObjectName(QStringLiteral("label_name"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_name->setFont(font);

        gridLayout->addWidget(label_name, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        image = new QLabel(CalVehicleRotation);
        image->setObjectName(QStringLiteral("image"));

        gridLayout->addWidget(image, 0, 0, 1, 3);

        gridLayout->setRowStretch(0, 4);
        gridLayout->setRowStretch(1, 1);

        retranslateUi(CalVehicleRotation);

        QMetaObject::connectSlotsByName(CalVehicleRotation);
    } // setupUi

    void retranslateUi(QWidget *CalVehicleRotation)
    {
        CalVehicleRotation->setWindowTitle(QApplication::translate("CalVehicleRotation", "Form", 0));
        label_name->setText(QApplication::translate("CalVehicleRotation", "Hold Still", 0));
        image->setText(QApplication::translate("CalVehicleRotation", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class CalVehicleRotation: public Ui_CalVehicleRotation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALVEHICLEROTATION_H
