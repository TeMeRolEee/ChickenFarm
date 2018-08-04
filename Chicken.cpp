#include "Chicken.h"


Chicken::Chicken()
    :eggCount(0)
{
    QRandomGenerator generator;
    QDateTime seed;
    quint32 seedNumber = static_cast<quint32>(seed.currentMSecsSinceEpoch());
    generator.seed(seedNumber);
    qDebug() << seedNumber;
    interval = generator.bounded(1000,12500);
    qDebug() << "Chicken added, interval" <<  (qreal)interval/1000 << "seconds";
}

void Chicken::doWork_slot() {
    qThread.start();
    QObject::connect(&qTimer, &QTimer::timeout, this, &Chicken::layEgg_slot);
    qTimer.setInterval(interval);
    qTimer.start();
}

Chicken::~Chicken() {
    qTimer.stop();
    qThread.quit();
    qThread.wait();
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




