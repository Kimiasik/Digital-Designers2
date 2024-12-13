#include "bot.h"
#include <iostream>

// Конструктор, ініціалізуємо генератор випадкових чисел
Bot::Bot() : isHunting(false) {
    srand(static_cast<unsigned int>(time(0)));
}

// Метод для створення випадкових координат
pair<int, int> Bot::getRandomCell() {
    int x = rand() % 10;
    int y = rand() % 10;
    return {x, y};
}

// Перевірка на те, чи знаходяться координати в межах поля
bool Bot::isValidCell(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10;
}

// Метод для здійснення ходу
void Bot::makeMove(Map& enemyBoard) {
    int x, y;

    if (isHunting && !huntTargets.empty()) {
        //Якщо перебуває в режимі добивання, беремо клітку з черги
        auto target = huntTargets.back();
        huntTargets.pop_back();
        x = target.first;
        y = target.second;
    } else {
        // Шукаємо випадкову клітку, яку ще не атакували
        do {
            std::pair<int, int> cell = getRandomCell();
            int x = cell.first;
            int y = cell.second;
        } while (attackedCells.find({x, y}) != attackedCells.end());
    }

    attackedCells.insert({x, y}); // Додаємо клітину до атакованих

    if (enemyBoard.attack(x, y)) {
        cout << "Бот потрапив у корабель на координатах: " << x << ", " << y << std::endl;

        // Додаємо сусідні клітини до списку для добивання
        if (isValidCell(x - 1, y)) huntTargets.push_back({x - 1, y}); // Вгору
        if (isValidCell(x + 1, y)) huntTargets.push_back({x + 1, y}); // Вниз
        if (isValidCell(x, y - 1)) huntTargets.push_back({x, y - 1}); // Ліворуч
        if (isValidCell(x, y + 1)) huntTargets.push_back({x, y + 1}); // Праворуч

        isHunting = true; // Встановлюємо режим добивання
    } else {
        cout << "Бот промахнувся за координатами: " << x << ", " << y << std::endl;

        // Якщо більше немає цілей добивання, повертаємося до випадкового пошуку
        if (huntTargets.empty()) {
            isHunting = false;
        }
    }
}

// Перевірка, чи можна розмістити корабель у вказаній позиції
bool Bot::canPlaceShip(Map& board, int x, int y, int length, bool horizontal) {
    for (int i = 0; i < length; ++i) {
        if (horizontal) {
            if (!isValidCell(x, y + i) || board.isOccupied(x, y + i)) return false;
        } else {
            if (!isValidCell(x + i, y) || board.isOccupied(x + i, y)) return false;
        }
    }
    return true;
}

// Розміщення кораблів на дошці
void Bot::placeShips(Map& ownBoard) {
    vector<int> shipSizes = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1}; // Розміри кораблів

    for (int size : shipSizes) {
        bool placed = false;
        while (!placed) {
            int x = rand() % 10;
            int y = rand() % 10;
            bool horizontal = rand() % 2;

            if (canPlaceShip(ownBoard, x, y, size, horizontal)) {
                for (int i = 0; i < size; ++i) {
                    if (horizontal) {
                        ownBoard.placeShip(x, y + i); // Розміщуємо горизонтально
                    } else {
                        ownBoard.placeShip(x + i, y); // Розміщуємо вертикально
                    }
                }
                placed = true;
            }
        }
    }
}