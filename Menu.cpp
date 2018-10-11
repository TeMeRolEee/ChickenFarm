#include <QDebug>
#include <QtCore/QTextStream>
#include <QtCore/QCoreApplication>
#include <iostream>

#include "Menu.h"
#include "cases.h"

int Menu::menuHandler() {
    printMenu();
    return getInput();
}

void Menu::printMenu() {
    std::cout.flush();
    std::cout << "Available commands:" << std::endl
    << "0 > EXIT" << std::endl
    << "1 > Add chicken" << std::endl
    << "2 <ID> > Kill chicken" << std::endl
    << "3 > Kill every chicken" << std::endl
    << "4 > List chickens" << std::endl
    << "5 <ID> > List a specified chicken" << std::endl
    << "6 <ID> > Make a chicken lay an egg" << std::endl;

}

int Menu::getInput() {
    QTextStream stream(stdin);
    QString inputString = stream.readLine();
    while(inputString == "") {
        inputString = stream.readLine();
    }
    QRegExp regExp("\\d*");
    if (regExp.exactMatch(inputString)) {
        return inputString.toInt();
    }

    return -1;
}


