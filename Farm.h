#pragma once

#include <QtCore>
#include "Chicken.h"

class Farm : public QObject
{
    Q_OBJECT
private:
    QMap<int, Chicken*> chickens;
    QMap<int, QThread*> threads;

    int idx=0;

public:
    Farm();
    ~Farm();

    void addChicken();
    void killChicken(int id);
    void showChickens();

signals:
    void doWork();

};


