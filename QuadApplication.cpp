#include "QuadApplication.h"
#include "Toolbox.h"



#include <QDebug>

QuadApplication* QuadApplication::_app = NULL;

QuadApplication::QuadApplication(int &argc, char* argv[])
:QApplication(argc,argv)
, _toolbox(NULL)
, _mainwindow(NULL)
{

    Q_ASSERT(_app == NULL);
    _app = this;

    setApplicationName("SIASUN");
    this->setApplicationVersion("v1.2.3");

    _toolbox = new Toolbox(this);
}

QuadApplication::~QuadApplication()
{

}

bool QuadApplication::_initForNormalAppBoot(void)
{
    connect(this,&QuadApplication::lastWindowClosed,this,&QuadApplication::quit);
    MainWindow* mainWindow = MainWindow::_create();
    Q_CHECK_PTR(mainWindow);
    _mainwindow = mainWindow->instance();
    return true;
}

 void QuadApplication::showMessage(QString message)
 {
     //qDebug()<<message;
 }

QuadApplication* qgcApp()
{
    Q_ASSERT(QuadApplication::_app);
    return QuadApplication::_app;
}
