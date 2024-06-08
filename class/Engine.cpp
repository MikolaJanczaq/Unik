#include "../headers/Engine.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

// Konstruktor i destruktor dla Engine
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

// Tworzenie mapy
void Engine::createMap() {
    tab = new int*[size];
    temp = new int*[size];
    for (int i = 0; i < size; ++i) {
        tab[i] = new int[size];
        temp[i] = new int[size];
    }
    srand(time(0));
}

// Tworzenie bohatera
void Engine::createHero() {
    hero.startingPosition();
}

// Tworzenie rakiet
void Engine::createRockets() {
    rockets.reserve(5); // rezerwujemy miejsce dla 5 rakiet
    for (int i = 0; i < 5; ++i) {
        Rocket rocket;
        do {
            rocket.startingPosition();
        } while (rocket.getLocationX() == hero.getLocationX() && rocket.getLocationY() == hero.getLocationY());
        rockets.push_back(std::move(rocket)); // używamy std::move, aby przenieść rakietę
    }
}

// Analiza stanu gry
void Engine::Analysis() {
    std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex

    // Aktualizowanie pozycji rakiet
    for (auto &rocket : rockets) {
        rocket.move();
    }

    // Sprawdzenie kolizji
    for (const auto &rocket : rockets) {
        if (rocket.getLocationX() == hero.getLocationX() && rocket.getLocationY() == hero.getLocationY()) {
            std::cout << "Game Over! You were hit by a rocket!" << std::endl;
            exit(0);
        }
    }

    // Aktualizacja mapy
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tab[i][j] = 0;
        }
    }

    tab[hero.getLocationY()][hero.getLocationX()] = 1; // Bohater

    for (const auto &rocket : rockets) {
        tab[rocket.getLocationY()][rocket.getLocationX()] = 2; // Rakieta
    }
}

// Update rockets' positions
void Engine::updateRockets() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
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
            std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex before moving the hero
            hero.move(input);
        }

        system("clear"); // Clear console, may use "cls" on Windows
        Show();
    }
}
