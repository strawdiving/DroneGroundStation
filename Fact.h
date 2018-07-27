#ifndef FACT_H
#define FACT_H

#include <QObject>
#include <QVariant>
#include "FactMetaData.h"

/// @brief A Fact is used to hold a single param value within the system.
class Fact : public QObject
{
    Q_OBJECT
public:
    explicit Fact(QObject *parent = 0);
    Fact(int componentId,QString name, FactMetaData::ValueType_t type,QObject *parent);
    ~Fact();

    int compId() {return _compId;}

      /// Sets the meta data associated with the Fact.
    void setMetaData(FactMetaData* metadata);

    QVariant rawValue() const {return _rawValue;}    
    void setRawValue(const QVariant &value);
    void _containerSetRawValue(const QVariant& value);

    QString name() const { return _name;}
    FactMetaData::ValueType_t type() const {return _type;}

    QString shortDescription() const;
    QVariant rawDefaultValue() const;
    QVariant rawMin() const;
    QVariant rawMax() const;

signals:
   void valueChanged(QVariant value);

    /// Signalled when property has been changed
    void _containerRawValueChanged(const QVariant& value);

public slots:

private:
    QVariant _rawValue;
    FactMetaData* _metaData;
    int _compId;
    QString _name;
    FactMetaData::ValueType_t _type;
};

#endif // FACT_H
