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
	int livingCells = 20;
public:
	void ShipPlacement(Board &Board);
	void StartGame(Board &playerBoard, Board &botBoard);
	void AutoShipPlacement(Board &Board);
	void SetShip(int x, int y, int size, bool horizontal, Board &board);
	void PlayersTurnAttack(int x, int y, Board &board);
	void botTurnAttack(int x, int y, Board &board);
	void endGame();
};
#endif //SEABATTLE_GAME_H
