/********************************************************************************
** Form generated from reading UI file 'SensorsGroupPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORSGROUPPAGE_H
#define UI_SENSORSGROUPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SensorsGroupPage
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget_Orientations;
    QWidget *nullWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *pushButton_Gyro;
    QPushButton *pushButton_Accel;
    QPushButton *pushButton_Mag;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_Mag_Detail;
    QPushButton *pushButton_Accel_Detail;
    QPushButton *pushButton_Gyro_Tmp;
    QPushButton *pushButton_Accel_Tmp;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QProgressBar *progressBar_CalProgress;
    QLabel *label_StatusText;

    void setupUi(QWidget *SensorsGroupPage)
    {
        if (SensorsGroupPage->objectName().isEmpty())
            SensorsGroupPage->setObjectName(QStringLiteral("SensorsGroupPage"));
        SensorsGroupPage->resize(707, 512);
        gridLayout = new QGridLayout(SensorsGroupPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(10);
        stackedWidget_Orientations = new QStackedWidget(SensorsGroupPage);
        stackedWidget_Orientations->setObjectName(QStringLiteral("stackedWidget_Orientations"));
        nullWidget = new QWidget();
        nullWidget->setObjectName(QStringLiteral("nullWidget"));
        stackedWidget_Orientations->addWidget(nullWidget);

        gridLayout->addWidget(stackedWidget_Orientations, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(SensorsGroupPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        pushButton_Gyro = new QPushButton(SensorsGroupPage);
        pushButton_Gyro->setObjectName(QStringLiteral("pushButton_Gyro"));
        pushButton_Gyro->setFont(font);

        horizontalLayout->addWidget(pushButton_Gyro);

        pushButton_Accel = new QPushButton(SensorsGroupPage);
        pushButton_Accel->setObjectName(QStringLiteral("pushButton_Accel"));
        pushButton_Accel->setFont(font);

        horizontalLayout->addWidget(pushButton_Accel);

        pushButton_Mag = new QPushButton(SensorsGroupPage);
        pushButton_Mag->setObjectName(QStringLiteral("pushButton_Mag"));
        pushButton_Mag->setFont(font);

        horizontalLayout->addWidget(pushButton_Mag);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_Mag_Detail = new QPushButton(SensorsGroupPage);
        pushButton_Mag_Detail->setObjectName(QStringLiteral("pushButton_Mag_Detail"));
        pushButton_Mag_Detail->setFont(font);

        horizontalLayout->addWidget(pushButton_Mag_Detail);

        pushButton_Accel_Detail = new QPushButton(SensorsGroupPage);
        pushButton_Accel_Detail->setObjectName(QStringLiteral("pushButton_Accel_Detail"));
        pushButton_Accel_Detail->setFont(font);

        horizontalLayout->addWidget(pushButton_Accel_Detail);

        pushButton_Gyro_Tmp = new QPushButton(SensorsGroupPage);
        pushButton_Gyro_Tmp->setObjectName(QStringLiteral("pushButton_Gyro_Tmp"));
        pushButton_Gyro_Tmp->setFont(font);

        horizontalLayout->addWidget(pushButton_Gyro_Tmp);

        pushButton_Accel_Tmp = new QPushButton(SensorsGroupPage);
        pushButton_Accel_Tmp->setObjectName(QStringLiteral("pushButton_Accel_Tmp"));
        pushButton_Accel_Tmp->setFont(font);

        horizontalLayout->addWidget(pushButton_Accel_Tmp);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(9, 3);

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        label = new QLabel(SensorsGroupPage);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        progressBar_CalProgress = new QProgressBar(SensorsGroupPage);
        progressBar_CalProgress->setObjectName(QStringLiteral("progressBar_CalProgress"));
        progressBar_CalProgress->setFont(font);
        progressBar_CalProgress->setValue(0);

        gridLayout->addWidget(progressBar_CalProgress, 2, 0, 1, 1);

        label_StatusText = new QLabel(SensorsGroupPage);
        label_StatusText->setObjectName(QStringLiteral("label_StatusText"));
        label_StatusText->setFont(font1);
        label_StatusText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_StatusText->setWordWrap(true);

        gridLayout->addWidget(label_StatusText, 3, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);

        retranslateUi(SensorsGroupPage);

        QMetaObject::connectSlotsByName(SensorsGroupPage);
    } // setupUi

    void retranslateUi(QWidget *SensorsGroupPage)
    {
        SensorsGroupPage->setWindowTitle(QApplication::translate("SensorsGroupPage", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("SensorsGroupPage", "\346\240\241\345\207\206\357\274\232", Q_NULLPTR));
        pushButton_Gyro->setText(QApplication::translate("SensorsGroupPage", "Gyro", Q_NULLPTR));
        pushButton_Accel->setText(QApplication::translate("SensorsGroupPage", "Accel", Q_NULLPTR));
        pushButton_Mag->setText(QApplication::translate("SensorsGroupPage", "Mag", Q_NULLPTR));
        pushButton_Mag_Detail->setText(QApplication::translate("SensorsGroupPage", "Mag_Detail", Q_NULLPTR));
        pushButton_Accel_Detail->setText(QApplication::translate("SensorsGroupPage", "Accel_Detail", Q_NULLPTR));
        pushButton_Gyro_Tmp->setText(QApplication::translate("SensorsGroupPage", "Gyro_Tmp", Q_NULLPTR));
        pushButton_Accel_Tmp->setText(QApplication::translate("SensorsGroupPage", "Accel_Tmp", Q_NULLPTR));
        label->setText(QApplication::translate("SensorsGroupPage", "\344\274\240\346\204\237\345\231\250\346\240\241\345\207\206", Q_NULLPTR));
        label_StatusText->setText(QApplication::translate("SensorsGroupPage", "\351\200\211\346\213\251\344\270\212\351\235\242\347\232\204\346\214\211\351\222\256\357\274\214\345\274\200\345\247\213\346\240\241\345\207\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SensorsGroupPage: public Ui_SensorsGroupPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORSGROUPPAGE_H
