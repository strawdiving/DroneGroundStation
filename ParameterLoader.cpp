#include "ParameterLoader.h"
#include "QuadApplication.h"
#include <QSettings>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include "PX4AutopioltPlugins/PX4AutopilotPlugin.h"
#include "PX4FirmwarePlugin.h"
#include <QVariant>
#include "Vehicle.h"
#include "linkmanager.h"
#include "UAS.h"
#include <QThread>

Fact ParameterLoader::_defaultFact;

ParameterLoader::ParameterLoader(Vehicle* vehicle,QObject *parent) :
    QObject(parent),
   _defaultCompId(PX4AutopilotPlugin::defaultCompId),
    _vehicle(vehicle),
    _compParamsComplete(false),
    _currentParamCount(0),
    _parameterMetaData(NULL)
{
    _initialParamRequestTimer.setSingleShot(true);
    _initialParamRequestTimer.setInterval(5000);
    connect(&_initialParamRequestTimer,&QTimer::timeout,this,&ParameterLoader::_initialParamRequestTimeout);
    connect(_vehicle->uas(),&UAS::parameterUpdate,this,&ParameterLoader::_parameterUpdate);

    _refreshAllParameters();
}

ParameterLoader::~ParameterLoader()
{

}

//check whether params loaded completely, and send param_request_list message to request for all parameters
void ParameterLoader::_refreshAllParameters()
{
    qDebug()<<"ParameterLoader: refreshAllParameters";
    if(!_compParamsComplete) {
        _initialParamRequestTimer.start();
    }

    mavlink_message_t msg;
    mavlink_param_request_list_t param;
    param.target_component = 0;
    param.target_system =1;

    mavlink_msg_param_request_list_encode(DEFAULT_SYSTEM_ID,DEFAULT_COMPONENT_ID,&msg,&param);
    _vehicle->linkManager()->sendMessage(msg);
}

void ParameterLoader::refreshParameters(void)
{
    _mapParamName2Variant.clear();
    _currentParamCount = 0;
    _compParamsComplete = false;
    _refreshAllParameters();
}

///if no parameteru updated (no param_value message received) in 6s, send param_request_list message again
void ParameterLoader::_initialParamRequestTimeout()
{
    qDebug()<<"Vehicle did not respond to request for parameters, retrying.";
    _refreshAllParameters();
    _initialParamRequestTimer.start();
}

/// Called whenever a parameter is updated or first seen.
void ParameterLoader::_parameterUpdate(int componentId, QString paramName, int paramCount, int paramId, int type,QVariant value)
{
    Q_UNUSED(paramId)

    _initialParamRequestTimer.stop();

    if(_compParamsComplete) {
        return;
    }

    qDebug()<<QString("_parameterUpdate (compId :%1, "
                    "name:%2,count:%3,"
                    "index:%4,"
                    "mavType:%5,"
                    "value:%6).").arg(QString::number(componentId)).arg(paramName)
             .arg(QString::number(paramCount)).arg(QString::number(paramId)).arg(type).arg(value.toString());

    _dataMutex.lock();

   _defaultCompId = componentId;
   _totalParamCount = paramCount;

   if(!_mapParamName2Variant.contains(paramName)) {
       //qDebug()<<"Adding new fact";
       _currentParamCount++;
       FactMetaData::ValueType_t factType;
       switch(type) {
       case MAV_PARAM_TYPE_UINT8:
           factType = FactMetaData::typeUint8;
           break;
       case MAV_PARAM_TYPE_INT8:
           factType = FactMetaData::typeInt8;
           break;
       case MAV_PARAM_TYPE_UINT16:
           factType = FactMetaData::typeUint16;
           break;
       case MAV_PARAM_TYPE_INT16:
           factType = FactMetaData::typeInt16;
           break;
       case MAV_PARAM_TYPE_UINT32:
           factType = FactMetaData::typeUint32;
           break;
       case MAV_PARAM_TYPE_INT32:
           factType = FactMetaData::typeInt32;
           break;
       case MAV_PARAM_TYPE_REAL32:
           factType = FactMetaData::typeFloat;
           break;
       case MAV_PARAM_TYPE_REAL64:
           factType = FactMetaData::typeDouble;
           break;
       default:
           factType = FactMetaData::typeInt32;
           qCritical()<<"Unsupported fact type:"<<type;
           break;
       }
       emit paramLoadProgress(_currentParamCount,paramCount);

       Fact* fact = new Fact(componentId,paramName,factType,this);
       //Returns a QVariant containing a copy of value
       _mapParamName2Variant[paramName] = QVariant::fromValue(fact);

       // when value changed, send the new value to the parameter manager
       connect(fact, &Fact::_containerRawValueChanged, this, &ParameterLoader::_valueUpdated);
   }
   _dataMutex.unlock();

   Q_ASSERT(_mapParamName2Variant.contains(paramName));
   Fact* fact = _mapParamName2Variant[paramName].value<Fact*>();
   Q_ASSERT(fact);

    fact->_containerSetRawValue(value);

    if(_compParamsComplete) {
        _addMetaDataToDefaultComponent();
    }
    _checkInitialLoadComplete();
}

void ParameterLoader::_checkInitialLoadComplete(void)
{
    if(_compParamsComplete) {
        return;
    }

    if(_currentParamCount == _totalParamCount) {
        qDebug()<<QString("%1 ParameterLoader: parameters loading completed").arg(_totalParamCount);
        _currentParamCount = 0;
        _compParamsComplete = true;
        qDebug()<<"parameters ready true";
        emit paramsReady(true);
    }
    else {
        _initialParamRequestTimer.start();
    }
}

 void ParameterLoader::_addMetaDataToDefaultComponent(void)
 {
     if(_defaultCompId == PX4AutopilotPlugin::defaultCompId) {
         return;
     }
     QString metaDataFile = QString(":\\cal_params.xml");

     //_px4MetaData created
     _parameterMetaData = _vehicle->firmwarePlugin()->loadParamFactMetaDataFile(metaDataFile);

      foreach (const QString&key,_mapParamName2Variant.keys()) {
         _vehicle->firmwarePlugin()->addMetaDataToFact(_parameterMetaData,_mapParamName2Variant[key].value<Fact*>());
     }
 }

/// Connected to Fact::valueUpdated
/// Writes the parameter to mavlink, sets up for write wait
void ParameterLoader::_valueUpdated(const QVariant& value)
{
    Fact* fact = qobject_cast<Fact*>(sender());
    Q_ASSERT(fact);

    _vehicle->uas()->writeParameterRaw(fact->compId(),fact->name(),value);
    qDebug()<<"Set parameter (componentId: "<<fact->compId()<<"name: "<<fact->name()<<value;
}

bool ParameterLoader::paramExists(int componentId,const QString& name)
{
    bool exist = false;
    componentId = _actualCompId(componentId);
    if(_mapParamName2Variant.contains(name)) {
            exist = true;
    }
    return exist;
}

Fact* ParameterLoader::getFact(int componentId, const QString& name)
{
    componentId = _actualCompId(componentId);
    if(!_mapParamName2Variant.contains(name)) {
        return &_defaultFact;
    }
    return _mapParamName2Variant[name].value<Fact*>();
    qDebug()<<"ParameterLoader: "<<_mapParamName2Variant[name].value<Fact*>()->name();
}

int ParameterLoader::_actualCompId(int componentId)
{
    if(componentId == PX4AutopilotPlugin::defaultCompId) {
      componentId = _defaultCompId;
        if(componentId == PX4AutopilotPlugin::defaultCompId) {
            qWarning()<<"Default component id not set";
        }
    }
    return componentId;
}
