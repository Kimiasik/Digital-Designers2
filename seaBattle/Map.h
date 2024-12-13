//
// Created by Kimiast on 13.12.2024.
//

#ifndef SEABATTLE_MAP_H
#define SEABATTLE_MAP_H
#include <iostream>
#include <vector>
#include <string>
class Cell {
private:
	char status; // ' ' - пусто, 'O' - корабль, 'X' - попадание, '*' - промах

public:
	Cell() : status(' ') {}

	char getStatus() const {
		return status;
	}

	void setStatus(char newStatus) {
		status = newStatus;
	}
};

class Board {
private:
	static const int size = 10;
	std::vector<std::vector<Cell>> grid;

public:
	Board() : grid(size, std::vector<Cell>(size)) {}

	void display() const;

	void placeShip(int x, int y);
};

class Game {
private:
	Board board;

public:
	void start();
};

#endif //SEABATTLE_MAP_H
