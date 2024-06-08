#ifndef UNIK_ENGINE_H
#define UNIK_ENGINE_H

#include "Object.h"
#include "Hero.h"
#include "Rocket.h"
#include <vector>

class Engine {
protected:
    int size;
    int **tab;
    int **temp;
    Hero hero;
    std::vector<Rocket> rockets;

    void createMap();
    void createHero();
    void createRockets();

    Engine(const Engine &e);
    Engine &operator=(const Engine &E);

public:
    Engine();
    virtual ~Engine();

    void Analysis();
    virtual void Show() = 0;
};

#endif //UNIK_ENGINE_H
