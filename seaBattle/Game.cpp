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

void Playing::AutoShipPlacement(Board &board)
{
    const int shipSizes[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    const int numShips = sizeof(shipSizes) / sizeof(shipSizes[0]);

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < numShips; ++i) {
        bool placed = false;

        while (!placed) {
            int x = rand() % board.size;
            int y = rand() % board.size;
            bool horizontal = rand() % 2 == 0;

            bool canPlace = true;

            for (int j = 0; j < shipSizes[i]; ++j) {
                int nx = x + (horizontal ? 0 : j);
                int ny = y + (horizontal ? j : 0);

                if (nx < 0 || nx >= board.size || ny < 0 || ny >= board.size) {
                    canPlace = false;
                    break;
                }

                if (board.grid[nx][ny].getStatus() == '#') {
                    canPlace = false;
                    break;
                }

                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int adjX = nx + dx;
                        int adjY = ny + dy;
                        if (adjX >= 0 && adjX < board.size && adjY >= 0 && adjY < board.size) {
                            if (board.grid[adjX][adjY].getStatus() == '#') {
                                canPlace = false;
                                break;
                            }
                        }
                    }
                    if (!canPlace) break;
                }
                if (!canPlace) break;
            }

            if (canPlace) {
                SetShip(x, y, shipSizes[i], horizontal, board);
                placed = true;
            }
        }
    }
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