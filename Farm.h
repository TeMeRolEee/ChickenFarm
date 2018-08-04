#pragma once

#include <QtWidgets>
#include "Chicken.h"

class Farm : public QObject
{
    Q_OBJECT
private:
    QMap<int , Chicken*> *chickens;

public:
    Farm();
    ~Farm();

    void addChicken(Chicken &chicken);
    void killChicken(int id);
    void showChickens();

public slots:

signals:


};


