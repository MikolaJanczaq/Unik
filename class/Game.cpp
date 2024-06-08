#include "../headers/Game.h"
#include <iostream>

Game::Game() {}

Game::~Game() {}

void Game::Run() {
    while (true) {
        Analysis();
        Show();

        char input;
        std::cin >> input;
        hero.move(input);

        system("clear"); // Clear console, may use "cls" on Windows
    }
}

void Game::Show() {
    // Wyświetlanie stanu gry, do zaimplementowania w klasach pochodnych
}
