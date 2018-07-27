/********************************************************************************
** Form generated from reading UI file 'SummaryViewPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMMARYVIEWPAGE_H
#define UI_SUMMARYVIEWPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SummaryViewPage
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_helpText;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SummaryViewPage)
    {
        if (SummaryViewPage->objectName().isEmpty())
            SummaryViewPage->setObjectName(QStringLiteral("SummaryViewPage"));
        SummaryViewPage->resize(687, 570);
        gridLayout = new QGridLayout(SummaryViewPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(10);
        label = new QLabel(SummaryViewPage);
        label->setObjectName(QStringLiteral("label"));
        label->setBaseSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_helpText = new QLabel(SummaryViewPage);
        label_helpText->setObjectName(QStringLiteral("label_helpText"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_helpText->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label_helpText->setFont(font1);
        label_helpText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_helpText->setWordWrap(true);

        gridLayout_2->addWidget(label_helpText, 1, 0, 1, 1);

        listWidget = new QListWidget(SummaryViewPage);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMouseTracking(true);
        listWidget->setFocusPolicy(Qt::ClickFocus);
        listWidget->setViewMode(QListView::IconMode);

        gridLayout_2->addWidget(listWidget, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 9);
        gridLayout_2->setRowStretch(3, 1);

        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(SummaryViewPage);

        QMetaObject::connectSlotsByName(SummaryViewPage);
    } // setupUi

    void retranslateUi(QWidget *SummaryViewPage)
    {
        SummaryViewPage->setWindowTitle(QApplication::translate("SummaryViewPage", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SummaryViewPage", "Vehicle Summary", Q_NULLPTR));
        label_helpText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SummaryViewPage: public Ui_SummaryViewPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMMARYVIEWPAGE_H
