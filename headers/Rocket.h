#ifndef UNIK_ROCKET_H
#define UNIK_ROCKET_H

#include "Object.h"

class Rocket : public Object{
public:
    Rocket();
    ~Rocket();

    void move() override;

};


#endif //UNIK_ROCKET_H
