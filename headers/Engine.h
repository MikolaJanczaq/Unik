#ifndef UNIK_ENGINE_H
#define UNIK_ENGINE_H

#include <vector>
#include "Object.h"
#include "Hero.h"
#include "Rocket.h"

class Engine {
protected:
    int size;
    int rockets_num;
    int **tab;
    int **temp;
    Hero hero;
    std::vector<Rocket> rockets;

    void createMap();
    void createHero();
    void createRockets();
    void replaceRocket(int index);

    Engine(const Engine &e);
    Engine &operator=(const Engine &E);

public:
    Engine();
    virtual ~Engine();

    void Analysis();
    void MoveRockets();
};

#endif // UNIK_ENGINE_H