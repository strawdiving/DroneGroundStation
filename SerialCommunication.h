

#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

class SerialConfiguration;
class SerialLink;

#include <QThread>
#include <QMutex>
#include <QSerialPort>
#include <common/mavlink.h>

/** @brief Polling interval in ms */
#define SERIAL_POLL_INTERVAL 4

// We use QSerialPort::SerialPortError in a signal so we must declare it as a meta type
Q_DECLARE_METATYPE(QSerialPort::SerialPortError)

class SerialConfiguration:public QObject
{
       Q_OBJECT
        friend class LinkManager;

public:
     SerialConfiguration(const QString &name);

    int  baud()         { return _baud; }
    int  dataBits()     { return _dataBits; }
    int  flowControl()  { return _flowControl; }
    int  stopBits()     { return _stopBits; }
    int  parity()       { return _parity; }
    const QString portName() { return _portName; }
    const QString description() { return _description; }

    void setPortName    (const QString& portName);
    void setBaud        (int baud);

    void setLink(SerialLink* serial) {_link = serial;}

private:
    int _baud;
    int _dataBits;
    int _flowControl;
    int _stopBits;
    int _parity;
    QString _portName;
    QString _description;

protected:
    //link using this cofiguration
    SerialLink * _link;
  };


class SerialLink : public QThread
{
       Q_OBJECT

    friend class SerialCofiguration;
    friend class LinkManager;

public:
      bool isConnected() const;

    //mavlink channel this link using, mavlink_parse_char uses it ,too.
    uint8_t getMavlinkChannel(void) const { Q_ASSERT(_mavlinkChannelSet); return _mavlinkChannel; }
    SerialConfiguration*  getSerialConfiguration();

    void run();
    static const int poll_interval = SERIAL_POLL_INTERVAL;

public slots:
    void readBytes();
    void writeBytes(const char *data,qint64 length);

signals:
    // New data arrived, for control links,not for image transmission
      void bytesReceived(SerialLink* link, QByteArray data);
      void connected();
      void disconnected();

protected:
    QSerialPort* _port;
    quint64 _bytesRead;
    int     _timeout;
    QMutex  _dataMutex;       // Mutex for reading data from _port
    QMutex  _writeMutex;      // Mutex for accessing the _transmitBuffer

private:
    SerialLink(SerialConfiguration *config);
    ~SerialLink();

    void _setMavlinkChannel(uint8_t channel) { Q_ASSERT(!_mavlinkChannelSet); _mavlinkChannelSet = true; _mavlinkChannel = channel; }

    virtual bool _connect(void);
    virtual bool _disconnect(void);
    bool _hardwareConnect();

    volatile bool        _stopp;
    QMutex               _stoppMutex;      // Mutex for accessing _stopp

    QByteArray           _transmitBuffer;  // An internal buffer for receiving data from member functions and actually transmitting them via the serial port.
    SerialConfiguration* _config;

    bool _mavlinkChannelSet = false;    ///< true: _mavlinkChannel has been set
    uint8_t _mavlinkChannel;    ///< mavlink channel to use for this link, as used by mavlink_parse_char
};

#endif // SERIALCOMMUNICATION_H
