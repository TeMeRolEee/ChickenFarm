#include <QtWidgets>
#include "Chicken.h"
#include "Farm.h"

int main(int argc, char* argv[])
{
    QCoreApplication application(argc,argv);
    /*Chicken *chicken = new Chicken();
    chicken->doWork_slot();
    qDebug() <<  "Egg count:" << chicken->getEggCount();
    qDebug() << "Chicken interval:" << chicken->getInterval();
    qDebug() << "Let's start!";
    */
    //chicken->layEgg_slot();
    //Farm* farm = new Farm;

    return application.exec();
}