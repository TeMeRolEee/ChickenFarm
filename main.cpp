#include <QtWidgets>
#include "Chicken.h"
#include "Farm.h"

int main(int argc, char* argv[])
{
    QCoreApplication application(argc,argv);
    //Chicken *chicken = new Chicken(1);
    qDebug() << "Let's start!";

    Farm* farm = new Farm;

    return application.exec();
}