#pragma once

#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QThreadPool>
#include "Chicken.h"

class Farm : public QObject {
Q_OBJECT
private:
    QMap<int, Chicken*> chickens;
    QMap<int, QThread*> threads;
    int chickenCount = 0;

public:
    Farm();
    ~Farm();

    void addChicken();
    void killChicken(const int &id);
    void listChicken(const int &id);
    void listAllChickens();
    void layEggNow(const int &id);
    void killAllChickens();

public slots:

    void handleEmits_slot(const int &value);

signals:

    void operate_signal();
    void stopChicken_signal();
};


