/********************************************************************************
** Form generated from reading UI file 'SetupWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPWIDGET_H
#define UI_SETUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetupWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_Summary;
    QPushButton *pushButton_Param;
    QPushButton *pushButton_Sensors;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *SetupWidget)
    {
        if (SetupWidget->objectName().isEmpty())
            SetupWidget->setObjectName(QStringLiteral("SetupWidget"));
        SetupWidget->resize(691, 501);
        gridLayout_2 = new QGridLayout(SetupWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(SetupWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        groupBox->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_Summary = new QPushButton(groupBox);
        pushButton_Summary->setObjectName(QStringLiteral("pushButton_Summary"));
        pushButton_Summary->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(pushButton_Summary->sizePolicy().hasHeightForWidth());
        pushButton_Summary->setSizePolicy(sizePolicy);
        pushButton_Summary->setBaseSize(QSize(1, 50));
        QPalette palette;
        QBrush brush(QColor(0, 170, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_Summary->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton_Summary->setFont(font1);
        pushButton_Summary->setStyleSheet(QStringLiteral(""));
        pushButton_Summary->setAutoExclusive(true);

        gridLayout_3->addWidget(pushButton_Summary, 0, 0, 1, 1);

        pushButton_Param = new QPushButton(groupBox);
        pushButton_Param->setObjectName(QStringLiteral("pushButton_Param"));
        pushButton_Param->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_Param->sizePolicy().hasHeightForWidth());
        pushButton_Param->setSizePolicy(sizePolicy1);
        pushButton_Param->setBaseSize(QSize(0, 50));

        gridLayout_3->addWidget(pushButton_Param, 2, 0, 1, 1);

        pushButton_Sensors = new QPushButton(groupBox);
        pushButton_Sensors->setObjectName(QStringLiteral("pushButton_Sensors"));
        pushButton_Sensors->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_Sensors->sizePolicy().hasHeightForWidth());
        pushButton_Sensors->setSizePolicy(sizePolicy);
        pushButton_Sensors->setBaseSize(QSize(1, 50));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_Sensors->setPalette(palette1);
        pushButton_Sensors->setFont(font1);
        pushButton_Sensors->setAutoExclusive(true);

        gridLayout_3->addWidget(pushButton_Sensors, 1, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setRowStretch(2, 1);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(SetupWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        stackedWidget->setFont(font2);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 5);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(SetupWidget);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SetupWidget);
    } // setupUi

    void retranslateUi(QWidget *SetupWidget)
    {
        SetupWidget->setWindowTitle(QApplication::translate("SetupWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SetupWidget", "Setup", Q_NULLPTR));
        pushButton_Summary->setText(QApplication::translate("SetupWidget", "Summary", Q_NULLPTR));
        pushButton_Param->setText(QApplication::translate("SetupWidget", "Params", Q_NULLPTR));
        pushButton_Sensors->setText(QApplication::translate("SetupWidget", "Sensors", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetupWidget: public Ui_SetupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPWIDGET_H
