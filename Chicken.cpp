#include "Chicken.h"

#include <QDebug>
#include <QtCore/QThread>

Chicken::Chicken(int id, int interval) :  interval(interval), id(id)
{
    qDebug() << "constructor threadID:" << QThread::currentThreadId();
}

Chicken::~Chicken()
{
    //qTimer.stop();
}

void Chicken::doWork_slot() {
    QTimer qTimer;
    qTimer.setInterval(interval);
    QObject::connect(&qTimer, &QTimer::timeout, this, &Chicken::layEggNow_slot);
    qDebug() << "chicken" << id << "has started laying eggs on thread" << QThread::currentThreadId();
    qTimer.moveToThread(QThread::currentThread());
    qTimer.start();
    qDebug() << "qtimer:" << QThread::currentThreadId();
    while (true)
    {
        if(qTimer.remainingTime() == 0)
        {
            layEggNow_slot();
            qTimer.stop();
            qTimer.start();
        }
        //qDebug() << qTimer.remainingTime() << "working";
    }
}
/*
void Chicken::layEgg_signal(const int &value) {

}*/

int Chicken::getEggCount() const {
    return eggCount;
}

void Chicken::layEggNow_slot() {
    eggCount++;
    //qDebug() << "chicken" << id << "has layed an egg";
    emit layEgg_signal(id);
}

