//
// Created by leafeon on 11/6/19.
//

#include "objects.h"


Grassland::Grassland(int r, int c) {
    row = r;
    col = c;
    priority = BACKGROUND;
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
