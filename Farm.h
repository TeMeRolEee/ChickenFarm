#pragma once

#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QThreadPool>
#include "Chicken.h"

class Farm : public QObject {
Q_OBJECT
private:
    QList<Chicken *> *chickens;
    int chickenCount;
public:
    Farm();

    ~Farm();

    void addChicken();

public slots:

    void handleEmits(const int &value);

signals:

    void operate(const QString &);
};


