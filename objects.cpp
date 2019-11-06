//
// Created by leafeon on 11/6/19.
//

#include "objects.h"

int Object::cnt = 0;

Grassland::Grassland(int r, int c) {
    row = r;
    col = c;
    priority = PRI_BACKGROUND;
    int w = WIDTH / NR_COL;
    int h = HEIGHT / NR_ROW;
    for (int i = 0; i < h; ++i) {
        vector<Pixel> line;
        if(i == 0 || i == h - 1){
            for (int j = 0; j < w; ++j) {
                line.push_back(Pixel(' ', DARKGREEN));
            }
        }
        else{
            line.push_back(Pixel(' ', DARKGREEN));
            for (int j = 1; j < w - 1; ++j) {
                line.push_back(Pixel(' ', GREEN));
            }
            line.push_back(Pixel(' ', DARKGREEN));
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
        else if(i == h / 2 - 1){
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
            for (int j = 16 + strlen("peanut shooter 100") + strlen("sunflower 50") - 2; j < WIDTH; ++j) {
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