#ifndef UNIK_OBJECT_H
#define UNIK_OBJECT_H

class Object {
private:
    Object(const Object &o);
    Object &operator=(const Object &o);

protected:
    int location_x, location_y;

public:
    Object();
    virtual ~Object();

    virtual void startingPosition();

    int getLocationX() const;
    int getLocationY() const;

    virtual void move();
};

#endif //UNIK_OBJECT_H