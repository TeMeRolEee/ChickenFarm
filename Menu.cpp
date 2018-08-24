#include <QDebug>
#include <QtCore/QTextStream>
#include <QtCore/QCoreApplication>

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

Menu::Menu() {

}

Menu::~Menu() {

}

int Menu::menuHandler() {
    helper();
    QString input;
    QTextStream stream(stdin);
    input = stream.readLine().toUpper();

    if (input == "0") {
        qDebug() << "Exiting...";
        return Cases::EXIT;
    } else if (input == "1") {
        qDebug() << "Adding a chicken";
        return Cases::ADDCHICKEN;
    } else if (input == "3") {
        qDebug() << "Killing them ALL!";
        return Cases::KILLALLCHICKEN;
    } else if (input == "2") {
        qDebug() << "Killing a specified chicken";
        return Cases::KILLCHICKEN;
    } else if (input == "5") {
        return Cases::LISTCHICKEN;
    } else if (input == "4") {
        return Cases::LISTALLCHICKEN;
    } else if (input == "6") {
        return Cases::LAYEGGNOW;
    }

    helper();
}

void Menu::helper() {
    qDebug() << "Available commands:";
    qDebug() << "0 > EXIT";
    qDebug() << "1 > Add chicken";
    qDebug() << "2 <ID> > Kill chicken";
    qDebug() << "3 > Kill every chicken";
    qDebug() << "4 > List chickens";
    qDebug() << "5 <ID> > List a specified chicken";
    qDebug() << "6 <ID> > Make a chicken lay an egg";
}


