#include "Menu.h"
#include "Map.h"
using namespace std;

void Menu::displayMenu() {
        cout << "============================\n";
        cout << "       МОРСЬКИЙ БІЙ       \n";
        cout << "============================\n";
        cout << "1. Розпочати гру\n";
        cout << "2. Вийти з гри\n";
        cout << "Введіть свій вибір: ";
}

void GameMenu::startGame() {
        cout << "Гра розпочалася! Удачі!\n";
				Game game;
				game.start();
}

Application::Application() : running(true) {}

void Application::GameMode()
{
	int choiceGame;
	while (running) {
		cin >> choiceGame;
		cout << "ВИБЕРІТЬ РЕЖИМ ГРИ" << endl;
		cout << "1. Грати з ботом" << endl;
		cout << "2. LAN гра" << endl;

		switch(choiceGame)
		{
			case 1:
				break;
			case 2:
				game.startGame();
				break;
			default:
				cout << "Невірний вибір. Спробуйте ще раз.\n";
		}
		cout << "\n";
	}
}

void Application::run() {
        int choice;
				int gameStart = 0;
        while (running) {
            menu.displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    GameMode();
										gameStart = 1;
                    break;
                case 2:
                    cout << "Дякуємо за гру! До побачення!\n";
                    running = false;
                    break;
                default:
                    cout << "Невірний вибір. Спробуйте ще раз.\n";
            }
            cout << "\n";
						if(gameStart == 1)
							break;
        }
}

void Application::ChoiceShipPlacement()
{
	int choice;
	while (running)
	{
		cin >> choice;
		cout << "ВИБЕРІТЬ РОЗТАШУВАННЯ КОРАБЛІВ" << endl;
		cout << "1. Вручну" << endl;
		cout << "2. Випадково" << endl;
		switch(choice)
		{
			case 1:

				break;

			case 2:

				break;
			default:
				cout << "Невірний вибір. Спробуйте ще раз.\n";
		}
	}
}