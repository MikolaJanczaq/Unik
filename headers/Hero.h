#ifndef UNIK_HERO_H
#define UNIK_HERO_H

#include "Object.h"

class Hero : public Object {
private:
    Hero(const Hero &h);
    Hero &operator=(const Hero &H);

public:
    Hero();
    ~Hero();

    void startingPosition() override;
    void move(char input); // Usunięto override
};

#endif //UNIK_HERO_H
