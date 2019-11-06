#include "common.h"
#include "objects.h"
#include "Painter.h"

int main() {
    for (int i = 0; i < NR_ROW; ++i) {
        for (int j = 0; j < NR_COL; ++j) {
            Painter::addObject(Grassland(i * (HEIGHT / NR_ROW), j * (WIDTH / NR_COL)));
        }
    }
//    Grassland grassland1(0,0);
//    Grassland grassland2(7,7);
//    Painter::addObject(grassland1);
//    Painter::addObject(grassland2);
    Painter::updateScreen();
    return 0;
}