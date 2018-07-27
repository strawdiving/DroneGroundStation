#ifndef QUADAPPLICATION_H
#define QUADAPPLICATION_H

#include <QApplication>
#include "mainwindow.h"
//class MainWindow;
class Toolbox;

class QuadApplication : public QApplication
{

public:
    QuadApplication(int &argc, char* argv[]);
    ~QuadApplication();

    static QuadApplication* _app;
    bool _initForNormalAppBoot(void);

    Toolbox* toolbox(void) { return _toolbox;}
    MainWindow* mainWindow(void) {return _mainwindow;}
    void showMessage(QString message);

private:
    Toolbox* _toolbox;
    MainWindow* _mainwindow;
};

QuadApplication* qgcApp();
#endif // QUADAPPLICATION_H
