#include <QCoreApplication>
#include <QDebug>
#include <QtCore/QThread>
#include <QtCore/QProcess>
#include "Farm.h"
#include "Menu.h"

enum Cases {
    EXIT,
    ADDCHICKEN,
    KILLCHICKEN,
    KILLALLCHICKEN,
    LISTCHICKEN,
    LISTALLCHICKEN,
    LAYEGGNOW
};

int getInput() {
    qDebug() << "Please give me an ID";
    QTextStream stream(stdin);
    return stream.readLine().toInt();
}

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);/*
    qDebug() << "mainthread" << QThread::currentThreadId();
    Chicken chicken(0);
    qDebug() <<  "Egg count:" << chicken.getEggCount();
    qDebug() << "Chicken interval:" << chicken.getInterval() << "msec";
    Chicken chicken1(1);
    qDebug() <<  "Egg count:" << chicken1.getEggCount();
    qDebug() << "Chicken interval:" << chicken1.getInterval() << "msec";
    qDebug() << "Let's start!";

    Farm *farm = new Farm;

    farm->addChicken();
    QThread::sleep(1);
    farm->addChicken();
    QThread::sleep(1);
    farm->addChicken();
    QThread::sleep(1);
    farm->addChicken();
*/
    Farm *farm = new Farm();
    Menu *menu = new Menu;

    while (true) {
        switch (menu->menuHandler()) {
            case Cases::EXIT:
                farm->killAllChickens();
                return 0;
            case Cases::ADDCHICKEN:
                farm->addChicken();
                break;
            case Cases::KILLALLCHICKEN:
                farm->killAllChickens();
                break;
            case Cases::KILLCHICKEN:
                farm->killChicken(getInput());
                break;
            case Cases::LISTCHICKEN:
                farm->listChicken(getInput());
                break;
            case Cases::LISTALLCHICKEN:
                farm->listAllChickens();
                break;
            case Cases::LAYEGGNOW:
                farm->layEggNow(getInput());
        }
    }
}