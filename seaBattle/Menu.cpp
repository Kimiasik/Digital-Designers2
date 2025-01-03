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

void GameMenu::startGame() {
        cout << "Гра розпочалася! Удачі!\n";
				Game game;
				game.start();

}

Application::Application() : running(true) {}

void Application::GameMode()
{
	int choiceGame;
	int endWhile;
	while (running) {
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
				game.startGame();
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
	int endWhile;
	while (running)
	{
		cout << "ВИБЕРІТЬ РОЗТАШУВАННЯ КОРАБЛІВ" << endl;
		cout << "1. Вручну" << endl;
		cout << "2. Випадково" << endl;
        cout << "Введіть свій вибір: ";
        cin >> choice;
		switch(choice)
		{
			case 1:
				playing.ShipPlacement();
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