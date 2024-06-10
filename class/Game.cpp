#include "../headers/Game.h"
#include <iostream>

Game::Game() {}

Game::~Game() {}

void Game::Run() {
    Engine::Run();
}

void Game::Show() {
    std::lock_guard<std::mutex> lock(mtx);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (tab[i][j] == 1) {
                std::cout << 'H';  // Hero
            } else if (tab[i][j] == 2) {
                std::cout << 'R';  // Rocket
            } else {
                std::cout << '.';  // Empty space
            }
        }
        std::cout << std::endl;
    }
}