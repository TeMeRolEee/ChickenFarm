#include "Farm.h"
#include "Chicken.h"

Farm::Farm() {
}

Farm::~Farm() {
}

void Farm::addChicken(Chicken &chicken) {
    chickens->insert(chickens->size()+1,&chicken);
    chickens->value(chickens->size())->setId(chickens->size());
}

void Farm::killChicken(int id) {
    if(chickens->find(id) != chickens->end())
    {
        chickens->value(id)->kill_slot();
        chickens->remove(id);
        qDebug() << "This chicken will not lay any eggs anymore.";
        qDebug() << "Rest in peace.";
    } else
    {
        qDebug() << "There is no chicken with this particular ID, you might have mistyped it.";
    }

}

void Farm::showChickens() {
    for(auto *item : *chickens)
    {
        qDebug() << "Chicken" << item->getId() << "has" << item->getEggCount() << "eggs.";
    }
}
