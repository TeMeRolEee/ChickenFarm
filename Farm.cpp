

#include <QtCore/QRandomGenerator>
#include <QtCore/QDateTime>
#include <QtCore/QThread>
#include <QDebug>
#include "Farm.h"

Farm::Farm() {

}

Farm::~Farm() {
    chickens->clear();
    delete chickens;
}

void Farm::handleEmits(const int &value) {
    qDebug() << "Chicken" << value << "has layed an egg";
}

void Farm::addChicken() {
    Chicken *chicken = new Chicken();
    chickens->push_back(chicken);
    chickenCount++;
}
