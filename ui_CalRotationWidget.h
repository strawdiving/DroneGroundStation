/********************************************************************************
** Form generated from reading UI file 'CalRotationWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALROTATIONWIDGET_H
#define UI_CALROTATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalRotationWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_CalHelpText;
    QWidget *widget_CalOrientations;

    void setupUi(QWidget *CalRotationWidget)
    {
        if (CalRotationWidget->objectName().isEmpty())
            CalRotationWidget->setObjectName(QStringLiteral("CalRotationWidget"));
        CalRotationWidget->resize(588, 501);
        gridLayout = new QGridLayout(CalRotationWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_CalHelpText = new QLabel(CalRotationWidget);
        label_CalHelpText->setObjectName(QStringLiteral("label_CalHelpText"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(label_CalHelpText->sizePolicy().hasHeightForWidth());
        label_CalHelpText->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        label_CalHelpText->setFont(font);

        gridLayout->addWidget(label_CalHelpText, 0, 0, 1, 1);

        widget_CalOrientations = new QWidget(CalRotationWidget);
        widget_CalOrientations->setObjectName(QStringLiteral("widget_CalOrientations"));
        widget_CalOrientations->setFont(font);

        gridLayout->addWidget(widget_CalOrientations, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 6);

        retranslateUi(CalRotationWidget);

        QMetaObject::connectSlotsByName(CalRotationWidget);
    } // setupUi

    void retranslateUi(QWidget *CalRotationWidget)
    {
        CalRotationWidget->setWindowTitle(QApplication::translate("CalRotationWidget", "Form", Q_NULLPTR));
        label_CalHelpText->setText(QApplication::translate("CalRotationWidget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalRotationWidget: public Ui_CalRotationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALROTATIONWIDGET_H
