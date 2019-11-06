//
// Created by leafeon on 11/6/19.
//

#ifndef PVZ_GAME_H
#define PVZ_GAME_H

#include "common.h"
#include "objects.h"
#include <pthread.h>

class Game{
private:
    int sunshine, score;
    int shop_idx, board_row, board_col;
    vector<int> shop_col;
    int shop_row;
    string status;
    Cursor cursor;
    pthread_mutex_t mutex_lock;
public:
    Game();
    void init_screen();
    void inputHandler(char ch);
};

#endif //PVZ_GAME_H
