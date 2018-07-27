#ifndef PX4FIRMWAREPLUGIN_H
#define PX4FIRMWAREPLUGIN_H

#include "Toolbox.h"
#include "Fact.h"

class QuadApplication;
class PX4ParameterMetaData;

class PX4FirmwarePlugin : public ToolBase
{
    Q_OBJECT
public:
    explicit PX4FirmwarePlugin(QuadApplication* app);
    ~PX4FirmwarePlugin();

     virtual void setToolbox(Toolbox* toolbox);

    PX4ParameterMetaData* loadParamFactMetaDataFile(QString &metaDataFile);
    void addMetaDataToFact(PX4ParameterMetaData *px4MetaData, Fact* fact);

signals:

public slots:

};

#endif // PX4FIRMWAREPLUGIN_H
