#include "../headers/Rocket.h"
#include <cstdlib>

Rocket::Rocket() : Object(), direction(0) {
    direction = rand() % 4;
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

void Rocket::move() {
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

bool Rocket::isAtEdge(int direction) const {
    switch (direction) {
        case 0: return location_y == 0; // Góra
        case 1: return location_y == 9; // Dół
        case 2: return location_x == 0; // Lewo
        case 3: return location_x == 9; // Prawo
        default: return false; // Nieznany kierunek
    }
}