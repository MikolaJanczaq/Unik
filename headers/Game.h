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

    void Run(); // while(true): Analysis
    void Show() override;
};

#endif //UNIK_GAME_H
