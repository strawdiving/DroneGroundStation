#ifndef AUDIO_WORKER_H
#define AUDIO_WORKER_H

#include <QObject>
#include <QSound>
#include<ActiveQt/QAxObject>

class Audio_Worker : public QObject
{
    Q_OBJECT
public:
    explicit Audio_Worker(QObject *parent = 0);
    ~Audio_Worker();
    /** @brief Sound a single beep */
    void beep();
    void say(QString text);

signals:

public slots:

protected:
    QSound *sound;
    mutable QAxObject *voiceObj;
};

#endif // AUDIO_WORKER_H
