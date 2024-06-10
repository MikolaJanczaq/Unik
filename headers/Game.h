#ifndef UNIK_GAME_H
#define UNIK_GAME_H

#include "Engine.h"

class Game : public Engine {
private:
    Game(const Game &e);
    Game &operator=(const Game &E);

public:
    Game();
    ~Game();

    virtual void Run(); // Start the game loop
    virtual void Show();
};

#endif //UNIK_GAME_H