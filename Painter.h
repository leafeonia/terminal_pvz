//
// Created by leafeon on 11/6/19.
//

#ifndef PVZ_PAINTER_H
#define PVZ_PAINTER_H

#include "objects.h"
#include <unistd.h>

class Painter{
private:
    static pthread_mutex_t screen_lock;
    static vector<Object> objects;
    static vector<vector<Pixel>> board;
    static vector<bool> flame;
    static void drawObject(const Object &o);
public:
    static void addObject(const Object &o);
    static void updateObject(const Object &o, int x, int y);
    static void updateObject(const Object &o, int x, int y,const vector<vector<Pixel> > &update);
    static vector<vector<Pixel> > pixmapGenerate(int row, int col, vector<char> chars, vector<int> colors);
    static void deleteObject(const Object &o);
    static void updateScreen();
    static void gameover();
    static void setFlame(int row, bool on);
};


#endif //PVZ_PAINTER_H
