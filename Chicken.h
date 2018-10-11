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
    Chicken(const Chicken &otherChicken);
    Chicken();

    ~Chicken();

    int getId() const;

    int getEggCount() const;

    int getInterval() const;

    void getThreadId();

public slots:
    void doWork_slot();

    void layEgg_slot();

signals:
    void layEgg_signal(const int &value);
};

