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
	char status; // ' ' - пусто, 'O' - корабель, 'X' - влучання, '*' - промах

public:
	Cell(); // Конструктор

	char getStatus() const;        // Отримати статус клітинки
	void setStatus(char newStatus); // Задати новий статус клітинки
};

// Клас дошки (Board)
class Board {
private:
	static const int size = 10; // Розмір дошки
    // Поле гри

public:
	Board(); // Конструктор

	void display() const;         // Відобразити поле
	void placeShip(int x, int y); // Розмістити корабель
	char attack(int x, int y);    // Атакувати координати
    vector<vector<Cell>> grid;
};

// Клас гри (Game)
class Game {
private:
	Board board; // Поле гри

public:
	void shot();  // Здійснити постріл
	void start(); // Почати гру
};

#endif //SEABATTLE_MAP_H
