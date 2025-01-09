#include "Menu.h"
#include "Map.h"
#include "Game.h"
#include "bot.h"
using namespace std;

void Menu::displayMenu() {
	int choice;
	int endWhile = 0;
	while(true) {
		cout << "============================\n";
		cout << "       МОРСЬКИЙ БІЙ       \n";
		cout << "============================\n";
		cout << "1. Розпочати гру\n";
		cout << "2. Вийти з гри\n";
		cout << "Введіть свій вибір: ";
		cin >> choice;
		switch (choice) {
			case 1:
				GameMode();
				endWhile++;
				break;
			case 2:
				cout << "Завершення програми" << endl;
				endWhile++;
				break;
			default:
				cout << "Неправильний вибір" << endl;
				break;
		}
		if(endWhile == 1)
			return;
	}
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
				ChoiceShipPlacementVsPlayer();
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
				cout << "Player Board" << endl;
				playerBoard.start();
				playingBot.ShipPlacement(playerBoard);
				playingBot.AutoShipPlacement(botBoard);
				playingBot.StartGameVsBot(playerBoard, botBoard);
				endWhile = 1;
				break;

			case 2:
				playingBot.AutoShipPlacement(playerBoard);
				playerBoard.start();
				playingBot.AutoShipPlacement(botBoard);
				playingBot.StartGameVsBot(playerBoard, botBoard);
				endWhile = 1;
				break;
			default:
				cout << "Невірний вибір. Спробуйте ще раз.\n";
		}
		if (endWhile == 1)
			break;
	}
}

void Menu::ChoiceShipPlacementVsPlayer()
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
				cout << "Player 1 Board" << endl;
				playerBoard.start();
				playingPlayer.ShipPlacement(playerBoard);
				playerTwoBoard.start();
				playingPlayer.ShipPlacement(playerTwoBoard);
				playingPlayer.startGameVsPlayer(playerBoard, playerTwoBoard);
				endWhile = 1;
				break;
			case 2:
				playerBoard.start();
				playingPlayer.AutoShipPlacement(playerBoard);
				playerTwoBoard.start();
				playingPlayer.AutoShipPlacement(playerTwoBoard);
				playingPlayer.startGameVsPlayer(playerBoard, playerTwoBoard);
				endWhile = 1;
				break;
			default:
				cout << "Невірний вибір. Спробуйте ще раз.\n";
		}
		if (endWhile == 1)
			break;
	}
}