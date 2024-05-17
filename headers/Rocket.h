#ifndef UNIK_ROCKET_H
#define UNIK_ROCKET_H

#include "Object.h"

class Rocket : public Object{
private:
    Rocket(const Rocket & e);
    Rocket & operator = (const Rocket &E);

public:
    Rocket();
    ~Rocket();

    void startingPosition() override;
    void move() override;


};


#endif //UNIK_ROCKET_H
