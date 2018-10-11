#pragma once

#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QThreadPool>
#include "Chicken.h"

class Farm : public QObject {
Q_OBJECT
private:
    QMap<int, Chicken *> chickens;
    QMap<int, QThread *> threads;
    int chickenCount = 0;

    bool findChicken(const int &id);

protected:
    void killChicken(Chicken &chicken);

public:
    void addChicken();

    void killChicken(const int &id);

    void printChicken(const int &id);

    void printAllChickens();

    void layEggNow(const int &id);

    void killAllChickens();

signals:
    void layEgg_signal(const int &id);

    void printChicken_signal(const int &id);
};


