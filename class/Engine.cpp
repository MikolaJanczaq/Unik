#include "../headers/Engine.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>

Engine::Engine() : size(10), tab(nullptr), temp(nullptr) {
    srand(static_cast<unsigned int>(time(0)));
    createMap();
    createHero();
    createRockets();
}

Engine::~Engine() {
    for (int i = 0; i < size; ++i) {
        delete[] tab[i];
        delete[] temp[i];
    }
    delete[] tab;
    delete[] temp;
}

void Engine::createMap() {
    tab = new int*[size];
    temp = new int*[size];
    for (int i = 0; i < size; ++i) {
        tab[i] = new int[size]();
        temp[i] = new int[size]();
    }
}

void Engine::createHero() {
    hero.startingPosition();
}

void Engine::createRockets() {
    for (int i = 0; i < 5; ++i) {
        Rocket rocket;
        do {
            rocket.startingPosition();
        } while (rocket.getLocationX() == hero.getLocationX() && rocket.getLocationY() == hero.getLocationY());
        rockets.push_back(std::move(rocket));
    }
}

void Engine::replaceRocket(int index) {
    Rocket rocket;
    do {
        rocket.startingPosition();
    } while (rocket.getLocationX() == hero.getLocationX() && rocket.getLocationY() == hero.getLocationY());
    rockets[index] = std::move(rocket);
}

void Engine::MoveRockets() {
    while (true) {
        for (Rocket &rocket : rockets) {
            rocket.move();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds (500));
    }
}

void Engine::Analysis() {
    for (const Rocket &rocket : rockets) {
        if (rocket.getLocationX() == hero.getLocationX() && rocket.getLocationY() == hero.getLocationY()) {
            std::cout << "Game Over! You were hit by a rocket!" << std::endl;
            exit(0);
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tab[i][j] = 0;
        }
    }

    tab[hero.getLocationY()][hero.getLocationX()] = 1;

    for (int i = 0; i < rockets.size(); ++i) {
        if (rockets[i].isAtEdge()) {
            replaceRocket(i);
        }
        tab[rockets[i].getLocationY()][rockets[i].getLocationX()] = 2;
    }
}
