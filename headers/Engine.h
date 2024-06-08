#ifndef UNIK_ENGINE_H
#define UNIK_ENGINE_H

#include "Object.h"
#include "Hero.h"
#include "Rocket.h"
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>

class Engine {
protected:
    int size;
    int **tab;
    int **temp;
    Hero hero;
    std::vector<Rocket> rockets;
    std::mutex mtx;  // Mutex for protecting shared resources

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
    void Run();

private:
    void updateRockets();
};

#endif // UNIK_ENGINE_H
