#ifndef UNIK_ENGINE_H
#define UNIK_ENGINE_H

#include "Object.h"
#include "Hero.h"
#include "Rocket.h"
#include <vector>


class Engine {
private:
    Engine(const Engine &e);
    Engine &operator=(const Engine &e);
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
