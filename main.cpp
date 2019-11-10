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

void restore_flash(){
    cout << "\033[?25h" << endl;
}

int main() {
    Game g;
    g.init_screen();
    cout << "\033[?25l" << endl;
    pthread_t t;
    pthread_create(&t, NULL, listenKey, (void*)(&g));
    atexit(restore_flash);
    while(1){
        usleep(10000);
        g.sendTimeSignal();
    }
    return 0;
}