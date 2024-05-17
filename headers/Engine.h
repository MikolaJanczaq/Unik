#ifndef UNIK_ENGINE_H
#define UNIK_ENGINE_H

#include "Object.h"
#include "Hero.h"
#include "Rocket.h"

class Engine {
private:
    int size;
    int **tab;
    int **temp;


    void createMap();
    void createHero();


    Engine(const Engine & e);
    Engine & operator = (const Engine &E);

public:
    Engine();
    ~Engine();

    void Analysis();

};


#endif //UNIK_ENGINE_H
