#include "PX4FirmwarePlugin.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include "PX4ParameterMetaData.h"
#include "Toolbox.h"


PX4FirmwarePlugin::PX4FirmwarePlugin(QuadApplication *app)
     :ToolBase(app)
{

}

void PX4FirmwarePlugin::setToolbox(Toolbox* toolbox)
{
    ToolBase::setToolbox(toolbox);
}

PX4FirmwarePlugin::~PX4FirmwarePlugin()
{

}

PX4ParameterMetaData* PX4FirmwarePlugin::loadParamFactMetaDataFile(QString &metaDataFile)
{
    PX4ParameterMetaData*px4MetaData = new PX4ParameterMetaData;

    qDebug()<<"PX4FirmwarePlugin::loadParamFactMetaDataFile";
    px4MetaData->loadParamFactMetaDataFile(metaDataFile);
    return px4MetaData;
}

void PX4FirmwarePlugin::addMetaDataToFact(PX4ParameterMetaData* px4MetaData,Fact* fact)
{
    if(px4MetaData)
    {
       // qDebug()<<"PX4FirmwarePlugin::addMetaDataToFact,px4metaData exists";
        px4MetaData->addMetaDataToFact(fact);
    }
}
