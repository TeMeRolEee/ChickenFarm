

#include <QtCore/QRandomGenerator>
#include <QtCore/QDateTime>
#include <QtCore/QThread>
#include <QDebug>
#include "Farm.h"

Farm::Farm() {

}

Farm::~Farm() {

}

void Farm::handleEmits(const int &value) {
    qDebug() << "Chicken" << value << "has layed an egg";
}

void Farm::addChicken() {
    QRandomGenerator generator;
    QDateTime seed;
    quint32 seedNumber = static_cast<quint32>(seed.currentMSecsSinceEpoch());
    generator.seed(seedNumber);
    qDebug() << seedNumber;
    int interval = generator.bounded(1000,12500);
    qDebug() << "Farm thread ID:" << QThread::currentThreadId();

    Chicken *chicken = new Chicken(++idx,interval);
    qDebug() << "Chicken" << idx <<" added, interval" <<  (qreal)interval/1000 << "seconds";
    chickens.insert(idx, chicken);

    threads.insert(idx, new QThread);

    chickens.value(idx)->moveToThread(threads.value(idx));

    threads.value(idx)->start();
    connect(threads.value(idx), &QThread::finished, chickens.value(idx), &QObject::deleteLater);
    connect(threads.value(idx), &QThread::started, chickens.value(idx), &Chicken::doWork_slot);
    connect(chickens.value(idx), &Chicken::layEgg_signal, this, &Farm::handleEmits);
    //connect(chickens.value(idx), &Chicken::layEgg_signal, chickens.value(idx), &Chicken::doWork_slot);

    qDebug() << threads.value(idx)->isRunning();
    //chickens.value(idx)->layEggNow_slot();
    //chickens.value(idx)->doWork_slot();

}
