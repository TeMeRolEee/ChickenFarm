#pragma once

#include <QtWidgets>
#include "Chicken.h"

class Farm : public QObject
{
    Q_OBJECT
private:
    QMap<int, Chicken*> chickens;
    QThreadPool qThreadPool;
    int size=0;

public:
    Farm();
    ~Farm();

    void addChicken();
    void killChicken(int id);
    void showChickens();

public slots:

signals:


};


