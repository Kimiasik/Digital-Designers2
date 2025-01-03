//
// Created by Kimiast on 30.12.2024.
//
#include "Game.h"
#include "iostream"
#include "Map.h"

void Playing::StartGame()
{

}

void Playing::ShipPlacement()
{
	int x, y, size;
	bool horizontal;
	cout << "Введіть координати горизонтальність та ромір корабля(приклад 1, 2, 3, true): " << endl;
	cin >> x, y, size, horizontal;
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