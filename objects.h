//
// Created by leafeon on 11/6/19.
//

#ifndef PVZ_OBJECTS_H
#define PVZ_OBJECTS_H

#include "common.h"

class Object{
private:
    static int cnt;
protected:
    int row, col, priority, id;
    vector<vector<Pixel>> pixels;
public:
    Object(){id = cnt++;}
    friend class Painter;
    bool operator < (const Object& o){return priority < o.priority;}
};

class Grassland: public Object{
public:
    Grassland(int r,int c);
};

class Shop: public Object{
public:
    Shop();
};

class Cursor: public Object{
public:
    Cursor(int r, int c);
};


class Unit: public Object{
public:
    virtual void clockHandler()=0;
};

class InfoBoard: public Unit {
public:
    InfoBoard();
    void clockHandler();
};

class Plant: public Unit{
protected:
    int hp, attack, cost, timer;
public:
    Plant(int h, int a, int c){hp = h; attack = a;cost = c;timer = 0;}
};

class PeanutShooter: public Plant{
public:
    PeanutShooter(int r, int c);
    void clockHandler();
};

class Sunflower: public Plant{
public:
    Sunflower(int r,int c);
    void clockHandler();
};

class Bullet: public Unit{
public:
    Bullet(int r,int c);
    void clockHandler();
};
#endif //PVZ_OBJECTS_H
