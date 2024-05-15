#ifndef UNIK_OBJECT_H
#define UNIK_OBJECT_H



class Object {
private:
    int location_x, location_y;

public:
    Object();
    virtual ~Object();

    int getLocation(); // return tab[x, y] or maybe change it to two functions getLocationX getLocationY

    virtual void move(); // virtual to let hero and rocket move in a different way

    //int collision(); // put it here or maybe in engine's function


};


#endif //UNIK_OBJECT_H
