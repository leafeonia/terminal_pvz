//
// Created by leafeon on 11/6/19.
//

#ifndef PVZ_PAINTER_H
#define PVZ_PAINTER_H

#include "objects.h"

class Painter{
private:
    static vector<Object> objects;
    static vector<vector<Pixel>> board;
    static void drawObject(const Object &o);
public:
    static void addObject(const Object &o);
    static void deleteObject(const Object &o);
    static void updateScreen();
};


#endif //PVZ_PAINTER_H
