//
// Created by Kimiast on 13.12.2024.
//
#include "Map.h"
using namespace std;
Board::Board() : grid(size, vector<Cell>(size)){}
Cell::Cell() : status(' ') {}
char Cell::getStatus() const {
	return status;
}

void Cell::setStatus(char newStatus) {
	if (newStatus == ' ' || newStatus == 'O' || newStatus == 'X' || newStatus == '*') {
		status = newStatus;
	} else {
		cerr << "Invalid status value: " << newStatus << endl;
	}
}

void Board::display() const {
	cout << "   A B C D E F G H I J\n";
	for (int i = 0; i < size; ++i) {
		cout << i + 1;
		if (i + 1 < 10) cout << " ";
		for (int j = 0; j < size; ++j) {
			char cellStatus = grid[i][j].getStatus();
			cout << "|" << (cellStatus == ' ' ? '.' : cellStatus);
		}
		cout << "|\n";
	}
}

void Board::placeShip(int x, int y) {
	if (x >= 0 && x < size && y >= 0 && y < size) {
		grid[x][y].setStatus('O');
	}
}

void Board::attack(int x, int y) {
	if (x >= 0 && x < size && y >= 0 && y < size) {
		if (grid[x][y].getStatus() == 'O') {
			grid[x][y].setStatus('X');
		} else {
			grid[x][y].setStatus('*');
		}
	}
}

void Game::shot() {
	int x, y;
	cout << "Enter coordinates to attack (x y): ";
	cin >> x >> y;
	board.attack(x - 1, y - 1);
}

void Game::start() {
	board.placeShip(0, 0);
	board.placeShip(1, 1);

	for (int i = 0; i < 20; ++i)
	{
		board.display();
		shot();
	}
	board.display();
}
