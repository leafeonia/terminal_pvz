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
#define PRI_UNIT 1
#define PRI_UNITPLUS 2
#define PRI_BULLET 3
#define PRI_CURSOR 5

#define WHITE 0xffffff
#define RED 0xff0000
#define ORANGE 0xff9900
#define YELLOW 0xffff00
#define GREEN 0xff66
#define DARKGREEN 0xcc00
#define DEEPGREEN 0x6600
#define INDIGO 0x3399cc
#define BLUE 0xff
#define PURPLE 0x6600ff
#define DARKPURPLE 0x330066
#define BROWN 0x996666
#define LIGHTGREY 0xbbbbbb
#define GREY 0x4b4b4b

#define PEANUT_HP 100
#define PEANUT_ATK 30
#define PEANUT_COST 100

#define SUNFLOWER_HP 50
#define SUNFLOWER_ATK 0
#define SUNFLOWER_COST 50

#define GARLIC_HP 40
#define GARLIC_ATK 0
#define GARLIC_COST 50

#define WALLNUT_HP 500
#define WALLNUT_ATK 0
#define WALLNUT_COST 50

#define SNOW_HP 100
#define SNOW_ATK 35
#define SNOW_COST 175

#define THORN_HP 1
#define THORN_ATK 25
#define THORN_COST 100

#define PEPPER_HP 1
#define PEPPER_ATK 1
#define PEPPER_COST 999

#define MELON_HP 100
#define MELON_ATK 85
#define MELON_COST 300

#define NORMALZB_HP 300
#define NORMALZB_ATK 10
#define NORMALZB_SPEED 10
#define NORMALZB_SCORE 100

#define FLAGZB_SPEED 5
#define FLAGZB_SCORE 150

#define CONEZB_HP 800
#define CONEZB_SCORE 300

#define FBZB_HP 900
#define FBZB_ATK 15
#define FBZB_SPEED 5
#define FBZB_SCORE 666

#define DKZB_HP 500
#define DKZB_SCORE 300

#define NEWSZB_HP 400
#define NEWSZB_SPEED 10
#define NEWSZB_SCORE 200

class Pixel{
public:
    Pixel(){ch = ' ';back = 0;}
    Pixel(char c,int b){ch = c; back = b;}
    char ch;
    int back;
};

#endif //PVZ_COMMON_H
