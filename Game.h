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
    static int sunshine, score;
    int shop_idx, board_row, board_col;
    vector<int> shop_col;
    int shop_row;
    int sunshine_timer; //automatic sunshine
    string status;
    Cursor cursor;
    InfoBoard infoBoard;
//    pthread_mutex_t mutex_lock;
    static vector<Unit*> units;
public:
    friend class InfoBoard;
    Game();
    void init_screen();
    void inputHandler(char ch);
    void sendTimeSignal();
    static void addUnit(Unit* unit);
    static void addSunshine(int num);
    static bool consumeSunshine(int num);
    static void addScore(int num);
};

#endif //PVZ_GAME_H
