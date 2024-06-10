#ifndef UNIK_ROCKET_H
#define UNIK_ROCKET_H

#include "Object.h"

class Rocket : public Object {
private:
    int direction;

public:
    Rocket();
    ~Rocket();

    Rocket(const Rocket &other) = delete;
    Rocket& operator=(const Rocket &other) = delete;

    Rocket(Rocket &&other) noexcept;
    Rocket& operator=(Rocket &&other) noexcept;

    int getDirection() const;

    void startingPosition() override;
    void move() override;
    bool isAtEdge(int direction) const;
};

#endif //UNIK_ROCKET_H