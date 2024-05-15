#ifndef UNIK_HERO_H
#define UNIK_HERO_H

#include "Object.h"

class Hero : public Object{
public:
    Hero();
    ~Hero();

    void move() override;

};


#endif //UNIK_HERO_H
