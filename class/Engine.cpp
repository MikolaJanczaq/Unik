#include "../headers/Engine.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <fstream>

Engine::Engine(const char* fn) : size(10) {
    readConfig(fn);
    srand(static_cast<unsigned int>(time(0)));
    createMap();
    createHero();
    createRockets();
}

void Engine::readConfig(const char* fn) {
    std::ifstream file(fn);
    if (!file.is_open()) {
        exit(500);
    }
    int value;
    file >> value;
        rocketsNum = value;

    file >> value;
        speed = value;
    file.close();
}

Engine::~Engine() {
    for (int i = 0; i < size; ++i) {
        delete[] tab[i];
    }
    delete[] tab;

    for (int i=0; i<rockets.size(); i++) {
        delete rockets[i];
    }
}

void Engine::createMap() {
    tab = new int*[size];
    for (int i = 0; i < size; ++i) {
        tab[i] = new int[size]();
    }
}

void Engine::createHero() {
    hero.startingPosition();
}

void Engine::createRockets() {
    for (int i = 0; i < rocketsNum; ++i) {
        Rocket* rocket = new Rocket();
        do {
            rocket->startingPosition();
        } while (rocket->getLocationX() == hero.getLocationX() && rocket->getLocationY() == hero.getLocationY());
        rockets.push_back(rocket);
    }
}
void Engine::MoveRockets() {
    speed = (11-speed)*100;
    if(speed<0) {
        exit(600);
    }
    while (true) {
        for(int i = 0; i < rockets.size(); i++) {
            rockets[i]->move();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds (speed));
    }
}


void Engine::replaceRocket(int index) {
    do {
        rockets[index]->setDirection();
        rockets[index]->startingPosition();
    } while (rockets[index]->getLocationX() == hero.getLocationX() && rockets[index]->getLocationY() == hero.getLocationY());
}

bool Engine::checkCollision() {
    for (int i = 0; i < rockets.size(); i++) {
        if (rockets[i]->getLocationX() == hero.getLocationX() && rockets[i]->getLocationY() == hero.getLocationY()) {
            gameStatus = false;
            return true;
        }
    }
    return false;
}

void Engine::Analysis() {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tab[i][j] = 0;
        }
    }

    tab[hero.getLocationY()][hero.getLocationX()] = 1;

    for (int i = 0; i < rockets.size(); i++) {
        if (rockets[i]->isAtEdge(rockets[i]->getDirection())) {
            replaceRocket(i);
        }
        tab[rockets[i]->getLocationY()][rockets[i]->getLocationX()] = 2;
    }
    checkCollision();
}
