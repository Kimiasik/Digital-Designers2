//
// Created by Acer on 16.12.2024.
//

#ifndef SEABATTLE_MENU_H
#define SEABATTLE_MENU_H

#include <iostream>

using namespace std;

class Menu {
public:
	void displayMenu();
};

class GameMenu {
public:
	void startGame();
};

class Application {
private:
	Menu menu;
	GameMenu game;
	bool running;

public:
	Application();
	void run();
};

#endif //SEABATTLE_MENU_H

