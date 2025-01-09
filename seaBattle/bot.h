#ifndef OOP_BOT_H
#define OOP_BOT_H

#include "Map.h"
#include <vector>
#include <set>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//Базовий клас для бота
class Bot {
protected:
    int livingCellsPlayer = 20; // К-сть живих клітинок
    set<pair<int, int>> attackedCells; //Набір атакованих клітинок

    // Перевірка доступності координат
    bool isValidCell(int x, int y);
    bool isCellAvailable(Board& board, int x, int y);
    // Отримання випадкової клітинки
    pair<int, int> getRandomCell();

public:
    Bot();
    virtual ~Bot() = default;

    // Метод здійснення ходу
    virtual void makeMove(Board& enemyBoard) = 0;
};

// Легкий бот
class EasyBot : public Bot {
public:
    EasyBot();
    void makeMove(Board& enemyBoard) override;
};

// Середній бот
class MediumBot : public Bot {
private:
    bool isHunting; // Режим добивания
    vector<pair<int, int>> huntTargets; // Черга цілей

public:
    MediumBot();
    void makeMove(Board& enemyBoard) override;
};

// Важкий бот
class HardBot : public MediumBot {
public:
    HardBot();
    void makeMove(Board& enemyBoard) override;
};

#endif // OOP_BOT_H
