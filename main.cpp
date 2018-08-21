#include <QCoreApplication>
#include <QDebug>
#include <QtCore/QThread>
#include "Farm.h"

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);/*
    qDebug() << "mainthread" << QThread::currentThreadId();
    Chicken chicken(0);
    qDebug() <<  "Egg count:" << chicken.getEggCount();
    qDebug() << "Chicken interval:" << chicken.getInterval() << "msec";
    Chicken chicken1(1);
    qDebug() <<  "Egg count:" << chicken1.getEggCount();
    qDebug() << "Chicken interval:" << chicken1.getInterval() << "msec";*/
    qDebug() << "Let's start!";

    Farm *farm = new Farm;

    farm->addChicken();
    QThread::sleep(1);
    farm->addChicken();
    QThread::sleep(1);
    farm->addChicken();
    QThread::sleep(1);
    farm->addChicken();
/*
    farm->getChicken(0);
    farm->getChicken(1);
    farm->getChicken(2);
    farm->getChicken(3);
*/

    return application.exec();
}