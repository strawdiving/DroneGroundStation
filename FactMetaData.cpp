#include "FactMetaData.h"
#include <limits>
#include <QDebug>

FactMetaData::FactMetaData(ValueType_t type,QObject *parent) : QObject(parent)
  , _type(type)
  , _rawDefaultValue(0)
  , _defaultValueAvailable(false)
  , _rawMin(_minForType())
  , _rawMax(_maxForType())
{

}

FactMetaData::~FactMetaData()
{

}

QVariant FactMetaData::_minForType() const
{
    switch(_type) {
    case typeUint8:
        return QVariant(std::numeric_limits<unsigned char>::min());
    case typeInt8:
        return QVariant(std::numeric_limits<char>::min());
    case typeUint16:
        return QVariant(std::numeric_limits<unsigned short int>::min());
    case typeInt16:
        return QVariant(std::numeric_limits<short int>::min());
    case typeUint32:
        return QVariant(std::numeric_limits<unsigned int>::min());
    case typeInt32:
        return QVariant(std::numeric_limits<int>::min());
    case typeFloat:
        return QVariant(-std::numeric_limits<float>::max());
    case typeDouble:
        return QVariant(-std::numeric_limits<double>::max());
    }

    return QVariant();
}

QVariant FactMetaData::_maxForType() const
{
    switch(_type) {
    case typeUint8:
        return QVariant(std::numeric_limits<unsigned char>::max());
    case typeInt8:
        return QVariant(std::numeric_limits<char>::max());
    case typeUint16:
        return QVariant(std::numeric_limits<unsigned short int>::max());
    case typeInt16:
        return QVariant(std::numeric_limits<short int>::max());
    case typeUint32:
        return QVariant(std::numeric_limits<unsigned int>::max());
    case typeInt32:
        return QVariant(std::numeric_limits<int>::max());
    case typeFloat:
        return QVariant(std::numeric_limits<float>::max());
    case typeDouble:
        return QVariant(std::numeric_limits<double>::max());
    }
    return QVariant();
}

void FactMetaData::setRawDefaultValue(const QVariant &rawDefaultValue)
{
    if(_rawMin < rawDefaultValue && rawDefaultValue < _rawMax) {
        _rawDefaultValue = rawDefaultValue;
        _defaultValueAvailable = true;
    }
    else {
        qWarning() << "Attempt to set default value which is outside min/max range";
    }
}

void FactMetaData::setRawMin(const QVariant &rawMin)
{
    if(rawMin >= _minForType()) {
        _rawMin = rawMin;
    }
    else {
        qWarning()<<"Attempt to set min below allowable value.";
      _rawMin = _minForType();
    }
}

void FactMetaData::setRawMax(const QVariant &rawMax)
{
    if(rawMax < _maxForType()) {
        _rawMax = rawMax;
    }
    else {
        qWarning() << "Attempt to set max above allowable value";
        _rawMax = _maxForType();
    }
}

FactMetaData::ValueType_t FactMetaData::stringToType(const QString &typeString,bool &unknownType)
 {
     QStringList typeStringList;
     QList<ValueType_t> knownTypes;
     unknownType = false;

     typeStringList<< QStringLiteral("Uint8")
                             << QStringLiteral("Int8")
                             << QStringLiteral("Uint16")
                             << QStringLiteral("Int16")
                             << QStringLiteral("Uint32")
                             << QStringLiteral("Int32")
                             << QStringLiteral("Float")
                             << QStringLiteral("Double");

      knownTypes<< typeUint8
                           << typeInt8
                           << typeUint16
                           << typeInt16
                           << typeUint32
                           << typeInt32
                           << typeFloat
                           << typeDouble;

      for(int i=0;i<typeStringList.count();i++) {
          if(typeStringList.at(i).compare(typeString,Qt::CaseInsensitive) == 0) {
              return knownTypes.at(i);
          }
      }
      unknownType = true;
      return FactMetaData::typeDouble;
 }


bool FactMetaData::convertAndValidateRaw(const QVariant &rawValue, bool convertOnly, QVariant &convertValue, QString &errorString)
{
    bool convertOk = false;
    errorString.clear();

    switch(type()) {
    case typeUint8:
    case typeUint16:
    case typeUint32:
        convertValue = rawValue.toUInt(&convertOk);
        if(!convertOnly && convertOk) {
            if(convertValue>rawMax() || convertValue<rawMin()) {
                errorString = QString("Value must be within %1 and %2.").arg(rawMin().toUInt()).arg(rawMax().toUInt());
            }
        }
        break;

     case typeInt8:
     case typeInt16:
     case typeInt32:
        convertValue = rawValue.toInt(&convertOk);
        if(!convertOnly && convertOk) {
            if(convertValue>rawMax() || convertValue<rawMin()) {
                errorString = QString("Value must be within %1 and %2.").arg(rawMin().toInt()).arg(rawMax().toInt());
            }
        }
        break;

     case typeFloat:
        convertValue = rawValue.toFloat(&convertOk);
        if(!convertOnly && convertOk) {
            if(convertValue>rawMax() || convertValue<rawMin()) {
                errorString = QString("Value must be within %1 and %2.").arg(rawMin().toFloat()).arg(rawMax().toFloat());
            }
        }
        break;

     case typeDouble:
       convertValue = rawValue.toDouble(&convertOk);
       if(!convertOnly && convertOk) {
           if(convertValue>rawMax() || convertValue<rawMin()) {
               errorString = QString("Value must be within %1 and %2.").arg(rawMin().toDouble()).arg(rawMax().toDouble());
           }
       }
       break;
    }
    return convertOk && errorString.isEmpty();
}

QVariant FactMetaData::rawDefaultValue() const
{
    if(_defaultValueAvailable) {
        return _rawDefaultValue;
    }
    else {
        qWarning()<<"Attempt to access unavailable default value";
        return QVariant(0);
    }
}


