#include <QCoreApplication>
#include <QtCore/QThread>
#include <QtCore/QProcess>
#include <QDebug>

#include <iostream>

#include "Farm.h"
#include "Menu.h"
#include "cases.h"

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);
    auto *farm = new Farm;
    auto *menu = new Menu;

    while (true) {
        int input = menu->menuHandler();
        switch (input) {
            case static_cast<int>(Cases::EXIT):
                farm->killAllChickens();
                delete farm;
                delete menu;
                return 0;
            case static_cast<int>(Cases::ADD_CHICKEN):
                std::cout << "Making a chicken" << std::endl;
                farm->addChicken();
                break;
            case static_cast<int>(Cases::KILL_ALL_CHICKEN):
                std::cout << "Killing every chicken" << std::endl;
                farm->killAllChickens();
                break;
            case static_cast<int>(Cases::KILL_CHICKEN):
                std::cout << "Killing a chicken" << std::endl;
                farm->killChicken(menu->getInput());
                break;
            case static_cast<int>(Cases::LIST_CHICKEN):
                QProcess::execute("clear");
                farm->printChicken(menu->getInput());
                break;
            case static_cast<int>(Cases::LIST_ALL_CHICKEN):
                QProcess::execute("clear");
                farm->printAllChickens();
                break;
            case static_cast<int>(Cases::LAY_EGG_NOW):
                farm->layEggNow(menu->getInput());
            default:
                break;
        }
    }
}