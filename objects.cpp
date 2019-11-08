//
// Created by leafeon on 11/6/19.
//

#include "objects.h"
#include "Painter.h"
#include "Game.h"

int Object::cnt = 0;

Grassland::Grassland(int r, int c) {
    row = r;
    col = c;
    priority = PRI_BACKGROUND;
    int w = WIDTH / NR_COL;
    int h = HEIGHT / NR_ROW;
    for (int i = 0; i < h; ++i) {
        vector<Pixel> line;
        if(i == h - 1){
            for (int j = 0; j < w; ++j) {
                line.push_back(Pixel(' ', DARKGREEN));
            }
        }
        else{
            //line.push_back(Pixel(' ', DARKGREEN));
            for (int j = 0; j < w; ++j) {
                line.push_back(Pixel(' ', GREEN));
            }
            //line.push_back(Pixel(' ', DARKGREEN));
        }
        pixels.push_back(line);
    }
}

Shop::Shop() {
    row = HEIGHT;
    col = 0;
    priority = PRI_BACKGROUND;
    int w = WIDTH;
    int h = SHOP_HEIGHT;
    for (int i = 0; i < h; ++i) {
        vector<Pixel> line;
        vector<int> colors = {RED, ORANGE, YELLOW, GREEN, INDIGO, BLUE, PURPLE};
        if(i == 0 || i == h - 1){
            for (int j = 0; j < w; ++j) {
                line.push_back(Pixel(' ', colors[j % colors.size()]));
            }
        }
        else if(i == h / 2){
            for (int j = 0; j < 8; ++j) {
                line.push_back(Pixel(' ', DARKPURPLE));
            }
            for (auto ch: "peanut shooter 100") {
                line.push_back(Pixel(ch, DARKPURPLE));
            }
            for (int j = 0; j < 8; ++j) {
                line.push_back(Pixel(' ', DARKPURPLE));
            }
            for (auto ch: "sunflower 50") {
                line.push_back(Pixel(ch, DARKPURPLE));
            }
            for (int j = 16 + strlen("peanut shooter 100") + strlen("sunflower 50"); j < WIDTH; ++j) {
                line.push_back(Pixel(' ', DARKPURPLE));
            }
        }
        else{
            for (int j = 0; j < w; ++j) {
                line.push_back(Pixel(' ', DARKPURPLE));
            }
        }
        pixels.push_back(line);
    }
}

Cursor::Cursor(int r, int c) {
    row = r;
    col = c;
    priority = PRI_CURSOR;
    vector<Pixel> line;
    for (int j = 0; j < 2; ++j) {
        line.push_back(Pixel(' ', WHITE));
    }
    pixels.push_back(line);
}

InfoBoard::InfoBoard() {
    row = HEIGHT + 2;
    col = WIDTH - 30;
    priority = PRI_UNIT;
    vector<Pixel> line;
    for(auto ch: "sunshine: 0   score: 0") line.push_back(Pixel(ch, DARKPURPLE));
    pixels.push_back(line);
}

void InfoBoard::clockHandler() {
    vector<Pixel> line;
    string info = "sunshine: " + to_string(Game::sunshine) + "   score: " + to_string(Game::score);
    for(auto ch: info) line.push_back(Pixel(ch, DARKPURPLE));
    vector<vector<Pixel> > tmp;
    tmp.push_back(line);
    Painter::updateObject(*this, row, col, tmp);
}


PeanutShooter::PeanutShooter(int r, int c):Plant(PEANUT_HP, PEANUT_ATK, PEANUT_COST) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    vector<char> chars = {
            '/','^','\\','_','_',
            '\\','_','/','-','-',
            ' ','|',' ',' ',' ',
            'x','-','x',' ',' ',
            ' ','1','0','0',' '
    };
    vector<int> colors = {
            DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,
            DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,
            GREEN,DEEPGREEN,GREEN,GREEN,GREEN,
            DEEPGREEN,DEEPGREEN,DEEPGREEN,GREEN,GREEN,
            RED,RED,RED,RED,RED
    };
    pixels = Painter::pixmapGenerate(5,5,chars,colors);
}

void PeanutShooter::clockHandler() {
    timer++;
    if(timer == 10){
        timer = 0;
        Bullet *bullet = new Bullet(row + 1, col + 4);
        Game::addUnit(bullet);
    }
}

Sunflower::Sunflower(int r, int c): Plant(SUNFLOWER_HP, SUNFLOWER_ATK, SUNFLOWER_COST) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    vector<char> chars = {
            'o','o','o',
            'o','x','o',
            'o','o','o',
            '\\','|','/',
            ' ','5','0'
    };
    vector<int> color = {
            YELLOW,YELLOW,YELLOW,
            YELLOW,BROWN,YELLOW,
            YELLOW,YELLOW,YELLOW,
            DEEPGREEN,DEEPGREEN,DEEPGREEN,
            RED,RED,RED
    };
    pixels = Painter::pixmapGenerate(5,3,chars,color);
}

void Sunflower::clockHandler() {
    timer++;
    if(timer == 10){
        timer = 0;
        Game::addSunshine(50);
    }
}

Bullet::Bullet(int r, int c) {
    row = r;
    col = c;
    priority = PRI_BULLET;
    vector<Pixel> line;
    for (int i = 0; i < 2; ++i) {
        line.push_back(Pixel(' ', DEEPGREEN));
    }
    pixels.push_back(line);
}

void Bullet::clockHandler() {
    col++;
    Painter::updateObject(*this, row, col);
}