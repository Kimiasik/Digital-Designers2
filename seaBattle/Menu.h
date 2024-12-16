//
// Created by Acer on 16.12.2024.
//

#ifndef SEABATTLE_MENU_H
#define SEABATTLE_MENU_H

#endif //SEABATTLE_MENU_H

#include <iostream>
using namespace std;

namespace std {

    class Menu {
    public:
        void displayMenu();
    };

    class Game {
    public:
        void startGame();
    };

    class Application {
    private:
        Menu menu;
        Game game;
        bool running;

    public:
        Application();
        void run();
    };
}