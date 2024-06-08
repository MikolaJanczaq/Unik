#include "../headers/Rocket.h"
#include <cstdlib>

Rocket::Rocket() : Object(), direction(0) {
    // Determine the direction in which the rocket will move (straight line)
    direction = rand() % 4; // 0: up, 1: down, 2: left, 3: right
}

Rocket::~Rocket() {}

Rocket::Rocket(Rocket &&other) noexcept : Object(), direction(other.direction) {
    location_x = other.location_x;
    location_y = other.location_y;
}

Rocket& Rocket::operator=(Rocket &&other) noexcept {
    if (this != &other) {
        location_x = other.location_x;
        location_y = other.location_y;
        direction = other.direction;
    }
    return *this;
}

void Rocket::startingPosition() {
    // Rakiety startują z losowej pozycji na krawędzi planszy
    int edge = rand() % 4;
    switch (edge) {
        case 0: // top edge
            location_x = rand() % 10;
            location_y = 0;
            break;
        case 1: // bottom edge
            location_x = rand() % 10;
            location_y = 9;
            break;
        case 2: // left edge
            location_x = 0;
            location_y = rand() % 10;
            break;
        case 3: // right edge
            location_x = 9;
            location_y = rand() % 10;
            break;
    }
}

void Rocket::move() {
    switch (direction) {
        case 0: if (location_y > 0) location_y--; break; // Move up
        case 1: if (location_y < 9) location_y++; break; // Move down
        case 2: if (location_x > 0) location_x--; break; // Move left
        case 3: if (location_x < 9) location_x++; break; // Move right
    }
}
