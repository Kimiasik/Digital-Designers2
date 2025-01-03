//
// Created by Kimiast on 30.12.2024.
//

#ifndef SEABATTLE_GAME_H
#define SEABATTLE_GAME_H
class Playing
{
private:
	int WhoseAttack; //чия атака, якщо 0 то гравця номер 1, якщо 1 то гравця номер 2
public:
	void ShipPlacement();
	void StartGame();
	void AutoShipPlacement();
};
#endif //SEABATTLE_GAME_H
