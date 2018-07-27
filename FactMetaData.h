#ifndef FACTMETADATA_H
#define FACTMETADATA_H

#include <QObject>
#include <QMap>
#include <QVariant>

#include <QDebug>

/// Holds the meta data associated with a Fact. This is kept in a seperate object from the Fact itself
/// since you may have multiple instances of the same Fact. But there is only ever one FactMetaData
/// instance of each Fact.
class FactMetaData : public QObject
{
    Q_OBJECT
public:
    ~FactMetaData();

    typedef enum{
        typeUint8,
        typeInt8,
        typeUint16,
        typeInt16,
        typeUint32,
        typeInt32,
        typeFloat,
        typeDouble
    } ValueType_t;

    explicit FactMetaData(ValueType_t type, QObject *parent = 0);
    static ValueType_t stringToType(const QString &typeString, bool &unknownType);

    bool convertAndValidateRaw(const QVariant &rawValue, bool convertOnly, QVariant &convertValue, QString &errorString);

    ValueType_t type() const    {return _type;}
    void setName(const QString &name) { _name = name;}

    void setShortDescription(const QString &shortDescription) {_shortDescription = shortDescription;}
    void setRawDefaultValue(const QVariant &rawDefaultValue);
    void setRawMin(const QVariant &rawMin);
    void setRawMax(const QVariant &rawMax);

    QString name() const {return _name;}
    QString shortDescription() const {return _shortDescription;}

    QVariant rawDefaultValue() const;
    bool defaultValueAvailable() const {return _defaultValueAvailable;}

    QVariant rawMin() const {return _rawMin;}
    QVariant rawMax() const {return _rawMax;}

signals:

public slots:

private:
    QVariant _minForType() const;
    QVariant _maxForType() const;
    ValueType_t _type;

    bool     _defaultValueAvailable; //true when the default value we get is in range (_rawMin,_rawMax)
                                                                 //accepted and copied to _rawDefaultValue
    QString _name;
    QString _shortDescription;
    QVariant _rawDefaultValue;
    QVariant _rawMax;
    QVariant _rawMin;
    };

#endif // FACTMETADATA_H
