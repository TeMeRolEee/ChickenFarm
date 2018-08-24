#include <QtCore/QRandomGenerator>
#include <QtCore/QDateTime>
#include <QtCore/QThread>
#include <QDebug>
#include "Farm.h"

Farm::Farm() {

}

Farm::~Farm() {
}

void Farm::handleEmits_slot(const int &value) {
    qDebug() << "Chicken" << value << "has layed an egg";
}

void Farm::addChicken() {
    Chicken *chicken = new Chicken(chickenCount);
    chickens.insert(chickenCount, chicken);

    QThread *qThread = new QThread();
    threads.insert(chickenCount, qThread);

    chickens.value(chickenCount)->moveToThread(threads.value(chickenCount));

    connect(threads.value(chickenCount), &QThread::finished, chickens.value(chickenCount), &QObject::deleteLater);
    connect(this, &Farm::operate_signal, chickens.value(chickenCount), &Chicken::doWork_slot);
    connect(threads.value(chickenCount), &QThread::started, chickens.value(chickenCount), &Chicken::doWork_slot);
    threads.value(chickenCount)->start();

    chickenCount++;
}

void Farm::killChicken(const int &id) {
        threads[id]->quit();
        threads[id]->wait();
        delete threads[id];
        threads.remove(id);

        delete chickens[id];
        chickens.remove(id);
}

void Farm::listChicken(const int &id) {
    qDebug() << "Chicken ID:" << chickens.value(id)->getId() << "eggcount:" << chickens.value(id)->getEggCount()
             << "interval:" << chickens.value(id)->getInterval();
}

void Farm::listAllChickens() {
    for (auto item : chickens.keys()) {
        listChicken(item);
    }
}

void Farm::layEggNow(const int &id) {
    chickens.value(id)->layEgg_slot();
}

void Farm::killAllChickens() {
    for (auto item : chickens.keys()) {
        killChicken(item);
    }
}


