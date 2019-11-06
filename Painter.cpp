//
// Created by leafeon on 11/6/19.
//

#include "Painter.h"

//Painter::Painter() {
//    board = vector<vector<Pixel>>(HEIGHT);
//    for (int i = 0; i < HEIGHT; ++i) {
//        board[i].resize(WIDTH);
//    }
//}

vector<Object> Painter::objects = vector<Object>();
vector<vector<Pixel>> Painter::board = vector<vector<Pixel>> (HEIGHT, vector<Pixel>(WIDTH));

void Painter::drawObject(const Object &o) {
    int row = o.row;
    int col = o.col;
//    vector<vector<Pixel> > pixels = o.pixels;
    if(o.pixels.empty()) return;
    for(int i = 0;i < o.pixels.size() && i + row < HEIGHT;i++){
        for (int j = 0; j < o.pixels[0].size() && j + col < WIDTH; ++j) {
            board[row + i][col + j] = o.pixels[i][j];
        }
    }
}

void Painter::addObject(const Object &o) {
    objects.push_back(o);
}

void Painter::updateScreen() {
    for(auto line: board) line.clear();
    sort(objects.begin(), objects.end());
    for(auto &object: objects) drawObject(object);
    printf("\033[H");
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int color = board[i][j].back;
//            printf("%d;%d;%d",(color&0xff0000) >> 16, (color&0xff00) >> 8, color&0xff);
            printf("\033[48;2;%d;%d;%dm",(color&0xff0000) >> 16, (color&0xff00) >> 8, color&0xff);
            cout << board[i][j].ch;
            cout << "\033[0m";
        }
        cout << endl;
    }
}