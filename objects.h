//
// Created by leafeon on 11/6/19.
//

#ifndef PVZ_OBJECTS_H
#define PVZ_OBJECTS_H

#include "common.h"

class Object{
protected:
    int row, col, priority;
    vector<vector<Pixel>> pixels;
public:
    friend class Painter;
    bool operator < (const Object& o){return priority < o.priority;}
};

class Grassland: public Object{
public:
    Grassland(int r,int c);
};

#endif //PVZ_OBJECTS_H
