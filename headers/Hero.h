#ifndef UNIK_HERO_H
#define UNIK_HERO_H

#include "Object.h"

class Hero : public Object{
private:
    Hero(const Hero & e);
    Hero & operator = (const Hero &E);
    
public:
    Hero();
    ~Hero();

    void startingPosition() override;
    void move() override;

};


#endif //UNIK_HERO_H
