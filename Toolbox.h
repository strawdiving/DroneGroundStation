#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QObject>

class LinkManager;
class VehicleManager;
class QuadApplication;
class UASMessageHandler;
class PX4FirmwarePlugin;

class Toolbox
{
public:
    Toolbox(QuadApplication* app);
    ~Toolbox();
    LinkManager* linkManager(void) { return _linkMgr;}
    VehicleManager* vehicleManager(void) { return _vehicleMgr;}
    UASMessageHandler* uasMessageHandler(void) { return _uasMessageHandler;}
    PX4FirmwarePlugin* firmwarePlugin(void) {return _firmwarePlugin;}

   private:
    LinkManager* _linkMgr;
    VehicleManager* _vehicleMgr;
    UASMessageHandler* _uasMessageHandler;
    PX4FirmwarePlugin* _firmwarePlugin;

};

class ToolBase : public QObject
{
    Q_OBJECT
public:
    ToolBase(QuadApplication* app);

    virtual void setToolbox(Toolbox* toolbox);

protected:
    QuadApplication* _app;
    Toolbox* _toolbox;
};

#endif // TOOLBOX_H
