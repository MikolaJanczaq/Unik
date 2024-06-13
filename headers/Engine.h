#ifndef UNIK_ENGINE_H
#define UNIK_ENGINE_H

#include "../headers/Object.h"
#include "../headers/Hero.h"
#include "../headers/Rocket.h"

#include <vector>
#include "Object.h"

class Engine {
protected:
    int size;
    int **tab;
    int rocketsNum;
    std::vector<Object*> rockets;
    Object* hero;
    int speed;

    void readConfig(const char* fn);
    void createMap();
    void createHero();
    void createRockets();
    void replaceRocket(int index);
    bool checkCollision();

public:
    bool gameStatus;
    Engine(const char* fn);
    virtual ~Engine();

    void Analysis();
    void MoveRockets();
};

#endif // UNIK_ENGINE_H
