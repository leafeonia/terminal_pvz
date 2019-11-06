//
// Created by leafeon on 11/6/19.
//

#include "objects.h"


Grassland::Grassland(int r, int c) {
    row = r;
    col = c;
    priority = BACKGROUND;
    for (int i = 0; i < 7; ++i) {
        vector<Pixel> line;
        for (int j = 0; j < 7; ++j) {
            line.push_back(Pixel('g', 0));
        }
        pixels.push_back(line);
    }
}
