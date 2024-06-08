#include "../headers/Rocket.h"
#include <cstdlib>

Rocket::Rocket() : Object() {}

Rocket::~Rocket() {}

Rocket::Rocket(Rocket &&other) noexcept : Object() {
    location_x = other.location_x;
    location_y = other.location_y;
}

Rocket& Rocket::operator=(Rocket &&other) noexcept {
    if (this != &other) {
        location_x = other.location_x;
        location_y = other.location_y;
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
    // Rakieta porusza się w kierunku środka planszy
    if (location_x < 5) location_x++;
    else if (location_x > 5) location_x--;

    if (location_y < 5) location_y++;
    else if (location_y > 5) location_y--;
}
