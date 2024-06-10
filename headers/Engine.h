#ifndef UNIK_ENGINE_H
#define UNIK_ENGINE_H

#include "Object.h"
#include "Hero.h"
#include "Rocket.h"
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <iostream>

class Engine {
protected:
    int size;
    int **tab;
    int **temp;
    Hero hero;
    std::vector<Rocket> rockets;
    std::mutex mtx;
    std::condition_variable cv;  // Condition variable for rocket updates
    bool stopThreads;

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
    void Run();
    void MoveRockets();
    void updateRockets();
};

#endif // UNIK_ENGINE_H
