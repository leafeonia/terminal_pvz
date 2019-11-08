#include "common.h"
#include "objects.h"
#include "Painter.h"
#include "Game.h"



void* listenKey(void* ptr){
    Game* g = (Game*)ptr;
    while(1){
        usleep(10000);
        system("stty -icanon -echo");
        char ch = getchar();
        system("stty icanon echo");
        g->inputHandler(ch);
    }
}

int main() {
    Game g;
    g.init_screen();
    pthread_t t;
    pthread_create(&t, NULL, listenKey, (void*)(&g));
    while(1){
        usleep(500000);
        g.sendTimeSignal();
    }
    return 0;
}