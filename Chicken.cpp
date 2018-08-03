#include "Chicken.h"


Chicken::Chicken()
    :eggCount(0)
{
    QRandomGenerator generator;
    QTime seed;
    generator.seed(seed.msec());
    interval = generator.bounded(1000,12500);
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

void Chicken::kill_slot() {
    delete this;
}

void Chicken::layEgg_slot() {
    eggCount++;
}




