#pragma once

#include <QtCore/QObject>
#include <QtCore/QTimer>

class Chicken : public QObject {
Q_OBJECT
private:
    int id;
    int interval;
    int eggCount;

public:
    Chicken();

    ~Chicken();

public slots:
signals:

    void layEgg_signal(const int &value);
};

