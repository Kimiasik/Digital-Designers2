#include "Menu.h"
#include "Map.h"
#include "Game.h"
using namespace std;

void Menu::displayMenu() {
        cout << "============================\n";
        cout << "       МОРСЬКИЙ БІЙ       \n";
        cout << "============================\n";
        cout << "1. Розпочати гру\n";
        cout << "2. Вийти з гри\n";
        cout << "Введіть свій вибір: ";
}

void Menu::startGame() {
        cout << "Гра розпочалася! Удачі!\n";
				board.start();

}
void Menu::GameMode()
{
	int choiceGame;
	int endWhile;
	while (true) {
		cout << "ВИБЕРІТЬ РЕЖИМ ГРИ" << endl;
		cout << "1. Грати з ботом" << endl;
		cout << "2. LAN гра" << endl;
        cout << "Введіть свій вибір: ";
        cin >> choiceGame;

		switch(choiceGame)
		{
			case 1:
				ChoiceShipPlacement();
				endWhile = 1;
				break;
			case 2:
				startGame();
				endWhile = 1;
				break;
			default:
				cout << "Невірний вибір. Спробуйте ще раз.\n";
		}
		cout << "\n";
		if(endWhile == 1)
			break;
	}
}

void Menu::run() {
        int choice;
		int gameStart = 0;
        while (true) {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    GameMode();
					gameStart = 1;
                    break;
                case 2:
                    cout << "Дякуємо за гру! До побачення!\n";
                    break;
                default:
                    cout << "Невірний вибір. Спробуйте ще раз.\n";
            }
            cout << "\n";
						if(gameStart == 1)
							break;
        }
}

void Menu::ChoiceShipPlacement()
{
	int choice;
	int endWhile;
	while (true)
	{
		cout << "ВИБЕРІТЬ РОЗТАШУВАННЯ КОРАБЛІВ" << endl;
		cout << "1. Вручну" << endl;
		cout << "2. Випадково" << endl;
        cout << "Введіть свій вибір: ";
        cin >> choice;
		switch(choice)
		{
			case 1:
				board.start();
				endWhile = 1;
				break;

			case 2:
				playing.AutoShipPlacement();
				endWhile = 1;
				break;
			default:
				cout << "Невірний вибір. Спробуйте ще раз.\n";
		}
		if (endWhile == 1)
			break;
	}
}