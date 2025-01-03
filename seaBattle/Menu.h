//
// Created by Acer on 16.12.2024.
//

#ifndef SEABATTLE_MENU_H
#define SEABATTLE_MENU_H
#include "Game.h"
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
	Playing playing;

public:
	Application();
	void run();
	void GameMode();
	void ChoiceShipPlacement();
};

#endif //SEABATTLE_MENU_H

