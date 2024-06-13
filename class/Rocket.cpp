#include "../headers/Rocket.h"
#include <cstdlib>

Rocket::Rocket() : Object() {
    direction = rand() % 4; // 0 down 1 up 2 left 3 right
}

Rocket::~Rocket() {}

void Rocket::startingPosition() {
    int edge = rand() % 4;
    switch (edge) {
        case 0:
            location_x = rand() % 10;
            location_y = 0;
            break;
        case 1:
            location_x = rand() % 10;
            location_y = 9;
            break;
        case 2:
            location_x = 0;
            location_y = rand() % 10;
            break;
        case 3:
            location_x = 9;
            location_y = rand() % 10;
            break;
    }
}

void Rocket::move(char input) {
    switch (direction) {
        case 0: if (location_y > 0) location_y--; break;
        case 1: if (location_y < 9) location_y++; break;
        case 2: if (location_x > 0) location_x--; break;
        case 3: if (location_x < 9) location_x++; break;
    }
}

int Rocket::getDirection() const{
    return direction;
}

void Rocket::setDirection()  {
    this->direction = rand() % 4;
}

bool Rocket::isAtEdge(int rocket_direction) const {
    switch (rocket_direction) {
        case 0: return location_y == 0;
        case 1: return location_y == 9;
        case 2: return location_x == 0;
        case 3: return location_x == 9;
        default: return false;
    }
}
