#pragma once

#include <QtCore/QObject>
#include <QtCore/QTimer>

class Chicken : public QObject
{
    Q_OBJECT
private:
    int id;
    int interval;

    int eggCount;

public:
    Chicken(int id, int interval);
    ~Chicken();
    void emitEggLayed();
    int getEggCount() const;

public slots:
    void doWork_slot();
    void layEggNow_slot();

signals:
    void layEgg_signal(const int &value);
};

