#ifndef UNIK_ROCKET_H
#define UNIK_ROCKET_H

#include "Object.h"

class Rocket : public Object {
private:
    int direction; // 0: up, 1: down, 2: left, 3: right

public:
    Rocket();
    ~Rocket();

    Rocket(const Rocket &other) = delete;
    Rocket& operator=(const Rocket &other) = delete;

    Rocket(Rocket &&other) noexcept;
    Rocket& operator=(Rocket &&other) noexcept;

    void startingPosition() override;
    void move() override;
    bool isAtEdge() const; // New method to check if the rocket is at the edge
};

#endif //UNIK_ROCKET_H