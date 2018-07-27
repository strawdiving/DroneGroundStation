/**
 * @file
 *   @brief This class
 * writes to serial port and reads data from serial port
 *
 *   @author QAH <qinanhong@siasun.com>
 *
 */
#include "SerialCommunication.h"
#include <QSerialPort>
#include <QtDebug>

SerialLink::SerialLink(SerialConfiguration *config)
{
_bytesRead = 0;
_port = NULL;
_stopp = false;
Q_ASSERT(config != NULL);
_config = config;
_config->setLink(this);

moveToThread(this);
//qDebug()<<"Create SerialCommunication"<<config->portName()<<config->baud();
}

SerialLink::~SerialLink()
{
_config->setLink(NULL);
_disconnect();

// thread
quit();
wait();
}

// Runs the thread
void SerialLink::run()
{
  _hardwareConnect();
    forever
   {
     {
        QMutexLocker locker(&this->_stoppMutex);
    if(_stopp)
    {
        _stopp = false;
        break; //exit the thread
    }
     }

    //buffer data transmitted trough serial port
    if(_transmitBuffer.count()>0)
    {
        _writeMutex.lock();
        //from QByteArray to device
       int bytesWritten = _port->write(_transmitBuffer);
       //from internal write buffer to serial port without blocking
       bool txSuccess =   _port->flush();
       txSuccess |= _port->waitForBytesWritten(10);
       if(!txSuccess|| bytesWritten !=_transmitBuffer.count())
       {
           qDebug()<<"Tx error!"<< txSuccess << "wrote" << bytesWritten << ", asked for " << _transmitBuffer.count() << "bytes";
       }
      _transmitBuffer = _transmitBuffer.remove(0,bytesWritten);
       _writeMutex.unlock();
    }

    //read data from serial port
    _dataMutex.lock();
    bool rxSuccess = _port->waitForReadyRead(20);
    if(rxSuccess)
    {
        //read all available data from port
        QByteArray readData = _port->readAll();
        while(_port->waitForReadyRead(10))
        {
            readData += _port->readAll();
          }
       _dataMutex.unlock();

       if(readData.length()>0)
       {
        emit bytesReceived(this,readData);
       }
       _bytesRead += readData.length();
    }
else
    {
        _dataMutex.unlock();
    }
    QThread::msleep(SerialLink::poll_interval);
}

   //close the port
   if(_port)
     {
     qDebug()<<"Closing port #"<<_port->portName();
     _port->close();
     delete _port;
     _port = NULL;
     }
}

//start the thread
bool SerialLink::_connect()
{
    if(isRunning())
     {
         _disconnect();
     }
    //_hardwareConnect();
    {
       QMutexLocker locker(&this->_stoppMutex);
        _stopp = false;
    }
    start(HighPriority);
    return true;
}

//connect the serial port
bool SerialLink::_hardwareConnect()
{
    //qDebug()<<"_hardwareConnect called, open the port";
    if(_port)
    {
        _port->close();
        QThread::msleep(5000);
        delete _port;
        _port = NULL;
    }

    //qDebug() << "Creating and configuring port";
    _port = new QSerialPort();
    _port->setPortName(_config->portName());
    _port->setBaudRate( _config->baud());
    _port->setDataBits     (static_cast<QSerialPort::DataBits>     (_config->dataBits()));
    _port->setFlowControl  (static_cast<QSerialPort::FlowControl>  (_config->flowControl()));
    _port->setStopBits     (static_cast<QSerialPort::StopBits>     (_config->stopBits()));
    _port->setParity       (static_cast<QSerialPort::Parity>       (_config->parity()));

    if (!_port) {
        qDebug()<<_config->portName()<<"Error creating port: " << _config->portName();
        return false; // couldn't create serial port.
    }

    if (!_port->open(QIODevice::ReadWrite)) {
        qDebug()<<_config->portName()<<"Error opening port: " << _port->errorString();
        _port->close();
        return false; // couldn't open serial port
       }
    else
      {
        qDebug()<<_port->portName()<< " Port opened!";
        emit connected();
        return true;
       }
}

//stop the thread
bool SerialLink::_disconnect()
{
    if(isRunning())
   {
        QMutexLocker locker(&this->_stoppMutex);
         _stopp = true;
    }
    else
    {
         _transmitBuffer.clear(); //clear the output buffer to avoid sending garbage at next connect
         qDebug()<<"Already disconnected!";
    }
    return true;
}

bool SerialLink::isConnected() const
{
    bool isConnected = false;
    if (_port) {
        isConnected = _port->isOpen();
    }
    return isConnected;
}

//write to _transmitBuffer
void SerialLink::writeBytes(const char *data, qint64 length)
{
if(_port && _port->isOpen())
{
    QByteArray buffer(data,length);
    _writeMutex.lock();
    _transmitBuffer.append(buffer);
    _writeMutex.unlock();
}
else
    qDebug()<<"Couldn't send data! "<<_config->portName()<<" is desconnected!";
}

void SerialLink::readBytes()
{
if(_port && _port->isOpen())
{
        const qint64 maxLength = 2048;
        char data[maxLength];
        _dataMutex.lock();
        qint64 numBytes = _port->bytesAvailable();

        if(numBytes > 0) {
            /* Read as much data in buffer as possible without overflow */
            if(maxLength < numBytes) numBytes = maxLength;

            _port->read(data, numBytes);
            QByteArray b(data, numBytes);
            emit bytesReceived(this, b);
        }
        _dataMutex.unlock();
    }
}

SerialConfiguration* SerialLink::getSerialConfiguration()
{
    return _config;
}

SerialConfiguration::SerialConfiguration(const QString& name)
{
    _description = name.trimmed();
    _portName = name.trimmed();
    _baud       = 57600;
    _flowControl= QSerialPort::NoFlowControl;
    _parity     = QSerialPort::NoParity;
    _dataBits   = 8;
    _stopBits   = 1;
}

void SerialConfiguration::setPortName(const QString& portName)
{
    QString pname = portName.trimmed();
    if (!pname.isEmpty() && pname != _portName) {
        _portName = pname;
    }
}

void SerialConfiguration::setBaud(int baud)
{
    _baud = baud;
}
