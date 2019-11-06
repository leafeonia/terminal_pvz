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

#endif //PVZ_OBJECTS_H
