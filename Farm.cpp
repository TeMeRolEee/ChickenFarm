#include "Farm.h"
#include "Chicken.h"

Farm::Farm() {
}

Farm::~Farm() {
}

void Farm::addChicken() {
    //Chicken *chicken = ;
    qDebug() << "Number of chickens:" << size;

    Chicken chicken(++size);

    chickens.insert(size,&chicken);
    qThreadPool.globalInstance()->start(chickens.value(size));
    //threads.insert(size , qThread);
    //chickens.value(size)->moveToThread(threads.value(size));

    //chickens.value(size)->doWork_slot();

    //Chicken chicken(++size);
    //chickens->insert(size, chicken);
    //chickens->value(size);

    qDebug() << "Number of chickens:" << size;

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
        chickens.value(id)->kill_slot();
        delete chickens.value(id);
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
