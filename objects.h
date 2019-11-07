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
private:
    int hp, attack;
public:
    Unit(int h,int a){hp = h; attack = a;}
};

class Plant: public Unit{
private:
    int cost;
public:
    Plant(int hp, int atk, int c):Unit(hp, atk){cost = c;}
};

class PeanutShooter: public Plant{
public:
    PeanutShooter(int r, int c);
};

class Sunflower: public Plant{
public:
    Sunflower(int r,int c);
};
#endif //PVZ_OBJECTS_H
