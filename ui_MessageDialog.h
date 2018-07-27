/********************************************************************************
** Form generated from reading UI file 'MessageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_MessageDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_Progress;
    QProgressBar *progressBar_Load;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *MessageDialog)
    {
        if (MessageDialog->objectName().isEmpty())
            MessageDialog->setObjectName(QStringLiteral("MessageDialog"));
        MessageDialog->resize(400, 194);
        gridLayout = new QGridLayout(MessageDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(20);
        label_Progress = new QLabel(MessageDialog);
        label_Progress->setObjectName(QStringLiteral("label_Progress"));
        label_Progress->setMinimumSize(QSize(0, 30));
        label_Progress->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label_Progress->setFont(font);

        gridLayout->addWidget(label_Progress, 1, 0, 1, 1);

        progressBar_Load = new QProgressBar(MessageDialog);
        progressBar_Load->setObjectName(QStringLiteral("progressBar_Load"));
        progressBar_Load->setFont(font);
        progressBar_Load->setValue(24);

        gridLayout->addWidget(progressBar_Load, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 3);
        gridLayout->setRowStretch(2, 3);
        gridLayout->setRowStretch(3, 1);

        retranslateUi(MessageDialog);

        QMetaObject::connectSlotsByName(MessageDialog);
    } // setupUi

    void retranslateUi(QDialog *MessageDialog)
    {
        MessageDialog->setWindowTitle(QApplication::translate("MessageDialog", "Dialog", 0));
        label_Progress->setText(QApplication::translate("MessageDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MessageDialog: public Ui_MessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
