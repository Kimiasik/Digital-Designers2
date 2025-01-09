#include "bot.h"
using namespace std;

// Базовий бот
Bot::Bot() {
    srand(static_cast<unsigned int>(time(0)));
}

pair<int, int> Bot::getRandomCell() {
    int x = rand() % 10;
    int y = rand() % 10;
    return {x, y};
}

bool Bot::isValidCell(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10;
}

bool Bot::isCellAvailable(Board& board, int x, int y) {
    // Перевіряємо, чи не атакована клітинка раніше
    char cellStatus = board.grid[x][y].getStatus();
    return cellStatus != 'X' && cellStatus != '*';
}

// Легкий бот
EasyBot::EasyBot() : Bot() {}

void EasyBot::makeMove(Board& enemyBoard) {
    int x, y;

    do {
        // Генерація випадкового хода
        pair<int, int> cell = getRandomCell();
        x = cell.first;
        y = cell.second;
    } while (attackedCells.count({x, y}) || !isCellAvailable(enemyBoard, x, y));

    // Перевірка статусу клітинки
    char cellStatus = enemyBoard.grid[x][y].getStatus();
    if (cellStatus == '#') { // Влучання
        cout << "EasyBot влучив у корабель на (" << x+1 << ", " << y+1 << ")." << endl;
        enemyBoard.grid[x][y].setStatus('X');
        livingCellsPlayer--;
    } else { // Промах
        cout << "EasyBot промахнувся на (" << x+1 << ", " << y+1 << ")." << endl;
        enemyBoard.grid[x][y].setStatus('*');
    }

    attackedCells.insert({x, y});
}

// Середній бот
MediumBot::MediumBot() : Bot(), isHunting(false) {}

void MediumBot::makeMove(Board& enemyBoard) {
    int x, y;

    if (isHunting && !huntTargets.empty()) {
        auto target = huntTargets.back();
        huntTargets.pop_back();
        x = target.first;
        y = target.second;

        // Якщо клітинка вже підбита чи по неї промахнулися, шукаємо наступну
        if (!isCellAvailable(enemyBoard, x, y)) {
            makeMove(enemyBoard);
            return;
        }
    } else {
        do {
            pair<int, int> cell = getRandomCell();
            x = cell.first;
            y = cell.second;
        } while (attackedCells.count({x, y}) || !isCellAvailable(enemyBoard, x, y));
    }

    char cellStatus = enemyBoard.grid[x][y].getStatus();
    if (cellStatus == '#') {
        cout << "MediumBot влучив у корабель на  (" << x+1 << ", " << y+1 << ")." << endl;
        enemyBoard.grid[x][y].setStatus('X');
        livingCellsPlayer--;

        if (isValidCell(x - 1, y) && isCellAvailable(enemyBoard, x - 1, y)) huntTargets.push_back({x - 1, y});
        if (isValidCell(x + 1, y) && isCellAvailable(enemyBoard, x + 1, y)) huntTargets.push_back({x + 1, y});
        if (isValidCell(x, y - 1) && isCellAvailable(enemyBoard, x, y - 1)) huntTargets.push_back({x, y - 1});
        if (isValidCell(x, y + 1) && isCellAvailable(enemyBoard, x, y + 1)) huntTargets.push_back({x, y + 1});

        isHunting = true;
    } else {
        cout << "MediumBot промахнувся на (" << x+1 << ", " << y+1 << ")." << endl;
        enemyBoard.grid[x][y].setStatus('*');
        if (huntTargets.empty()) {
            isHunting = false;
        }
    }

    attackedCells.insert({x, y});
}

// Важкий бот
HardBot::HardBot() : MediumBot() {}

void HardBot::makeMove(Board& enemyBoard) {
    // Використовуємо шахматний алгоритм для пошуку
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            if ((x + y) % 2 == 0 && !attackedCells.count({x, y}) && isCellAvailable(enemyBoard, x, y)) {
                char cellStatus = enemyBoard.grid[x][y].getStatus();
                if (cellStatus == '#') {
                    cout << "HardBot влучив у корабель на (" << x+1 << ", " << y+1 << ")." << endl;
                    enemyBoard.grid[x][y].setStatus('X');
                    livingCellsPlayer--;
                } else {
                    cout << "HardBot промахнувся на (" << x+1 << ", " << y+1 << ")." << endl;
                    enemyBoard.grid[x][y].setStatus('*');
                }

                attackedCells.insert({x, y});
                return;
            }
        }
    }

    // Якщо всі клітинки по шаблону вже використані, то використовуємо логіку середнього бота
    MediumBot::makeMove(enemyBoard);
}



