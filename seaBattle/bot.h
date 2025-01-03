#ifndef OOP_BOT_H
#define OOP_BOT_H

#include "Map.h"
#include <vector>
#include <set>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Bot {
private:
    bool isHunting; // Прапор, що вказує на пошук сусідніх клітин після влучення
    std::vector<std::pair<int, int>> huntTargets; // Черга для добивання
    std::set<std::pair<int, int>> attackedCells; // Набір для зберігання атакованих клітин

    std::pair<int, int> getRandomCell(); // Метод для випадкового вибору клітини
    bool isValidCell(int x, int y); // Метод для перевірки, чи не виходять координати за межі
    bool canPlaceShip(Board& board, int x, int y, int length, bool horizontal); // Метод для перевірки, чи можна розмістити корабель

public:
    Bot(); // Конструктор
    void makeMove(Board& enemyBoard); // Метод, що здійснює хід
    void placeShips(Board& ownBoard); // Метод для розміщення кораблів на дошці
};

#endif //OOP_BOT_H
