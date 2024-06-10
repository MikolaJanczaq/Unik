#include "../headers/Object.h"

Object::Object() : location_x(-1), location_y(-1) {}

Object::~Object() {}

void Object::startingPosition() {
    location_x = 0;
    location_y = 0;
}

int Object::getLocationX() const {
    return location_x;
}

int Object::getLocationY() const {
    return location_y;
}

void Object::move() {
    // Default implementation
}