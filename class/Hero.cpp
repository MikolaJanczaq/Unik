#include "../headers/Hero.h"

Hero::Hero() : Object() {}

Hero::~Hero() {}

void Hero::startingPosition() {
    location_x = 5; // Środek planszy
    location_y = 5;
}

void Hero::move(char input) {
    switch (input) {
        case 'w': if (location_y > 0) location_y--; break;
        case 's': if (location_y < 9) location_y++; break;
        case 'a': if (location_x > 0) location_x--; break;
        case 'd': if (location_x < 9) location_x++; break;
    }
}
