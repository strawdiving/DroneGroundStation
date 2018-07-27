#include "FlightModesComponentController.h"

FlightModesComponentController::FlightModesComponentController()
    : _offboardModeSelected(false),
      _autoModeSelected(false),
      _returnModeSelected(false),
      //_loiterModeSelected(false),
      //_missionModeSelected(false),
      _posCtlModeSelected(false),
      _altCtlModeSelected(false),
     _assistModeSelected(false),
     _acroModeSelected(false),
     _manualModeSelected(false)
{
    QStringList usedParams;
    usedParams<<"RC_MAP_THROTTLE"<<"RC_MAP_YAW"<<"RC_MAP_ROLL"<<"RC_MAP_PITCH"<<"RC_MAP_FLAPS"<<"RC_MAP_AUX1"<<"RC_MAP_AUX2"
                <<"RC_MAP_MODE_SW"<<"RC_MAP_RETURN_SW"<<"RC_MAP_POSCTL_SW"<<"RC_MAP_LOITER_SW"<<"RC_MAP_ACRO_SW"<<"RC_MAP_OFFB_SW";
    if(!_allParamsExist(PX4AutopilotPlugin::defaultCompId,usedParams)) {
        return;
        qDebug()<<"FlightModesComponentController::Not all params exist";
    }

    _init();

    connect(_vehicle,&Vehicle::rcChannelsChanged,this,&FlightModesComponentController::_rcChannelsChanged);

}

void FlightModesComponentController::_init()
{
   //Get min and max for channel in order to calculate percentage range,ie. rcValue
    for(int channel=0;channel<_maxChannel;channel++) {
        //param 1-based
        QString rcMinParam = QString("RC%1_MIN").arg(channel+1);
        QString rcMaxParam = QString("RC%1_MAX").arg(channel+1);
        QString rcRevParam = QString("RC%1_REV").arg(channel+1);

        _rcMinValues[channel] = getParamFact(-1,rcMinParam)->rawValue().toInt();
        _rcMaxValues[channel] = getParamFact(-1,rcMaxParam)->rawValue().toInt();

        float reversedValue = getParamFact(-1,rcRevParam)->rawValue().toFloat();
        _rcReversed[channel] = (reversedValue == -1.0f);

        _rcValues[channel] = 0.0f;
    }

    //RC_CHAN_CNT param is set by Radio Cal to specify the number of radio channels.
    if(_autopilot->paramExists(-1,"RC_CHAN_CNT")) {
        _channelCount = getParamFact(-1,"RC_CHAN_CNT")->rawValue().toInt();
        if(_channelCount <= 0 || _channelCount > _maxChannel) {
            _channelCount = _maxChannel;
        }
    } else {
        _channelCount = _maxChannel;
    }

    //Find unused channels
    QList<int> usedChannels;
    QStringList attitudeParams;
    attitudeParams<<"RC_MAP_THROTTLE"<<"RC_MAP_YAW"<<"RC_MAP_ROLL"<<"RC_MAP_PITCH"<< "RC_MAP_FLAPS" << "RC_MAP_AUX1" << "RC_MAP_AUX2";

    foreach (const QString &attitudeParam, attitudeParams) {
        int channel = getParamFact(-1,attitudeParam)->rawValue().toInt();
        if(channel != 0) {
            usedChannels<<channel;
        }
    }

    _channelListModel<<"Disabled";
    //channelList : 0-based
    _channelList<<0;

    for(int channel = 1; channel<=_channelCount;channel++) {
        if(!usedChannels.contains(channel)) {
            _channelList<<channel;
            _channelListModel<<QString("Channel %1").arg(channel);
        }
    }
}

FlightModesComponentController::~FlightModesComponentController()
{

}

void FlightModesComponentController::_rcChannelsChanged(int channelCount,int pwmValues[Vehicle::maxRCChannelsCount])
{
    for(int channel = 0;channel<channelCount;channel++) {
        int channelValue = pwmValues[channel];
        if(channelValue!=-1) {
            if(channelValue > _rcMaxValues[channel]) {
                channelValue = _rcMaxValues[channel];
            }
            if(channelValue < _rcMinValues[channel]) {
                channelValue = _rcMinValues[channel];
            }

            float percentRange = (channelValue - _rcMinValues[channel])/(_rcMaxValues[channel] - _rcMinValues[channel]);
            if(_rcReversed[channel]) {
                percentRange = 1.0 - percentRange;
            }
            _rcValues[channel] = percentRange;
        }
        _recalcModeSelections();
    }
}

// refer to PX4 Flight Mode Flow Diagram, (6 switch + 7 threshold)
void FlightModesComponentController::_recalcModeSelections()
{
    _offboardModeSelected = false;
    _autoModeSelected = false;
    _returnModeSelected = false;
   // _loiterModeSelected = false;
    //_missionModeSelected = false;
    _posCtlModeSelected = false;
    _altCtlModeSelected = false;
    _assistModeSelected = false;
    _acroModeSelected = false;
    _manualModeSelected = false;

    //channels are 1 - based : 0 - unassigned, NOT MAPPED ,change it to 0-based
    int modeSwChannel = getParamFact(-1,"RC_MAP_MODE_SW")->rawValue().toInt()-1;
    int returnSwChannel = getParamFact(-1,"RC_MAP_RETURN_SW")->rawValue().toInt()-1;
    int posCtlSwChannel =  getParamFact(-1,"RC_MAP_POSCTL_SW")->rawValue().toInt()-1;
    //int loiterSwChannel =  getParamFact(-1,"RC_MAP_LOITER_SW")->rawValue().toInt()-1;
    int acroSwChannel =  getParamFact(-1,"RC_MAP_ACRO_SW")->rawValue().toInt()-1;
    int offboardSwChannel =  getParamFact(-1,"RC_MAP_OFFB_SW")->rawValue().toInt()-1;

    double assistThreshold = getParamFact(-1,"RC_ASSIST_TH") ->rawValue().toDouble();
    double autoThreshold = getParamFact(-1,"RC_AUTO_TH") ->rawValue().toDouble();
    double posCtlThreshold = getParamFact(-1,"RC_POSCTL_TH") ->rawValue().toDouble();
    double returnThreshold = getParamFact(-1,"RC_RETURN_TH") ->rawValue().toDouble();
    //double loiterThreshold = getParamFact(-1,"RC_LOITER_TH") ->rawValue().toDouble();
    double acroThreshold = getParamFact(-1,"RC_ACRO_TH") ->rawValue().toDouble();
    double offboardThreshold = getParamFact(-1,"RC_OFFB_TH") ->rawValue().toDouble();

    if(modeSwChannel >=0) {
        if(offboardSwChannel >=0 && _rcValues[offboardSwChannel] >= offboardThreshold) {
            _offboardModeSelected = true;
        }
        else if(returnSwChannel >=0 && _rcValues[returnSwChannel] >= returnThreshold) {
            _returnModeSelected = true;
        }
        else {
            if(_rcValues[modeSwChannel] >= autoThreshold) {
                _autoModeSelected = true;
                /*if(loiterSwChannel >=0 && _rcValues[loiterSwChannel] >= loiterThreshold) {
                    _loiterModeSelected = true;
                } else {
                    _missionModeSelected = true;
                }*/
            }
            else if(_rcValues[modeSwChannel] >= assistThreshold) {
                _assistModeSelected = true;
                if(posCtlSwChannel >=0 && _rcValues[posCtlSwChannel] >= posCtlThreshold) {
                    _posCtlModeSelected = true;
                } else {
                    _altCtlModeSelected = true;
                }
            }
            else if (acroSwChannel >=0 && _rcValues[acroSwChannel] >= acroThreshold) {
                _acroModeSelected = true;
            }
            else {
                _manualModeSelected = true;
            }
        }
    }
    //emit signals
    emit offboardModeSelectedChanged(_offboardModeSelected);
    emit autoModeSelectedChanged(_autoModeSelected);
    emit returnModeSelectedChanged(_returnModeSelected);
    emit posCtlModeSelectedChanged(_posCtlModeSelected);
    emit altCtlModeSelectedChanged(_altCtlModeSelected);
    emit assistModeSelectedChanged(_assistModeSelected);
    emit acroModeSelectedChanged(_acroModeSelected);
    emit manualModeSelectedChanged(_manualModeSelected);
}

void FlightModesComponentController::_setOffboardChannelIndex(int index)
{
    qDebug()<<"offboard: "<<_channelList.at(index);
    getParamFact(-1,"RC_MAP_OFFB_SW")->setRawValue(_channelList.at(index));
    _recalcModeSelections();
}

void FlightModesComponentController::_setReturnChannelIndex(int index)
{
    getParamFact(-1,"RC_MAP_RETURN_SW")->setRawValue(_channelList.at(index));
    _recalcModeSelections();
}

void FlightModesComponentController::_setPosCtlChannelIndex(int index)
{
    int channel = _channelList.at(index);
    getParamFact(-1,"RC_MAP_POSCTL_SW")->setRawValue(channel);

    // PosCtl disabled so AltCtl must move back to main Mode switch
   // Assist mode is visible if AltCtl/PosCtl are on seperate channel from main Mode switch

    _recalcModeSelections();
}

void FlightModesComponentController::_setAcroChannelIndex(int index)
{
    getParamFact(-1,"RC_MAP_ACRO_SW")->setRawValue(_channelList.at(index));
    _recalcModeSelections();
}

void FlightModesComponentController::_setManualChannelIndex(int index)
{
    getParamFact(-1,"RC_MAP_MODE_SW")->setRawValue(_channelList.at(index));
    _recalcModeSelections();
}

 int FlightModesComponentController::getModeChannel(QString param)
 {
     int channel;
     //return 0 if equal
     if(!param.compare("RC_MAP_ALTCTL_SW")) {
         channel = getParamFact(-1,"RC_MAP_POSCTL_SW")->rawValue().toInt();
         if(channel == 0) {
             channel = getParamFact(-1,"RC_MAP_MODE_SW")->rawValue().toInt();
         }
     }
     else {
         channel = getParamFact(-1,param)->rawValue().toInt();
     }
         return _channelList.lastIndexOf(channel);
 }
