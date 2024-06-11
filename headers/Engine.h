#ifndef UNIK_ENGINE_H
#define UNIK_ENGINE_H

#include <vector>
#include "Object.h"
#include "Hero.h"
#include "Rocket.h"

class Engine {
protected:
    int size;
    int **tab;
    int rocketsNum;
    std::vector<Rocket*> rockets;
    Hero hero;
    int speed;

    void createMap();
    void createHero();
    void createRockets();
    void replaceRocket(int index);
    bool checkCollision();

private:
    Engine(const Engine &e);
    Engine &operator=(const Engine &e);

public:
    bool gameStatus;
    Engine();
    virtual ~Engine();

    void Analysis();
    void MoveRockets();
};

#endif // UNIK_ENGINE_H