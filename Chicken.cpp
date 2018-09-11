#include "Chicken.h"

#include <QDebug>
#include <QtCore/QThread>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDateTime>

Chicken::Chicken(const int &id) : id(id) {
    QRandomGenerator generator;
    auto seedNumber = static_cast<quint32>(QDateTime::currentMSecsSinceEpoch());
    generator.seed(seedNumber);
    interval = generator.bounded(1000, 12500);
    qDebug() << "Chicken added, interval" << (qreal) interval / 1000 << "seconds";
    qDebug() << id << QThread::currentThreadId();
}

Chicken::~Chicken() {
    qTimer->stop();
    delete qTimer;
}

int Chicken::getId() const {
    return id;
}

int Chicken::getEggCount() const {
    return eggCount;
}

void Chicken::doWork_slot() {
    qTimer = new QTimer();
    qTimer->setInterval(interval);
    qDebug() << id << QThread::currentThreadId();
    QObject::connect(qTimer, &QTimer::timeout, this, &Chicken::layEgg_slot);
    qTimer->start();
}

int Chicken::getInterval() const {
    return interval;
}

void Chicken::layEgg_slot() {
    eggCount++;
    qDebug() << "Chicken ID:" << id << "Egg count:" << eggCount << " threadID:" << QThread::currentThreadId();
}

void Chicken::getThreadId() {
    qDebug() << "chicken id:" << id << "threadID:" << QThread::currentThreadId();
}


