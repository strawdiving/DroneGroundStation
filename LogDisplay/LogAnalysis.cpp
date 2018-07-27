#include "LogAnalysis.h"
//#include "dataconnection.h"

#include <QFile>
#include <QFileDialog>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

LogAnalysis::LogAnalysis(QWidget *parent) :
    QWidget(parent)
{
    _creatConnection();
}

bool LogAnalysis::_creatConnection()
{    
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("LogData.db");

    if(!db.open()) {
        qDebug()<<db.lastError();
        qFatal("Fail to connect");
        return false;
    }

    //db.transaction();

    //create database table
    QSqlQuery query(db);

    query.exec("create table Mode (timestamp int primary key,"
               "mode int)");

    query.exec("create table FlightStatus (timestamp int primary key,"
               "flightStatus int)");

    query.exec("create table Baro (timestamp int primary key,"
               "temperature float,"
               "altitude float)");

    query.exec("create table IMU (timestamp int primary key,"
               "acc_x float,"
               "acc_y float,"
               "acc_z float,"
               "gyro_x float,"
               "gyro_y float,"
               "gyro_z float,"
               "mag_x float,"
               "mag_y float,"
               "mag_z float)");

    query.exec("create table GPS (timestamp int primary key,"
               "lat int,"
               "lon int,"
               "azm float,"
               "vel float,"
               "alt float,"
               "sat int,"
               "date int,"
               "time int)");

    query.exec("create table RC (timestamp int primary key,"
               "ch1 float,"
               "ch2 float,"
               "ch3 float,"
               "ch4 float,"
               "ch5 float,"
               "ch6 float,"
               "ch7 float,"
               "ch8 float,"
               "ch9 float,"
               "ch10 float,"
               "ch11 float,"
               "ch12 float,"
               "ch13 float,"
               "ch14 float,"
               "ch15 float,"
               "ch16 float)");

    query.exec("create table Battery_Info (timestamp int primary key,"
                   "voltage float,"
                   "battery_remaining float)");

    /*query.exec("create table Attitude_Setpoint (timestamp int primary key,"
               "thrust float,"
               "yaw_ff float)");
     */

    query.exec("create table Attitude (timestamp int primary key,"
               "rate_x float,"
               "rate_y float,"
               "rate_z float,"
               "euler_R float,"
               "euler_P float,"
               "euler_Y float)");

    query.exec("create table Manual_Setpoint (timestamp int primary key,"
               "throttle float,"
               "euler_R float,"
               "euler_P float,"
               "euler_Y float)");

    query.exec("create table PosCtrl_Setpoint (timestamp int primary key,"
               "position_setpoint_x float,"
               "position_setpoint_y float,"
               "position_setpoint_z float,"
               "vel_ff_x float,"
               "vel_ff_y float,"
               "vel_ff_z float,"
               "acc_ff_x float,"
               "acc_ff_y float,"
               "acc_ff_z float,"
               "yaw_setpoint float)");

    query.exec("create table AltCtrl_Setpoint (timestamp int primary key,"
               "pos_sp_z float,"
               "vel_ff_z float,"
               "euler_R float,"
               "euler_P float,"
               "euler_Y float)");

    query.exec("create table Position (timestamp int primary key,"
               "pos_x float,"
               "pos_y float,"
               "pos_z float,"
               "vel_x float,"
               "vel_y float,"
               "vel_z float,"
               "acc_x float,"
               "acc_y float,"
               "acc_z float)");

    return true;
}

void LogAnalysis::logReadAndStore()
{
    /**/
    db.transaction();

    QStringList tables = db.tables();
    QSqlQuery query(db);
    for(int i = 0;i<tables.count();i++) {
        QString truncateString = QString("truncate table %1").arg(tables.at(i));
        //qDebug()<<truncateString;
        query.exec(truncateString);
    }

    QString fileName = QFileDialog::getOpenFileName(this,"Open File",".\\","texFile(*.txt *.bin)");
    QFile file(fileName);  

    if(fileName.isNull()) {
       QMessageBox::information(this,"Document","No document selected.",QMessageBox::Ok | QMessageBox::Cancel);
       emit openFileStatusChanged(false);
    }
    else {
        emit openFileStatusChanged(true);
        //QFile file("F:\\SIASUN.txt");
        QByteArray b;
        QList<QByteArray> arrayList;
        if(!file.open(QIODevice::ReadOnly)) {
            qDebug()<<"can't open";
            return;
        }
        else {
            // 用"\r\n"即0d0a分行，每一行存储一个数据结构，见sdfiles.h
            b = file.readAll();
            QByteArray turn("\r\n",2);
            int len = turn.length();
            int start = 0;
            int end = b.indexOf(turn,start);
            while(end != -1) {
                arrayList<<b.mid(start,(end-start));
                start = end + len;
                end = b.indexOf(turn,start);
            }
            qDebug()<<arrayList.count();
        }

        for(int i = 0;i<arrayList.size();i++) {
           //读取每一行的数据
            const char* logData = arrayList.at(i).data();
          //第一个字节为message_id
           // qDebug()<<QString::number(*logData);
            //QSqlQuery query(db);

            switch(*logData) {
            case 0:
            {
                mode_log_t* mode_log = (mode_log_t*)logData;
                mode_t mode =mode_log->mode_log_s;
                QString queryString = QString("insert into Mode values(%1,%2)").arg(mode_log->timestamp).arg(mode);
                query.exec(queryString);

                //mode_log_t* mode_log = (mode_log_t*)logData;
                //qDebug()<<"mode"<<mode_log->mode_log_s;
            }
                break;

           //0x01,flight status
            case 1:
            {
                status_log_t* status_log = (status_log_t*)logData;
                statusFlight_t status = status_log->status_log_s;
                QString queryString = QString("insert into FlightStatus values(%1,%2)").arg(status_log->timestamp).arg(status);
                query.exec(queryString);

                //qDebug()<<"status"<<status_log->status_log_s;
            }
                break;

             //0x10, baro
             case 16:
            {
                baro_log_t* baro_log = (baro_log_t*)logData;
                baro_t* baro = (baro_t*)&(baro_log->baro_log_s);

                QString queryString = QString("insert into Baro values(%1,%2,%3)").arg(baro->timestamp).arg(baro->temp).arg(baro->alt);
                query.exec(queryString);
            }
                break;


            //0x11,imu
            case 17:
            {
                 imu_log_t* imu_log = (imu_log_t*)logData;
                 //qDebug()<<"message_id"<<imu_log->message_id;
                 marg_t* marg = (marg_t*)&(imu_log->marg_log_s);
                 //qDebug()<<"x"<<marg->acc.x<<"y"<<marg->acc.y<<"z"<<marg->acc.z;
                 QString queryString = QString("insert into IMU values(%1,%2,%3,%4,%5,%6,%7,%8,%9,%10)").arg(marg->timestamp)
                         .arg(marg->acc.x).arg(marg->acc.y).arg(marg->acc.z)
                         .arg(marg->gyr.x).arg(marg->gyr.y).arg(marg->gyr.z)
                         .arg(marg->mag.x).arg(marg->mag.y).arg(marg->mag.z);
                 query.exec(queryString);
            }
                 break;

            //0x12,gps
            case 18:
            {
                 gps_log_t* gps_log = (gps_log_t*)logData;
                 //qDebug()<<"message_id"<<QString::number(gps_log->message_id);
                 gpsRaw_t* gps = (gpsRaw_t*)&(gps_log->gpsRaw_log_s);
                 qDebug()<<"gps date time"<<gps->date<<gps->time;
                 QString queryString = QString("insert into GPS values(%1,%2,%3,%4,%5,%6,%7,%8,%9)").arg(gps->timestamp)
                         .arg(gps->lat).arg(gps->lon).arg(gps->azm).arg(gps->vel).arg(gps->alt).arg(gps->sat).arg(gps->date).arg(gps->time);
                 query.exec(queryString);
            }
                 break;

            //0x13, rc
            case 19:
            {
                 rc_log_t* rc_log = (rc_log_t*)logData;
                 rc_t* rc = (rc_t*)&(rc_log->rc_log_s);
                 //qDebug()<<"channel 3"<<rc->channels[2];
                 query.prepare("insert into RC values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
                 query.bindValue(0,rc->timestamp);
                 for(int i =1;i<17;i++) {
                     query.bindValue(i,rc->channels[i-1]);
                 }
                 query.exec();
            }
                 break;

            //0x14, power
            case 20:
            {
                bat_log_t* bat_log = (bat_log_t*)logData;
                battery_t* battery = (battery_t*)&(bat_log->bat_log_s);
                QString queryString = QString("insert into Battery_Info values(%1,%2,%3)").arg(battery->timestamp).arg(battery->voltage).arg(battery->battery_remaining);
                qDebug()<<"bat query"<<query.exec(queryString);

                //qDebug()<<"voltage: "<<battery->voltage<<"battery_remaining: "<<battery->battery_remaining;
            }
                 break;

            //0x20, attsp
         /*   case 32:
            {
                attsp_log_t* attsp_log = (attsp_log_t*)logData;
                attsp_t* attsp = (attsp_t*)&(attsp_log->attsp_log_s);
                QString queryString = QString("insert into Attitude_Setpoint values(%1,%2,%3)").arg(attsp->timestamp)
                        .arg(attsp->thrust).arg(attsp->yaw_ff);
                query.exec(queryString);
            }
                break;
        */

             //0x21, att
           case 33:
            {
                att_log_t* att_log = (att_log_t*)logData;
                att_t* att = (att_t*)&(att_log->att_log_s);
                QString queryString = QString("insert into Attitude values(%1,%2,%3,%4,%5,%6,%7)").arg(att->timestamp)
                        .arg(att->rate.x).arg(att->rate.y).arg(att->rate.z).arg(att->Euler.R).arg(att->Euler.P).arg(att->Euler.Y);
                query.exec(queryString);
            }
                break;

                //0x22, output
                case 34:
                {
                output_t* output = (output_t*)logData;
                qDebug()<<"thrust"<<output->thrust;
                }
                    break;

                //0x23, mansp
                case 35:
                {
                mansp_log_t* mansp_log = (mansp_log_t*)logData;
                manCtrlsp_t* manCtrlsp = (manCtrlsp_t*)&(mansp_log->mansp_log_s);
                QString queryString = QString("insert into Manual_Setpoint values(%1,%2,%3,%4)")
                            .arg(manCtrlsp->throttle).arg(manCtrlsp->euler.R).arg(manCtrlsp->euler.P).arg(manCtrlsp->euler.Y);
                    query.exec(queryString);
                }
                    break;

                //0x24, altsp
            case 36:
            {
                altsp_log_t* altsp_log = (altsp_log_t*)logData;
                altCtrlsp_t* altCtrlsp = (altCtrlsp_t*)&(altsp_log->altsp_log_s);
                QString queryString = QString("insert into AltCtrl_Setpoint values(%1,%2,%3,%4,%5)")
                            .arg(altCtrlsp->pos_sp_z).arg(altCtrlsp->euler.R).arg(altCtrlsp->euler.P).arg(altCtrlsp->euler.Y);
                    query.exec(queryString);
            }
                break;

                //0x25, possp
            case 37:
            {
                possp_log_t* possp_log = (possp_log_t*)logData;
                posCtrlsp_t* posCtrlsp = (posCtrlsp_t*)&(possp_log->possp_log_s);
                QString queryString = QString("insert into PosCtrl_Setpoint values(%1,%2,%3,%4,%5,%6,%7,%8,%9,%10,%11)")
                        .arg(posCtrlsp->timestamp).arg(posCtrlsp->pos_sp.x).arg(posCtrlsp->pos_sp.y).arg(posCtrlsp->pos_sp.z)
                        .arg(posCtrlsp->vel_ff.x).arg(posCtrlsp->vel_ff.y).arg(posCtrlsp->vel_ff.z)
                        .arg(posCtrlsp->acc_ff.x).arg(posCtrlsp->acc_ff.y).arg(posCtrlsp->acc_ff.z)
                        .arg(posCtrlsp->yaw_sp);
                query.exec(queryString);
            }
                break;

                //0x26, pos
            case 38:
            {
                pos_log_t* pos_log = (pos_log_t*)logData;
                pos_t* pos = (pos_t*)&(pos_log->pos_log_s);
                QString queryString = QString("insert into Position values(%1,%2,%3,%4,%5,%6,%7,%8,%9,%10)")
                        .arg(pos->timestamp).arg(pos->pos.x).arg(pos->pos.y).arg(pos->pos.z)
                        .arg(pos->vel.x).arg(pos->vel.y).arg(pos->vel.z)
                        .arg(pos->acc.x).arg(pos->acc.y).arg(pos->acc.z);
                query.exec(queryString);
            }
                break;

            default:
                break;
            }
        }
       db.commit();
    }
}
