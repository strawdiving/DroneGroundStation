#include "PX4ParameterMetaData.h"
#include <QFile>
#include <QDir>
#include <QXmlStreamReader>
#include <QDebug>
#include <QRegExp>

PX4ParameterMetaData::PX4ParameterMetaData(QObject *parent) :
    QObject(parent),
    _parameterMetaDataLoaded(false)
{

}

PX4ParameterMetaData::~PX4ParameterMetaData()
{

}

void PX4ParameterMetaData::addMetaDataToFact(Fact* fact)
{
    if(_mapParameterName2FactMetaData.contains(fact->name())) {
        fact->setMetaData(_mapParameterName2FactMetaData[fact->name()]);
    }
}

void PX4ParameterMetaData::loadParamFactMetaDataFile(QString &metaDataFile)
{
    _mapParameterName2FactMetaData.clear();
    _loadParameterFactMetaDataFile(metaDataFile);
}

 void PX4ParameterMetaData::_loadParameterFactMetaDataFile(const QString& metaDataFile)
 {
     qDebug()<<"PX4ParameterMetaData::loadParameterFactMetaDataFile."<<metaDataFile;

     if(_parameterMetaDataLoaded){
         qWarning() << "Internal error: parameter meta data loaded more than once";
         return;
     }
     _parameterMetaDataLoaded = true;
     qDebug()<<"Loading parameter meta data......";

     QFile xmlFile(metaDataFile);
     if(!xmlFile.exists()){
         qWarning()<<"Internal error:metaDataFile missing"<<metaDataFile;
         return;
     }
     if(!xmlFile.open(QIODevice::ReadWrite)) {
         qWarning()<<"Internal error: Unable to open parameter file:"<<metaDataFile<<xmlFile.errorString();
         return;
     }

     QXmlStreamReader xml(xmlFile.readAll());
     xmlFile.close();
     if(xml.hasError()) {
         qWarning()<<"Badly formed xml"<<xml.errorString();
         return;
     }

     int xmlState = XMLStateNone;
     FactMetaData* metaData = NULL;
     bool badMetaData = false;
     QString errorString;

     while(!xml.atEnd()) {
         if(xml.isStartElement()) {
             QString elementName = xml.name().toString();

             if(elementName == "parameters") {
                 if(xmlState!=XMLStateNone) {
                     qWarning() << "parameters: Badly formed XML";
                     return;
                 }
                 xmlState = XMLStateFoundParameters;
             }
            else if(elementName == "parameter") {
                 if(xmlState!=XMLStateFoundParameters) {
                     qDebug() <<  "parameter: Badly formed XML";
                     return;
                 }
                 xmlState = XMLStateFoundParameter;
                 if(!xml.attributes().hasAttribute("name") || !xml.attributes().hasAttribute("type")) {
                     qDebug() <<  "name & type: Badly formed XML";
                     return;
                 }

                 QString name = xml.attributes().value("name").toString();
                 QString type = xml.attributes().value("type").toString();
                 QString strDefault= xml.attributes().value("default").toString();

                 //qDebug()<<"Found parameter name:"<<name<<" type:"<<type<<" default:"<<strDefault;

                 // Convert type from string to FactMetaData::ValueType_t
                 bool unknownType;
                 FactMetaData::ValueType_t foundType = FactMetaData::stringToType(type,unknownType);
                 if(unknownType) {
                     qWarning()<<"Parameter meta data with bad type: "<<type<<" name: "<<name;
                     return;
                 }

                 metaData = new FactMetaData(foundType);

                 //add to FactMetaData
                 if(_mapParameterName2FactMetaData.contains(name)) {
                     badMetaData = true;
                     qWarning()<<"Duplicate parameter found: "<<name;
                     //reset to default meta data
                     _mapParameterName2FactMetaData[name] = metaData;
                 }
                 else {
                 _mapParameterName2FactMetaData[name] = metaData;
                 metaData->setName(name);

                 if(xml.attributes().hasAttribute("default") && !strDefault.isEmpty()) {
                     QVariant varDefault;

                     if(metaData->convertAndValidateRaw(strDefault,false,varDefault,errorString)) {
                         metaData->setRawDefaultValue(varDefault);                         
                     }
                     else {
                         qDebug()<< "Invalid default value, name:" << name << " type:" << type << " default:" << strDefault << " error:" << errorString;
                     }
                 }
                 }
             }
             else {
                 //be getting meta data now
                 if(xmlState!=XMLStateFoundParameter) {
                     qDebug() <<  "Badly formed XML"<<xmlState;
                     return;
                 }

                  if(!badMetaData) {
                     if(elementName == "short_desc") {
                         QString text = xml.readElementText();
                         text = text.replace("\n"," ");
                         //qDebug()<<"Short Description: "<<text;
                         metaData->setShortDescription(text);
                     }          
                     else if(elementName == "min") {
                         QString text = xml.readElementText();
                         //qDebug()<<"Min: "<<text;
                         QVariant varMin;
                         //convertOnly, i.e. only convertOk matters
                         if(metaData->convertAndValidateRaw(text,true,varMin,errorString)) {
                             metaData->setRawMin(varMin);
                         }
                         else {
                             qWarning()<< "Invalid min value, name:" << metaData->name() << " type:" << metaData->type() << " min:" << text << " error:" << errorString;
                         }
                     }
                     else if(elementName == "max") {
                         QString text = xml.readElementText();
                         //qDebug()<<"Max: "<<text;
                         QVariant varMax;
                         //convertOnly, i.e. only convertOk matters
                         if(metaData->convertAndValidateRaw(text,true,varMax,errorString)) {
                             metaData->setRawMax(varMax);
                         }
                         else {
                             qWarning()<< "Invalid max value, name:" << metaData->name() << " type:" << metaData->type() << " min:" << text << " error:" << errorString;
                         }
                     }
                     else {
                         //qDebug()<< "Unknown element in XML: " << elementName;
                 }
             }
         }
     }
         else if (xml.isEndElement()) {
            QString elementName = xml.name().toString();
            if(elementName == "parameter") {
                // Reset for next parameter
                metaData = NULL;
                badMetaData = false;
                xmlState = XMLStateFoundParameters;
            }
         else if (elementName == "parameters") {
                xmlState = XMLStateFoundParameters;
            }
         }
         xml.readNext();
     }
 }
