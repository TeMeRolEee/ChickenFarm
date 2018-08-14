#include "Chicken.h"


Chicken::Chicken(int id)
    :eggCount(0)
{
    setId(id);
    QRandomGenerator generator;
    QDateTime seed;
    quint32 seedNumber = static_cast<quint32>(seed.currentMSecsSinceEpoch()) + id*100;
    generator.seed(seedNumber);
    qDebug() << seedNumber;
    interval = generator.bounded(1000,12500);
    qDebug() << "Chicken added, interval" <<  (qreal)interval/1000 << "seconds";
    //moveToThread(&qThread);
    /*qTimer.setInterval(interval);
    qTimer.start();
    //connect(&qThread, SIGNAL(started()), this, SLOT(doWork_slot()));
    qThread.start();*/
    qTimer.setInterval(interval);
}

void Chicken::doWork_slot() {
    qDebug() << "ChickenId:" << id << "threadID:" << QThread::currentThreadId();

    QObject::connect(&qTimer, &QTimer::timeout, this, &Chicken::layEgg_slot);
    qTimer.start();
}

Chicken::~Chicken() {
    qTimer.stop();
}

int Chicken::getInterval() const {
    return interval;
}

int Chicken::getEggCount() const {
    return eggCount;
}

void Chicken::kill_slot() const {
    delete this;
}

void Chicken::layEgg_slot() {
    qDebug() << "Chicken " << id << "layed an egg.";
    eggCount++;
    qDebug() << "Number of eggs:" << getEggCount();

}

int Chicken::getId() const {
    return id;
}

void Chicken::setId(int id) {
    Chicken::id = id;
}






