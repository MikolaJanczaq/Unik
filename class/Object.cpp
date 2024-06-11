#include "../headers/Object.h"

Object::Object() {
}

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

void Object::move() {}