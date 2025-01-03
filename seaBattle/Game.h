//
// Created by Kimiast on 30.12.2024.
//

#ifndef SEABATTLE_GAME_H
#define SEABATTLE_GAME_H
#include "Map.h"
class Playing
{
private:
	int WhoseAttack; //чия атака, якщо 0 то гравця номер 1, якщо 1 то гравця номер 2
public:
	void ShipPlacement(Board &board);
	void StartGame();
	void AutoShipPlacement();
	void SetShip(int x, int y, int size, bool horizontal, Board &board);
};
#endif //SEABATTLE_GAME_H
