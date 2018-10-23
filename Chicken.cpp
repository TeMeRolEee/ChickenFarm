#include "Chicken.h"

#include <QDebug>
#include <QtCore/QThread>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDateTime>
#include <iostream>

Chicken::Chicken(const int &id) : id(id) {
    QRandomGenerator generator;
    auto seedNumber = static_cast<quint32>(QDateTime::currentMSecsSinceEpoch());
    generator.seed(seedNumber);
    interval = generator.bounded(1000, 12500);
    qDebug() << "Chicken added, interval" << (qreal) interval / 1000 << "seconds";
    qDebug() << id << QThread::currentThreadId();
}

Chicken::~Chicken() {
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

    QObject::connect(qTimer, &QTimer::timeout, this, &Chicken::layEgg_slot);
    connect(this, &Chicken::printChicken_signal, this, &Chicken::printChicken_slot);
    connect(this, &Chicken::layEgg_signal, this, &Chicken::layEgg_slot);

    qTimer->start();
}

int Chicken::getInterval() const {
    return interval;
}

void Chicken::layEgg_slot() {
    eggCount++;
    emit printChicken_signal();
}

void Chicken::printChicken_slot() {
        std::cout.flush();
        std::cout << std::endl
                  << QStringLiteral("--- Chicken: [ id: %0, egg count: %1 ] ---").arg(id).arg(eggCount).toStdString()
                  << std::endl;
}

void Chicken::killChicken_slot() {
    qTimer->stop();
}



