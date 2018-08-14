#pragma once

#include <QtCore>

class Chicken : public QObject
{
    Q_OBJECT
private:
    int interval;
    QTimer qTimer;
    int id;
    int eggCount;

public:
    Chicken(int id);
    ~Chicken();

    int getId() const;
    void setId(int id);
    int getInterval() const;
    int getEggCount() const;

public slots:
    void doWork_slot();
    void kill_slot() const;
    void layEgg_slot();
    void layEggNow_slot();
signals:
    void layEgg_signal(const int &value);

};


