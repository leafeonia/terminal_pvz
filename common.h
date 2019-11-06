//
// Created by leafeon on 11/6/19.
//

#ifndef PVZ_COMMON_H
#define PVZ_COMMON_H

#include <bits/stdc++.h>
using namespace std;
#define HEIGHT 35
#define WIDTH 49
#define BACKGROUND 0

class Pixel{
public:
    Pixel(){front = ' ';back = 0;}
    Pixel(char f,int b){front = f; back = b;}
    char front;
    int back;
};

#endif //PVZ_COMMON_H
