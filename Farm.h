#pragma once

#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QThreadPool>
#include "Chicken.h"

class Farm : public QObject
{
    Q_OBJECT
private:
    QMap<int, Chicken*> chickens;
    QMap<int, QThread*> threads;
    QThreadPool qThreadPool;
    int idx=0;

public:
    Farm();
    ~Farm();
    void addChicken();

public slots:
    void handleEmits(const int &value);
signals:
    void operate(const QString &);
};


