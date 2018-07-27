#ifndef LOGANALYSIS_H
#define LOGANALYSIS_H

#include <QWidget>
#include <QMap>
#include <QSqlDatabase>
#include "basic_types.h"
#include "messages.h"
#include "sdfiles.h"

class LogAnalysis : public QWidget
{
    Q_OBJECT
public:
    LogAnalysis(QWidget *parent);
    void logReadAndStore();

signals:
    void openFileStatusChanged(bool opened);

private:
    bool _creatConnection();

    QSqlDatabase db;
};

#endif // LOGANALYSIS_H
