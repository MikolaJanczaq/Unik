#ifndef UNIK_HERO_H
#define UNIK_HERO_H

#include "Object.h"

class Hero : public Object {
private:
    Hero(const Hero &h);
    Hero &operator=(const Hero &h);

public:
    Hero();
    ~Hero() override;

    void startingPosition() override;
    void move(char input);
};

#endif //UNIK_HERO_H