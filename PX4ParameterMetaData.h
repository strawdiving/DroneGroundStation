#ifndef PX4PARAMETERMETADATA_H
#define PX4PARAMETERMETADATA_H

#include <QObject>
#include "FactMetaData.h"
#include "Fact.h"

class PX4ParameterMetaData : public QObject
{
    Q_OBJECT
public:
    explicit PX4ParameterMetaData(QObject *parent = 0);
    ~PX4ParameterMetaData();

    void loadParamFactMetaDataFile(QString &metaDataFile);
    void addMetaDataToFact(Fact* fact);

signals:

public slots:

private:
    enum {
        XMLStateNone,
        XMLStateFoundParameters,
        XMLStateFoundParameter,
        XMLStateDone
    };
    void _loadParameterFactMetaDataFile(const QString& metaDataFile);
    bool _parameterMetaDataLoaded;
    QMap<QString, FactMetaData*> _mapParameterName2FactMetaData;
};

#endif // PX4PARAMETERMETADATA_H
