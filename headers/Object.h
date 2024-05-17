#ifndef UNIK_OBJECT_H
#define UNIK_OBJECT_H

class Object {
private:
    int location_x, location_y;

    Object(const Object & e);
    Object & operator = (const Object &E);

public:
    Object();
    virtual ~Object();


    virtual void startingPosition();
    int getLocationX();
    int getLocationY();

    virtual void move();


};


#endif //UNIK_OBJECT_H
