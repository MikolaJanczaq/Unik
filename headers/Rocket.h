#ifndef UNIK_ROCKET_H
#define UNIK_ROCKET_H

#include "Object.h"

class Rocket : public Object {
public:
    Rocket();
    ~Rocket();

    Rocket(const Rocket &other) = delete;
    Rocket& operator=(const Rocket &other) = delete;

    Rocket(Rocket &&other) noexcept;
    Rocket& operator=(Rocket &&other) noexcept;

    void startingPosition() override;
    void move() override;
};

#endif //UNIK_ROCKET_H
