#include "common.h"
#include "objects.h"
#include "Painter.h"

int main() {
    Grassland grassland1(0,0);
    Grassland grassland2(7,7);
    Painter::addObject(grassland1);
    Painter::addObject(grassland2);
    Painter::updateScreen();
    return 0;
}