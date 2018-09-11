#include <QtCore/QRandomGenerator>
#include <QtCore/QDateTime>
#include <QtCore/QThread>
#include <QDebug>
#include "Farm.h"

void Farm::addChicken() {
    auto *chicken = new Chicken(chickenCount);
    chickens.insert(chickenCount, chicken);

    auto *qThread = new QThread();
    threads.insert(chickenCount, qThread);

    chickens.value(chickenCount)->moveToThread(threads.value(chickenCount));
    connect(this, &Farm::layEgg_signal, chicken, &Chicken::layEgg_slot);
    connect(qThread, &QThread::started, chicken, &Chicken::doWork_slot);
    threads.value(chickenCount)->start();

    chickenCount++;
}

void Farm::killChicken(const int &id) {
    if (findChicken(id)) {
        killChicken(chickens.value(id));
    } else {
        qDebug() << "No such chicken in this farm. Try killing an other one.";
    }
}

void Farm::killChicken(Chicken *chicken) {
    int id = chicken->getId();
    threads[id]->quit();
    threads[id]->wait();

    delete chickens.take(id);
    delete threads.take(id);
}

void Farm::printChicken(const int &id) {
    if (findChicken(id)) {
        printChicken(chickens.value(id));
    }
}

void Farm::printChicken(Chicken *chicken) {
    qDebug() << "Chicken ID:" << chicken->getId() << "eggcount:" << chicken->getEggCount()
             << "interval:" << chicken->getInterval();
}

void Farm::printAllChickens() {
    for (auto *chicken : chickens) {
        printChicken(chicken);
    }
}

void Farm::layEggNow(const int &id) {
    emit layEgg_signal();
}

void Farm::killAllChickens() {
    for (auto *chicken : chickens) {
        killChicken(chicken);
    }
}

bool Farm::findChicken(const int &id) {
    return chickens.find(id) != chickens.end();
}


