//
// Created by Kimiast on 13.12.2024.
//

#ifndef SEABATTLE_MAP_H
#define SEABATTLE_MAP_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Cell {
private:
	char status; // ' ' - пусто, '#' - корабель, 'X' - влучання, '*' - промах

public:
	Cell(); // Конструктор

	char getStatus() const;        // Отримати статус клітинки
	void setStatus(char newStatus); // Задати новий статус клітинки
};

// Клас дошки (Board)
class Board {
private:
public:
	Board(); // Конструктор

	void display() const;         // Відобразити поле
	vector<vector<Cell>> grid;		// Поле гри
	static const int size = 10; 	// Розмір дошки
	void start();
};
#endif //SEABATTLE_MAP_H
