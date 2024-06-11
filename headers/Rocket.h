#ifndef UNIK_ROCKET_H
#define UNIK_ROCKET_H

#include "Object.h"

class Rocket : public Object {
private:
    int direction;

    Rocket(const Rocket &r);
    Rocket& operator=(const Rocket &r);

public:
    Rocket();
    ~Rocket() override;

    int getDirection() const;
    void setDirection() ;

    void startingPosition() override;
    bool isAtEdge(int direction) const;
    void move() override;
};

#endif //UNIK_ROCKET_H