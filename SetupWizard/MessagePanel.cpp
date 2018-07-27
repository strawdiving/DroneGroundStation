#include "MessagePanel.h"
#include <QGridLayout>

MessagePanel::MessagePanel(QWidget *parent):
    QWidget(parent)
{
    _messageText = new QLabel(this);
    _messageText->setFont(QFont("Arial",14));
    _messageText->setText(_disconnectedVehicleText);

    _messageText->setWordWrap(true);
    _messageText->setAlignment(Qt::AlignCenter);

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(_messageText);
    this->setLayout(layout);
}

MessagePanel::~MessagePanel()
{


}

void MessagePanel::_paramLoadProgress(int currentCount,int totalCount)
 {
    QString text;
    if(currentCount == totalCount) {
        text = QString("Parameters loaded completely");
    }
    else {
        text = QString(tr("参数加载...... %1/%2 个参数已加载完成 ")).arg(currentCount).arg(totalCount);
    }


    _messageText->setText(text);
 }

void MessagePanel::_showMessage(const QString text)
{
    _messageText->setText(text);
}
