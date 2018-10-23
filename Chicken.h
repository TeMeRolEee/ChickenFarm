#pragma once

#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QtCore/QThread>

class Chicken : public QObject {
Q_OBJECT

private:
    int id;
    int interval;
    int eggCount = 0;
    QTimer *qTimer;

public:
    Chicken(const int &id);

    ~Chicken();

    int getId() const;

    int getEggCount() const;

    int getInterval() const;

public slots:

    void doWork_slot();

    void layEgg_slot();

    void printChicken_slot();

    void killChicken_slot();

signals:
    void printChicken_signal();

    void layEgg_signal();

};

