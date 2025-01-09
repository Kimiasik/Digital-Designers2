//
// Created by Acer on 16.12.2024.
//

#ifndef SEABATTLE_MENU_H
#define SEABATTLE_MENU_H
#include "Game.h"
#include "bot.h"
#include <iostream>

using namespace std;

class Menu {
private:
	PlayingBot playingBot;
	PlayingPlayer playingPlayer;
	Board playerBoard;
	Board botBoard;
	Board playerTwoBoard;
public:
	void displayMenu();
	void GameMode();
	void ChoiceShipPlacement();
	void ChoiceShipPlacementVsPlayer();
};

#endif //SEABATTLE_MENU_H

