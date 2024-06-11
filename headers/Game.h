#ifndef UNIK_GAME_H
#define UNIK_GAME_H

#include "Engine.h"

class Game : public Engine {
private:
    Game(const Game &g);
    Game &operator=(const Game &g);

public:
    Game();
    virtual ~Game();

    virtual void Run();
    virtual void Show();
};

#endif //UNIK_GAME_H