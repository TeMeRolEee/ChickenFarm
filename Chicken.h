#pragma once

#include <QtCore>

class Chicken : public QRunnable
{
    Q_OBJECT

private:
    //QThread qThread;
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
    Chicken(int id);
    ~Chicken();

public slots:
    void doWork_slot();
    void kill_slot() const;
    void layEgg_slot();

    void run() override;

signals:

};


