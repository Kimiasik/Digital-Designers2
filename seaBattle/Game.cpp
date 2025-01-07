//
// Created by Kimiast on 30.12.2024.
//
#include "Game.h"
#include "iostream"
#include "Map.h"

void Playing::endGame()
{
}

void Playing::PlayersTurnAttack(int x, int y, Board &botBoard, int &livingCells)
{
	if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
	{
		if (botBoard.grid[x][y].getStatus() == '#') {
			botBoard.grid[x][y].setStatus('X');
			cout << "Попадання!" << endl;
			livingCells--;
		}
		else {
			cout << "Не попав((((" << endl;
			botBoard.grid[x][y].setStatus('*');
		}
	}
}

void PlayingBot::botTurnAttack(Board &playerBoard)
{
	int x, y;
	x = 0 + rand() % 10;
	y = 0 + rand() % 10;
	if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
	{
		if (playerBoard.grid[x][y].getStatus() == '#') {
			playerBoard.grid[x][y].setStatus('X');
			cout << "Попадання!" << endl;
			livingCellsPlayer--;
		}
		else {
			cout << "Не попав((((" << endl;
			playerBoard.grid[x][y].setStatus('*');
		}
	}
}

void PlayingBot::StartGameVsBot(Board &playerBoard, Board &botBoard) {
	int x, y;
	cout << "Поля гравців створені, гра починається!" << endl;
	cout << "Перший хід за гравцем!" << endl;
	while (livingCellsPlayer && livingCellsBot) {
		endGame();
		cout << "Введіть координати для атаки(x, y):" << endl;
		cin >> x;
		cin >> y;
		PlayersTurnAttack(x - 1, y - 1, botBoard, livingCellsBot);
		cout << "Атака Бота!" << endl;
		botTurnAttack(playerBoard);
		playerBoard.start();
	}
}

void Playing::ShipPlacement(Board &Board)
{
	int fourDeckShip = 0, threeDeckShip = 0, doubleDeckerShip = 0, singleDeckShip = 0;
	int x, y, size;
	int h;
	bool horizontal;
	for (int i = 0; i <= 9; i++)
	{
		cout << "Введіть координати горизонтальність та ромір корабля(приклад 1, 2, 3, 0 - false 1-true): " << endl;
		cout << "Enter x" << endl;
		cin >> x;
		cout << "Enter y" << endl;
		cin >> y;
		cout << "enter size" << endl;
		cin >> size;
		cout << "Введіть горизонтальність корабля" << endl;
		cin >> h;
		if(size == 4) {
			fourDeckShip++;
		}
		if(size == 3) {
			threeDeckShip++;
		}
		if(size == 2){
			doubleDeckerShip++;
		}
		if(size == 1){
			singleDeckShip++;
		}
		if (h == 1)
			horizontal = true;
		if (h == 0)
			horizontal = false;

		if(fourDeckShip == 2 || threeDeckShip == 3 || doubleDeckerShip == 4 || singleDeckShip == 5) {
			cout << "Кількість цих кораблів максимальна" << endl;
		}
		else
			SetShip(x - 1, y - 1, size, horizontal, Board);
		Board.start();
	}
}

void Playing::AutoShipPlacement(Board &board)
{
    const int shipSizes[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    const int numShips = sizeof(shipSizes) / sizeof(shipSizes[0]);

    for (int i = 0; i < numShips; ++i) {
        bool placed = false;

        while (!placed) {
            int x = rand() % board.size;
            int y = rand() % board.size;
            bool horizontal = rand() % 2 == 0;

            bool canPlace = true;

            for (int j = 0; j < shipSizes[i]; ++j) {
                int nx = x + (horizontal ? 0 : j);
                int ny = y + (horizontal ? j : 0);

                if (nx < 0 || nx >= board.size || ny < 0 || ny >= board.size) {
                    canPlace = false;
                    break;
                }

                if (board.grid[nx][ny].getStatus() == '#') {
                    canPlace = false;
                    break;
                }

                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int adjX = nx + dx;
                        int adjY = ny + dy;
                        if (adjX >= 0 && adjX < board.size && adjY >= 0 && adjY < board.size) {
                            if (board.grid[adjX][adjY].getStatus() == '#') {
                                canPlace = false;
                                break;
                            }
                        }
                    }
                    if (!canPlace) break;
                }
                if (!canPlace) break;
            }

            if (canPlace) {
                SetShip(x, y, shipSizes[i], horizontal, board);
                placed = true;
            }
        }
    }
}

void Playing::SetShip(int x, int y, int size, bool horizontal, Board &board) {
	for (int i = 0; i < size; ++i) {
		int nx = x + (horizontal ? 0 : i);
		int ny = y + (horizontal ? i : 0);

		if (nx < 0 || nx >= board.size || ny < 0 || ny >= board.size) {
			cerr << "Error: Ship placement is out of bounds." << endl;
			return;
		}

		// Перевірка на перекриття з іншими кораблями
		if (board.grid[nx][ny].getStatus() == '#') {
			cerr << "Error: Ship placement overlaps with another ship." << endl;
			return;
		}
	}

	// Розміщення корабля
	for (int i = 0; i < size; ++i) {
		int nx = x + (horizontal ? 0 : i);
		int ny = y + (horizontal ? i : 0);

		board.grid[nx][ny].setStatus('#');
	}
}

void PlayingPlayer::startGameVsPlayer(Board &playerBoard, Board &playerTwoBoard)
{
	int x, y;
	cout << "Поля гравців створені, гра починається!" << endl;
	cout << "Перший хід за гравцем!" << endl;
	while (livingCellsPlayerOne && livingCellsPlayerTwo) {
		endGame();
		cout << "Введіть координати для атаки(x, y):" << endl;
		cin >> x;
		cin >> y;
		PlayersTurnAttack(x - 1, y - 1, playerTwoBoard, livingCellsPlayerTwo);
		cout << "Атага гравця 2!" << endl;
		PlayersTurnAttack(x - 1, y - 1, playerBoard, livingCellsPlayerOne);
	}
}