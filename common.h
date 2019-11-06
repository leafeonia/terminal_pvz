//
// Created by leafeon on 11/6/19.
//

#ifndef PVZ_COMMON_H
#define PVZ_COMMON_H

#include <bits/stdc++.h>
using namespace std;
#define HEIGHT 35
#define WIDTH 105
#define SHOP_HEIGHT 10
#define NR_ROW 5
#define NR_COL 7

#define PRI_BACKGROUND 0
#define PRI_CURSOR 5

#define WHITE 0xffffff
#define RED 0xff0000
#define ORANGE 0xff9900
#define YELLOW 0xffff00
#define GREEN 0xff66
#define DARKGREEN 0xcc00
#define INDIGO 0x3399cc
#define BLUE 0xff
#define PURPLE 0x6600ff
#define DARKPURPLE 0x330066

class Pixel{
public:
    Pixel(){ch = ' ';back = 0;}
    Pixel(char c,int b){ch = c; back = b;}
    char ch;
    int back;
};

#endif //PVZ_COMMON_H
