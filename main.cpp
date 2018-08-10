#include <QtWidgets>
#include "Chicken.h"
#include "Farm.h"

int main(int argc, char* argv[])
{
    QCoreApplication application(argc,argv);
/*
    Chicken *chicken = new Chicken(0);
    qDebug() <<  "Egg count:" << chicken->getEggCount();
    qDebug() << "Chicken interval:" << chicken->getInterval() << "msec";
*/
    qDebug() << "Let's start!";

    Farm* farm = new Farm;

    farm->addChicken();
    farm->addChicken();
    farm->addChicken();
    farm->addChicken();



    return application.exec();
}