/**
 * @file
 *   @brief Class LinkManager. This class manages serial configures and links, receive the complete mavlink packet and decode ,emit signals
 *               to MainWindow.
 *   @author QAH <qin.anhong@163.com>
 *
 */
#ifndef LINKMANAGER_H
#define LINKMANAGER_H

#include "Toolbox.h"

#include "SerialCommunication.h"
#include <QList>
#include <QTimer>
#include <QDateTime>
#include <mavlink_types.h>

#define DEFAULT_SYSTEM_ID 255
#define DEFAULT_COMPONENT_ID 0
//APM 3 Pixhawk 1

class QuadApplication;

class LinkManager : public ToolBase
{
    Q_OBJECT
public:
    LinkManager(QuadApplication* app);
     ~LinkManager();

    /// Override from ToolBase
    virtual void setToolbox(Toolbox* toolbox);

    ///update serial config list
    void _updateConfigurationList(void);
    ///get serial config list
    const QList<SerialConfiguration*> getSerialConfigurationList();

   /// Creates, connects a link  based on the given configuration instance
   SerialLink *createConnectedLink(SerialConfiguration* config);
   void setLink(SerialLink* link);
   SerialLink* getLink();
   /// Connect/disconnect  the specified link,start/stop the thread
   void disconnectLink(SerialLink *link);

   quint64 getHeartbeatTime() {return lastHeartbeat;}

   ///get current link and call sendMessage(SerialLink* link, mavlink_message_t message)
   void sendMessage(mavlink_message_t message);
   /////send message via serial link
   void sendMessage(SerialLink* link, mavlink_message_t message);

signals:
   void linkDisconnected(SerialLink* link);

   /// Forward heartbeat package
   void vehicleHeartbeatInfo(SerialLink* link, int vehicleId);
   /// Forward received message
   void messageReceived(SerialLink*link, mavlink_message_t &message);

private slots:
    void _linkConnected(void);
    void _linkDisconnected(void);
    void _receiveBytes(SerialLink* link, QByteArray b);

private:
    ///find available serial config
    SerialConfiguration* _findSerialConfiguration(const QString& portName);
    ///add available serial config
    void _addSerialConfiguration(SerialConfiguration* config);
    void _linkStatusChanged(SerialLink* link, bool connected);

     SerialLink* _link;
     ///to store known serial configs
     QList<SerialConfiguration*> _serialConfigurations;

     uint32_t  _mavlinkChannelsUsedBitMask;
     ///time when heartbeat received
     quint64 lastHeartbeat;
};

#endif // LINKMANAGER_H
