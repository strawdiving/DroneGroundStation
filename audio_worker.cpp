#include "audio_worker.h"

Audio_Worker::Audio_Worker(QObject *parent) :
    QObject(parent)
  ,sound(NULL)
{
    voiceObj = new QAxObject();
}

Audio_Worker::~Audio_Worker()
{

}

void Audio_Worker::beep()
{
  sound->play(":/attitude/BEEP1.WAV");
}

void Audio_Worker::say(QString text)
{
    voiceObj->setControl("sapi.spvoice");
    voiceObj->dynamicCall("Speak(QString,uint)",text,1);
}

