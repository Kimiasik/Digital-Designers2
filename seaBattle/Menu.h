//
// Created by Acer on 16.12.2024.
//

#ifndef SEABATTLE_MENU_H
#define SEABATTLE_MENU_H
#include "Game.h"
#include <iostream>

using namespace std;

class Menu {
private:
	Playing playing;
public:
	void displayMenu();
	void startGame();
	void GameMode();
	void run();
	void ChoiceShipPlacement();
};
#endif //SEABATTLE_MENU_H

