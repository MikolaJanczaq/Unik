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


    int getLocationX() const;
    int getLocationY() const;

    virtual void startingPosition();
    virtual void move(char input) =0;
};

#endif //UNIK_OBJECT_H