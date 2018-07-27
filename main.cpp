
#include "mainwindow.h"
#include "QuadApplication.h"
#include "Toolbox.h"
#include "linkmanager.h"
#include <QTextStream>
#include <QMutex>
#include <QFile>
#include <stdio.h>
#include <stdlib.h>

QMutex mutex;

void logMsgOutput(QtMsgType type,const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(context)

    mutex.lock();
    QString text;
    switch(type) {
    case QtDebugMsg:
        text =QString("Debug");
        break;
    case QtWarningMsg:
        text = QString("Warning");
        break;
    case QtCriticalMsg:
        text = QString("Critical");
        break;
    case QtFatalMsg:
        text = QString("Fatal");
    }
//QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
/*QString message = QString("  %1 : File: %2  Line: %3  Function: %4  %5").arg(text).arg(QString(context.file)).arg(QString::number(context.line))
        .arg(QString(context.function)).arg(msg);*/
QString message = QString("  %1 : %2").arg(text).arg(msg);

QFile file("log.txt");
if(file.open(QIODevice::WriteOnly|QIODevice::Append)) {
    QTextStream text(&file);
   // text<<currentDateTime;
    text<<message<<"\r\n";
    file.flush();
    file.close();
}
mutex.unlock();
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(logMsgOutput);
    QuadApplication *a = new QuadApplication(argc, argv);

    Q_CHECK_PTR(a);
    int exitcode = 0;
    {
        if(!a->_initForNormalAppBoot()) {
            return -1;
        }
        exitcode = a->exec();
    }
    delete a;

    qDebug() << "After app delete";
    return exitcode;
}
