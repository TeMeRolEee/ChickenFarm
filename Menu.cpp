#include <QDebug>
#include <QtCore/QTextStream>
#include <QtCore/QCoreApplication>

#include "Menu.h"
#include "cases.h"

int Menu::menuHandler() {
    printMenu();
    return getInput();
}

void Menu::printMenu() {
    qDebug() << "Available commands:";
    qDebug() << "0 > EXIT";
    qDebug() << "1 > Add chicken";
    qDebug() << "2 <ID> > Kill chicken";
    qDebug() << "3 > Kill every chicken";
    qDebug() << "4 > List chickens";
    qDebug() << "5 <ID> > List a specified chicken";
    qDebug() << "6 <ID> > Make a chicken lay an egg";
}

int Menu::getInput() {
    return QTextStream(stdin).readLine().toInt();
}


