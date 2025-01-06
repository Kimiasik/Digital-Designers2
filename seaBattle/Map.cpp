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
	if (newStatus == ' ' || newStatus == '#' || newStatus == 'X' || newStatus == '*') {
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

void Board::start() {
	display();
}
