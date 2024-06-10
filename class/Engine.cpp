#include "../headers/Engine.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

// Constructor and Destructor for Engine
Engine::Engine() : size(10) {
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

// Create the map
void Engine::createMap() {
    tab = new int*[size];
    temp = new int*[size];
    for (int i = 0; i < size; ++i) {
        tab[i] = new int[size];
        temp[i] = new int[size];
    }
    srand(time(0));
}

// Create the hero
void Engine::createHero() {
    hero.startingPosition();
}

// Create the rockets
void Engine::createRockets() {
    rockets.reserve(5);
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

// Analyze the game state
void Engine::Analysis() {
    std::lock_guard<std::mutex> lock(mtx);

    for (auto &rocket : rockets) {
        rocket.move();
    }

    for (int i = 0; i < rockets.size(); ++i) {
        if (rockets[i].getLocationX() == hero.getLocationX() && rockets[i].getLocationY() == hero.getLocationY()) {
            std::cout << "Game Over! You were hit by a rocket!" << std::endl;
            //exit(0);
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

// Update rockets' positions
void Engine::updateRockets() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds (100));  // Adjusted delay to 1 second
        Analysis();
    }
}

void Engine::Run() {
    std::thread rocketThread(&Engine::updateRockets, this);
    rocketThread.detach(); // Run the rocket update thread in the background

    while (true) {
        char input;
        std::cin >> input;

        {
            std::lock_guard<std::mutex> lock(mtx);
            hero.move(input);
        }

        system("clear");
        //Show();
    }
}