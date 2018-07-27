#include "OrientationWidget.h"
#include <QDebug>
#include <QVBoxLayout>

struct Name2Resorce {
    const char* name;
    bool rotate;
    const char* imageResource;
};

static const struct Name2Resorce name2Resource[] = {
{"Down",              false,      ":/qmlImages/qmlImages/Vehicle2UpsideDown.png"},
{"Up",                   false,      ":/qmlImages/qmlImages/Vehicle1Down.png"},
{"Left",                 false,      ":/qmlImages/qmlImages/Vehicle3Left.png"},
{"Right",               false,      ":/qmlImages/qmlImages/Vehicle4Right.png"},
{"NoseDown",     false,      ":/qmlImages/qmlImages/Vehicle6TailDown.png"},
{"TailDown",        false,      ":/qmlImages/qmlImages/Vehicle5NoseDown.png"},
/*
{"Down",              false,      ":/qmlImages/qmlImages/VehicleUpsideDownRotate.png"},
{"Up", false,      ":/qmlImages/qmlImages/VehicleDownRotate.png"},
{"Left",                 false,      ":/qmlImages/qmlImages/VehicleLeftRotate.png"},
{"Right",              false,      ":/qmlImages/qmlImages/VehicleRightRotate.png"},
{"NoseDown",    false,      ":/qmlImages/qmlImages/VehicleTailDownRotate.png"},
{"TailDown",        false,      ":/qmlImages/qmlImages/VehicleNoseDownRotate.png"},
*/
{"Down",              true,      ":/qmlImages/qmlImages/VehicleUpsideDownRotate.png"},
{"Up",                  true,      ":/qmlImages/qmlImages/VehicleDownRotate.png"},
{"Left",                 true,      ":/qmlImages/qmlImages/VehicleLeftRotate.png"},
{"Right",               true,      ":/qmlImages/qmlImages/VehicleRightRotate.png"},
{"NoseDown",     true,      ":/qmlImages/qmlImages/VehicleTailDownRotate.png"},
{"TailDown",        true,      ":/qmlImages/qmlImages/VehicleNoseDownRotate.png"},
};

OrientationWidget::OrientationWidget(QString name)
    : _name(name)
{
    _image = new QLabel;
    _image->setFixedSize(200,160);
    _statusText = new QLabel("尚未完成");
    _statusText->setAlignment(Qt::AlignHCenter);
    _statusText->setFixedWidth(_image->width());

    for(int i = 0; i < sizeof(name2Resource)/sizeof(name2Resource[0]); i++ ) {
        if(_name == name2Resource[i].name && name2Resource[i].rotate == false) {
            QPixmap pix(name2Resource[i].imageResource);
            pix = pix.scaled(_image->size());
            _image->setPixmap(pix);
        }
    }

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(_image,5);
    vLayout->addWidget(_statusText,1);

    this->setLayout(vLayout);
    this->setStyleSheet("border:3px solid red;color:red");
}

OrientationWidget::~OrientationWidget()
{

}

void OrientationWidget::_statusChanged(bool inProgress, bool rotate, bool done)
{
    //qDebug()<<"name,inProgress,rotate,done"<<_name<< inProgress<<rotate<<done;
    if(inProgress) {
        this->setStyleSheet("border:3px solid yellow");
        for(int i = 0; i < sizeof(name2Resource)/sizeof(name2Resource[0]); i++ ) {
            if(_name == name2Resource[i].name && rotate == name2Resource[i].rotate) {
                QPixmap pix(name2Resource[i].imageResource);
                pix = pix.scaled(_image->size());
                _image->setPixmap(pix);
                if(rotate) {
                    _statusText->setText("旋转");
                } else {
                    _statusText->setText("保持不动");
                    //_statusText->setText("旋转");
                }
                break;
            }
        }
    }  else {
        if(done) {
            this->setStyleSheet("border:3px solid #27c927;color:green");
            for(int i = 0; i < sizeof(name2Resource)/sizeof(name2Resource[0]); i++ ) {
                if(_name == name2Resource[i].name && rotate == name2Resource[i].rotate) {
                    QPixmap pix(name2Resource[i].imageResource);
                    pix = pix.scaled(_image->size());
                    _image->setPixmap(pix);
                    _statusText->setText("完成");
                    break;
                }
            }
        } else {
            this->setStyleSheet("border:3px solid red; color:red");
            _statusText->setText("尚未完成");
        }
    }
}

void OrientationWidget::_calVisibleChanged(void)
{

}
