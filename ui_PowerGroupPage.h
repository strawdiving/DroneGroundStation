/********************************************************************************
** Form generated from reading UI file 'PowerGroupPage.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERGROUPPAGE_H
#define UI_POWERGROUPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PowerGroupPage
{
public:
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_cells;
    QLabel *label_4;
    QLabel *label_batMax;
    QLabel *label;
    QLineEdit *lineEdit_fullPerCell;
    QLabel *label_6;
    QLabel *label_batMin;
    QLabel *label_3;
    QLineEdit *lineEdit_emptyPerCell;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *label_escText2;
    QLabel *label_escText1;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_calibrateESC;

    void setupUi(QWidget *PowerGroupPage)
    {
        if (PowerGroupPage->objectName().isEmpty())
            PowerGroupPage->setObjectName(QStringLiteral("PowerGroupPage"));
        PowerGroupPage->resize(515, 481);
        gridLayout_5 = new QGridLayout(PowerGroupPage);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_8 = new QLabel(PowerGroupPage);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setBaseSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label_8->setFont(font);

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        groupBox = new QGroupBox(PowerGroupPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        groupBox->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(15);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_cells = new QLineEdit(groupBox);
        lineEdit_cells->setObjectName(QStringLiteral("lineEdit_cells"));
        QPalette palette;
        QBrush brush(QColor(0, 85, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lineEdit_cells->setPalette(palette);
        lineEdit_cells->setFont(font1);
        lineEdit_cells->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_cells, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_batMax = new QLabel(groupBox);
        label_batMax->setObjectName(QStringLiteral("label_batMax"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label_batMax->setPalette(palette1);
        label_batMax->setFont(font1);
        label_batMax->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_batMax, 0, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit_fullPerCell = new QLineEdit(groupBox);
        lineEdit_fullPerCell->setObjectName(QStringLiteral("lineEdit_fullPerCell"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lineEdit_fullPerCell->setPalette(palette2);
        lineEdit_fullPerCell->setFont(font1);
        lineEdit_fullPerCell->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_fullPerCell, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        label_batMin = new QLabel(groupBox);
        label_batMin->setObjectName(QStringLiteral("label_batMin"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label_batMin->setPalette(palette3);
        label_batMin->setFont(font1);
        label_batMin->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_batMin, 1, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_emptyPerCell = new QLineEdit(groupBox);
        lineEdit_emptyPerCell->setObjectName(QStringLiteral("lineEdit_emptyPerCell"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lineEdit_emptyPerCell->setPalette(palette4);
        lineEdit_emptyPerCell->setFont(font1);
        lineEdit_emptyPerCell->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_emptyPerCell, 2, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnStretch(3, 1);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(PowerGroupPage);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font1);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_escText2 = new QLabel(groupBox_2);
        label_escText2->setObjectName(QStringLiteral("label_escText2"));
        label_escText2->setFont(font1);
        label_escText2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_escText2->setWordWrap(true);

        gridLayout_3->addWidget(label_escText2, 1, 0, 1, 2);

        label_escText1 = new QLabel(groupBox_2);
        label_escText1->setObjectName(QStringLiteral("label_escText1"));
        QPalette palette5;
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_escText1->setPalette(palette5);
        label_escText1->setFont(font1);
        label_escText1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_escText1->setWordWrap(true);

        gridLayout_3->addWidget(label_escText1, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 1, 1, 1);

        pushButton_calibrateESC = new QPushButton(groupBox_2);
        pushButton_calibrateESC->setObjectName(QStringLiteral("pushButton_calibrateESC"));
        pushButton_calibrateESC->setFont(font1);

        gridLayout_3->addWidget(pushButton_calibrateESC, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 2, 0, 1, 1);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setRowStretch(1, 4);
        gridLayout_5->setRowStretch(2, 4);

        retranslateUi(PowerGroupPage);

        QMetaObject::connectSlotsByName(PowerGroupPage);
    } // setupUi

    void retranslateUi(QWidget *PowerGroupPage)
    {
        PowerGroupPage->setWindowTitle(QApplication::translate("PowerGroupPage", "Form", 0));
        label_8->setText(QApplication::translate("PowerGroupPage", "\345\212\250\345\212\233\347\263\273\347\273\237\346\240\241\345\207\206", 0));
        groupBox->setTitle(QApplication::translate("PowerGroupPage", "\347\224\265\346\261\240", 0));
        label_2->setText(QApplication::translate("PowerGroupPage", "Num of Cells", 0));
        label_4->setText(QApplication::translate("PowerGroupPage", "\346\234\200\345\244\247\347\224\265\345\216\213:", 0));
        label_batMax->setText(QString());
        label->setText(QApplication::translate("PowerGroupPage", "\346\273\241\345\216\213 (per cell) ", 0));
        label_6->setText(QApplication::translate("PowerGroupPage", "\346\234\200\345\260\217\347\224\265\345\216\213: ", 0));
        label_batMin->setText(QString());
        label_3->setText(QApplication::translate("PowerGroupPage", "\344\275\216\345\216\213 (per cell) ", 0));
        groupBox_2->setTitle(QApplication::translate("PowerGroupPage", "\347\224\265\350\260\203\346\240\241\345\207\206", 0));
        label_escText2->setText(QString());
        label_escText1->setText(QString());
        pushButton_calibrateESC->setText(QApplication::translate("PowerGroupPage", "\346\240\241\345\207\206", 0));
    } // retranslateUi

};

namespace Ui {
    class PowerGroupPage: public Ui_PowerGroupPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERGROUPPAGE_H
