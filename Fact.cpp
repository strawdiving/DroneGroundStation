#include "Fact.h"
#include <QDebug>

Fact::Fact(QObject *parent) :
    QObject(parent),
    _metaData(NULL),
    _type(FactMetaData::typeDouble)
{

}

Fact::Fact(int componentId,QString name, FactMetaData::ValueType_t type,QObject *parent)
    :QObject(parent),
      _compId(componentId),
      _metaData(NULL),
      _name(name),
      _type(type)
{
    FactMetaData* metaData = new FactMetaData(_type,this);
    setMetaData(metaData);
}


Fact::~Fact()
{

}

QString Fact::shortDescription() const
{
    if (_metaData) {
        return _metaData->shortDescription();
    } else {
        qWarning() << "Meta data pointer missing";
        return QString();
    }
}

 QVariant Fact::rawDefaultValue() const
 {
     if (_metaData) {
         if(_metaData->defaultValueAvailable()) {
            qDebug()<<"Fact:FactMetaData:rawDefaultValue";            
         }
         else {
             qDebug()<<"Access to unavailable default value.";
         }
         return _metaData->rawDefaultValue();
     }
     else {
         qWarning() << "Meta data pointer missing";
         return QVariant(0);
     }
 }

QVariant Fact::rawMin() const
{
    if (_metaData) {
        return _metaData->rawMin();
    } else {
        qWarning() << "Meta data pointer missing";
        return QVariant(0);
    }
}

QVariant Fact::rawMax() const
{
    if (_metaData) {
        return _metaData->rawMax();
    } else {
        qWarning() << "Meta data pointer missing";
        return QVariant(0);
    }
}

void Fact::setRawValue(const QVariant &value)
{
    if(_metaData) {
        QVariant typedValue;
        QString errorString;

        //convertOnly
        if(_metaData->convertAndValidateRaw(value,true,typedValue,errorString)) {
            if(_rawValue != typedValue) {
                _rawValue.setValue(typedValue);
                emit valueChanged(rawValue());
                emit _containerRawValueChanged(rawValue());
            }
        }
        else {
            qWarning() << "Meta data pointer missing";
        }
    }
}

 void Fact::_containerSetRawValue(const QVariant& value)
 {
     _rawValue = value;
     emit valueChanged(rawValue());
 }

 void Fact::setMetaData(FactMetaData* metadata)
 {
     _metaData = metadata;
     emit valueChanged(rawValue());
 }
