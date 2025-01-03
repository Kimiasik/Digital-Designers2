#include "bot.h"

// Конструктор: ініціалізуємо випадковий генератор
Bot::Bot() : isHunting(false) {
    srand(static_cast<unsigned int>(time(0)));
}

// Метод для створення випадкових координат
std::pair<int, int> Bot::getRandomCell() {
    int x = rand() % 10;
    int y = rand() % 10;
    return {x, y};
}

// Перевіряє, чи координати знаходяться в межах поля
bool Bot::isValidCell(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10;
}

// Метод для здійснення ходу
void Bot::makeMove(Board& enemyBoard) {
    int x, y;

    if (isHunting && !huntTargets.empty()) {
        // Якщо бот добиває, беремо координати з черги
        auto target = huntTargets.back();
        huntTargets.pop_back();
        x = target.first;
        y = target.second;
    } else {
        // Генеруємо випадкові координати, поки не знайдемо невідому клітинку
        do {
            std::pair<int, int> cell = getRandomCell();
            x = cell.first;
            y = cell.second;
        } while (attackedCells.count({x, y}));
    }

    // Атакуємо клітинку
    char cellStatus = enemyBoard.grid[x][y].getStatus(); // Отримуємо статус клітинки

    if (cellStatus == 'O') { // Потрапляння
        std::cout << "Бот влучив у корабель на (" << x << ", " << y << ")." << std::endl;
        enemyBoard.grid[x][y].setStatus('X'); // Помічаємо влучання

        // Додаємо сусідні клітинки до списку добивання
        if (isValidCell(x - 1, y)) huntTargets.push_back({x - 1, y});
        if (isValidCell(x + 1, y)) huntTargets.push_back({x + 1, y});
        if (isValidCell(x, y - 1)) huntTargets.push_back({x, y - 1});
        if (isValidCell(x, y + 1)) huntTargets.push_back({x, y + 1});

        isHunting = true; // Увімкнути режим добивання
    } else if (cellStatus == ' ') { // Промах
        std::cout << "Бот промахнувся на (" << x << ", " << y << ")." << std::endl;
        enemyBoard.grid[x][y].setStatus('*'); // Помічаємо промах
        if (huntTargets.empty()) {
            isHunting = false; // Вийти з режиму добивання
        }
    }

    attackedCells.insert({x, y});
}

// Перевіряє, чи можна розмістити корабель на дошці
bool Bot::canPlaceShip(Board& board, int x, int y, int length, bool horizontal) {
    for (int i = 0; i < length; ++i) {
        if (horizontal) {
            if (!isValidCell(x, y + i) || board.grid[x][y + i].getStatus() != ' ') return false;
        } else {
            if (!isValidCell(x + i, y) || board.grid[x + i][y].getStatus() != ' ') return false;
        }
    }
    return true;
}

// Розміщення кораблів на дошці
void Bot::placeShips(Board& ownBoard) {
    std::vector<int> shipSizes = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};

    for (int size : shipSizes) {
        bool placed = false;
        while (!placed) {
            int x = rand() % 10;
            int y = rand() % 10;
            bool horizontal = rand() % 2;

            if (canPlaceShip(ownBoard, x, y, size, horizontal)) {
                for (int i = 0; i < size; ++i) {
                    if (horizontal) {
                        ownBoard.grid[x][y + i].setStatus('O');
                    } else {
                        ownBoard.grid[x + i][y].setStatus('O');
                    }
                }
                placed = true;
            }
        }
    }
}
