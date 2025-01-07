//
// Created by Kimiast on 30.12.2024.
//

#ifndef SEABATTLE_GAME_H
#define SEABATTLE_GAME_H
#include "Map.h"
class Playing
{
public:
	void ShipPlacement(Board &Board);
	void AutoShipPlacement(Board &Board);
	void SetShip(int x, int y, int size, bool horizontal, Board &board);
	void PlayersTurnAttack(int x, int y, Board &board, int &livingCells);
	void endGame();
};

class PlayingBot : public Playing
{
private:
	int livingCellsPlayer = 20;
	int livingCellsBot = 20;
public:
	void StartGameVsBot(Board &playerBoard, Board &botBoard);
	void botTurnAttack(Board &board);
};

class PlayingPlayer : public Playing
{
private:
	int livingCellsPlayerOne = 20;
	int livingCellsPlayerTwo = 20;
public:
	void startGameVsPlayer(Board &playerBoard, Board &playerTwoBoard);
};
#endif //SEABATTLE_GAME_H
