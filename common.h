//
// Created by leafeon on 11/6/19.
//

#ifndef PVZ_COMMON_H
#define PVZ_COMMON_H

#include <bits/stdc++.h>
using namespace std;
#define HEIGHT 35
#define WIDTH 70
#define NR_ROW 5
#define NR_COL 7

#define BACKGROUND 0

#define GREEN 0xff00
#define DARKGREEN 0xcc00
#define BLUE 0xff

class Pixel{
public:
    Pixel(){ch = ' ';back = 0;}
    Pixel(char c,int b){ch = c; back = b;}
    char ch;
    int back;
};

#endif //PVZ_COMMON_H
