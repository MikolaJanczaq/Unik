#ifndef UNIK_OBJECT_H
#define UNIK_OBJECT_H

class Object {
protected:
    int location_x, location_y;

    Object(const Object &e);
    Object &operator=(const Object &E);

public:
    Object();
    virtual ~Object();

    virtual void startingPosition();
    int getLocationX() const;  // Dodajemy const
    int getLocationY() const;  // Dodajemy const

    virtual void move();
};

#endif //UNIK_OBJECT_H
