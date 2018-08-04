#pragma once

#include <QtCore>

class Chicken : public QObject
{
    Q_OBJECT
private:
    QThread qThread;
    bool stopper= false;
    int interval;
    QTimer qTimer;
    int id;
public:
    int getId() const;

    void setId(int id);

public:
    int getInterval() const;

    int getEggCount() const;


private:
    int eggCount;
public:
    Chicken();
    ~Chicken();

public slots:
    void doWork_slot();
    void kill_slot() const;
    void layEgg_slot();
signals:
    //void
};


