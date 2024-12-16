#include "Menu.h"
#include <cstdlib>

using namespace std;

    void Menu::displayMenu() {
        cout << "============================\n";
        cout << "       МОРСЬКИЙ БІЙ       \n";
        cout << "============================\n";
        cout << "1. Розпочати гру\n";
        cout << "2. Вийти з гри\n";
        cout << "Введіть свій вибір: ";
    }

    void Game::startGame() {
        cout << "Гра розпочалася! Удачі!\n";
    }

    Application::Application() : running(true) {}

    void Application::run() {
        int choice;
        while (running) {
            menu.displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    game.startGame();
                    break;
                case 2:
                    cout << "Дякуємо за гру! До побачення!\n";
                    running = false;
                    break;
                default:
                    cout << "Невірний вибір. Спробуйте ще раз.\n";
            }

            cout << "\n";
        }
    }

