#include "Toolbox.h"
#include "linkmanager.h"
#include "VehicleManager.h"
#include "PX4FirmwarePlugin.h"

Toolbox::Toolbox(QuadApplication *app)
    :_linkMgr(NULL)
    , _vehicleMgr(NULL)
    , _uasMessageHandler(NULL)
    ,_firmwarePlugin(NULL)
{
    _linkMgr = new LinkManager(app);
    _vehicleMgr = new VehicleManager(app);
    _firmwarePlugin = new PX4FirmwarePlugin(app);

    _linkMgr->setToolbox(this);
    _vehicleMgr->setToolbox(this);
    _firmwarePlugin->setToolbox(this);
}

Toolbox::~Toolbox()
{
    delete _linkMgr;
    delete _vehicleMgr;
    delete _firmwarePlugin;
}

ToolBase::ToolBase(QuadApplication* app)
    :QObject((QObject*) app)
    , _app(app)
    , _toolbox(NULL)
{

}

void ToolBase::setToolbox(Toolbox* toolbox)
{
    _toolbox = toolbox;
}
