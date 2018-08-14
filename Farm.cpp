#include "Farm.h"
#include "Chicken.h"

Farm::Farm() {
}

Farm::~Farm() {
}

void Farm::addChicken() {
    qDebug() << "Number of chickens:" << idx;

    Chicken *chicken = new Chicken(++idx);
    chickens.insert(idx,chicken);

    //QThread *chickenThread = new QThread;
    threads.insert(idx , new QThread);

    chickens.value(idx)->moveToThread(threads.value(idx));
    connect(threads.value(idx), &QThread::finished, chickens.value(idx), &QObject::deleteLater);
    connect(this, &Farm::doWork, chickens.value(idx), &Chicken::doWork_slot);
    threads.value(idx)->start();


    //QObject::connect(&qTimer, &QTimer::timeout, this, &Chicken::layEgg_slot);
    qDebug() << "Number of chickens:" << idx;

}

void Farm::killChicken(int id) {
    /*int temp;
    for(auto *item : *chickens)
    {
        if(item->getId() == id)
        {
            chickens->value(id)->kill_slot();
            chickens->removeAt(temp);
            qDebug() << "This chicken will not lay any eggs anymore.";
            qDebug() << "Rest in peace.";
        }
        else
        {
            qDebug() << "There is no chicken with this particular ID, you might have mistyped it.";
        }
        temp++;
    }*/

    if(chickens.find(id) != chickens.end())
    {
        threads.value(id)->quit();
        threads.value(id)->wait();
        //delete chickens.value(id);
        chickens.remove(id);
        qDebug() << "This chicken will not lay any eggs anymore.";
        qDebug() << "Rest in peace.";
    }
    else
    {
        qDebug() << "There is no chicken with this particular ID, you might have mistyped it.";
    }

}

void Farm::showChickens() {
    for(auto *item : chickens)
    {
        qDebug() << "Chicken" << item->getId() << "has" << item->getEggCount() << "eggs.";
    }
}
