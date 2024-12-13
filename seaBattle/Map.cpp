//
// Created by Kimiast on 13.12.2024.
//
#include "Map.h"
void Board :: display() const
{
	std::cout << "  A B C D E F G H I J\n";
	for (int i = 0; i < size; ++i) {
		std::cout << i + 1;
		if (i + 1 < 10) std::cout << " "; // Выравнивание для однозначных чисел

		for (int j = 0; j < size; ++j) {
			std::cout << "|" << grid[i][j].getStatus();
		}
		std::cout << "|\n";
	}
}

void Board :: placeShip(int x, int y)
{
		if (x >= 0 && x < size && y >= 0 && y < size) {
			grid[x][y].setStatus('O');
		}
}
void Game :: start()
{
	{
		board.display();
	}
}