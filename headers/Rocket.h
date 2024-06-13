#ifndef UNIK_ROCKET_H
#define UNIK_ROCKET_H

#include "Object.h"

class Rocket : public Object {
private:
    Rocket(const Rocket &r);
    Rocket& operator=(const Rocket &r);

    int direction;

public:
    Rocket();
    ~Rocket() override;

    int getDirection() const;
    void setDirection() ;
    bool isAtEdge(int rocket_direction) const;

    void startingPosition() override;
    void move(char input) override;
};

#endif //UNIK_ROCKET_H