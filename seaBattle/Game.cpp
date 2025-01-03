//
// Created by Kimiast on 30.12.2024.
//
#include "Game.h"
#include "iostream"
#include "Map.h"

void Playing::StartGame()
{

}

void Playing::ShipPlacement(Board &board)
{
	int x, y, size;
	int h;
	bool horizontal;
	cout << "Введіть координати горизонтальність та ромір корабля(приклад 1, 2, 3, 0 - false 1-true): " << endl;
	cout << "Enter x" << endl;
	cin >> x;
	cout << "Enter y" << endl;
	cin >> y;
	cout << "enter size" << endl;
	cin >> size;
	cout << "Введіть горизонтальність корабля" << endl;
	cin >> h;
	if(h == 1)
		horizontal = true;
	if(h == 0)
		horizontal = false;
	SetShip(x, y, size, horizontal, board);
}

void Playing::AutoShipPlacement()
{

}

void Playing::SetShip(int x, int y, int size, bool horizontal, Board &board) {
	for (int i = 0; i < size; ++i) {
		int nx = x + (horizontal ? 0 : i);
		int ny = y + (horizontal ? i : 0);

		if (nx < 0 || nx >= board.size || ny < 0 || ny >= board.size) {
			cerr << "Error: Ship placement is out of bounds." << endl;
			return;
		}

		// Перевірка на перекриття з іншими кораблями
		if (board.grid[nx][ny].getStatus() == '#') {
			cerr << "Error: Ship placement overlaps with another ship." << endl;
			return;
		}
	}

	// Розміщення корабля
	for (int i = 0; i < size; ++i) {
		int nx = x + (horizontal ? 0 : i);
		int ny = y + (horizontal ? i : 0);

		board.grid[nx][ny].setStatus('#');
	}
}