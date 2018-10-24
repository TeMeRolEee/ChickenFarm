#include <QtCore/QRandomGenerator>
#include <QtCore/QDateTime>
#include <QtCore/QThread>
#include <QDebug>
#include <iostream>
#include "Farm.h"

void Farm::addChicken() {
    auto *chicken = new Chicken(chickenCount);
    chickens.insert(chickenCount, chicken);

    auto *qThread = new QThread();
    threads.insert(chickenCount, qThread);

    chickens.value(chickenCount)->moveToThread(threads.value(chickenCount));

    connect(qThread, &QThread::started, chicken, &Chicken::doWork_slot);

    connect(qThread, &QThread::finished, chicken, &Chicken::killChicken_slot);

    threads.value(chickenCount)->start();

    chickenCount++;
}

void Farm::killChicken(const int &id) {
    if (findChicken(id)) {
        killChicken(*chickens.value(id));
    } else {
        std::cout << "No such chicken in this farm. Try killing an other one." << std::endl;
    }
}

void Farm::killChicken(Chicken &chicken) {
    int id = chicken.getId();

    threads[id]->quit();
    threads[id]->wait();

    delete chickens.take(id);
    delete threads.take(id);
}

void Farm::printChicken(const int &id) {
    if (findChicken(id)) {
        emit chickens.value(id)->printChicken_signal();
    }
}

void Farm::printAllChickens() {
    std::cout << "Number of chickens alive is: " << chickens.size() << std::endl;

    for (auto id : chickens.keys()) {
        printChicken(id);
    }
}

void Farm::layEggNow(const int &id) {
	if (findChicken(id)) {
		emit chickens.value(id)->layEgg_signal();
	} else {
		std::cout << "Error, couldn't find the specified chicken" << std::endl;
	}
}

void Farm::killAllChickens() {
    for (auto id : chickens.keys()) {
        killChicken(*chickens.value(id));
    }
}

bool Farm::findChicken(const int &id) {
    return chickens.find(id) != chickens.end();
}


