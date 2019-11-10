//
// Created by leafeon on 11/9/19.
//

#ifndef PVZ_PIXMAP_H
#define PVZ_PIXMAP_H

#include "common.h"

vector<char> peanutChars = {
        '/','^','\\','_','_',
        '\\','_','/','-','-',
        ' ','|',' ',' ',' ',
        'x','-','x',' ',' ',
        ' ',' ','1','0','0'
};

vector<int> peanutColor = {
        DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,
        DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,
        GREEN,DEEPGREEN,GREEN,GREEN,GREEN,
        DEEPGREEN,DEEPGREEN,DEEPGREEN,GREEN,GREEN,
        RED,RED,RED,RED,RED
};

vector<int> snowpeaColor = {
        INDIGO,INDIGO,INDIGO,INDIGO,INDIGO,
        INDIGO,INDIGO,INDIGO,INDIGO,INDIGO,
        GREEN,INDIGO,GREEN,GREEN,GREEN,
        DEEPGREEN, DEEPGREEN, DEEPGREEN,GREEN,GREEN,
        RED,RED,RED,RED,RED
};

vector<char> sunflowerChars = {
        'o','o','o',
        'o','x','o',
        'o','o','o',
        '\\','|','/',
        ' ','5','0'
};

vector<int> sunflowerColor = {
        YELLOW,YELLOW,YELLOW,
        YELLOW,BROWN,YELLOW,
        YELLOW,YELLOW,YELLOW,
        DEEPGREEN,DEEPGREEN,DEEPGREEN,
        RED,RED,RED
};

vector<char> garlicChars = {
        ' ','W','W',' ',
        '/','.','.','\\',
        '\\','~','~','/',
        ' ',' ','4','0'
};

vector<int> garlicColor = {
        GREEN, LIGHTGREY, LIGHTGREY, GREEN,
        LIGHTGREY, LIGHTGREY, LIGHTGREY, LIGHTGREY,
        LIGHTGREY, LIGHTGREY, LIGHTGREY, LIGHTGREY,
        RED, RED, RED, RED
};

vector<char> thornChars = {
        '^','^','^','^','^','^'
};

vector<int> thornColor = {
        BROWN,BROWN,BROWN,BROWN,BROWN,BROWN
};

vector<char> wallnutChars = {
        '/','-','-','-','\\',
        '|','.',' ','.','|',
        '|',' ','w',' ','|',
        '\\','_','_','_','/',
        ' ',' ','5','0','0'
};

vector<int> wallnutColor = {
        BROWN, BROWN, BROWN, BROWN, BROWN,
        BROWN, BROWN, BROWN, BROWN, BROWN,
        BROWN, BROWN, BROWN, BROWN, BROWN,
        BROWN, BROWN, BROWN, BROWN, BROWN,
        RED, RED, RED, RED, RED
};

vector<char> pepperChars = {
        ' ','^',' ',' ',
        '(','o','o',')',
        ' ','\\','^','|',
        ' ',' ','v',' '
};

vector<int> pepperColor = {
        GREEN, DEEPGREEN, GREEN, GREEN,
        RED, RED, RED, RED,
        GREEN, RED, RED, RED,
        GREEN, GREEN, RED, GREEN
};

vector<char> watermelonChars = {
        '(','O',')',' ',' ',
        ' ','\\','_','_',' ',
        '/','>',' ','<','\\',
         '\\','_','w','_','/',
         ' ',' ','1','0','0'
};

vector<int> watermelonColors = {
        DEEPGREEN, DARKGREEN, DEEPGREEN, GREEN, GREEN,
        GREEN, DEEPGREEN, GREEN, GREEN, GREEN,
        DEEPGREEN, DARKGREEN, DEEPGREEN, DARKGREEN, DEEPGREEN,
        DEEPGREEN, DARKGREEN, DEEPGREEN, DARKGREEN, DEEPGREEN,
        RED, RED, RED, RED,RED
};

vector<char> normalZombieChars = {
        ' ','o',' ',
        '/','x','\\',
        ' ','|',' ',
        '/',' ','\\',
        '3','0','0'
};

vector<int> normalZombieColor = {
        GREEN,GREY,GREEN,
        GREY,GREY,GREY,
        GREEN,GREY,GREEN,
        GREY,GREEN,GREY,
        RED, RED, RED

};

vector<char> flagZombieChars = {
        '[',']','o',' ',
        ' ','|','x','-',
        ' ',' ','|',' ',
        ' ','|',' ','\\',
        ' ','3','0','0'

};

vector<int> flagZombieColor = {
        RED, RED, GREY, GREEN,
        GREEN, BROWN, GREY, GREY,
        GREEN, GREEN, GREY, GREEN,
        GREEN, GREY, GREEN, GREY,
        RED, RED, RED, RED
};

vector<char> coneZombieChars = {
        ' ','^',' ',
        '/','x','\\',
        ' ','|',' ',
        '/',' ','\\',
        '8','0','0'
};

vector<int> coneZombieColor = {
        GREEN,ORANGE,GREEN,
        GREY,GREY,GREY,
        GREEN,GREY,GREEN,
        GREY,GREEN,GREY,
        RED, RED, RED
};

vector<char> footballZombieChars = {
        ' ','o',' ',
        '/','*','\\',
        ' ','X', ' ',
        '/',' ','\\',
        '9','0','0'
};

vector<int> footballZombieColor = {
        GREEN,GREY,GREEN,
        RED,GREY,RED,
        GREEN,RED,GREEN,
        RED,GREEN,RED,
        RED, RED, RED
};

vector<char> dancingKingChars = {
        ' ','o',' ',
        '/','-','/',
        ' ','K', ' ',
        '/',' ','\\',
        '5','0','0'
};

vector<int> dancingKingColor = {
        GREEN,GREY,GREEN,
        PURPLE,PURPLE,PURPLE,
        GREEN,PURPLE,GREEN,
        PURPLE,GREEN,PURPLE,
        RED, RED, RED
};

vector<char> dancingGuyChars = {
        ' ','o',' ',
        '/','-','/',
        ' ','|', ' ',
        '/',' ','\\',
        '3','0','0'
};

vector<int> dancingGuyColor = {
        GREEN,GREY,GREEN,
        INDIGO,GREY,INDIGO,
        GREEN,INDIGO,GREEN,
        INDIGO,GREEN,INDIGO,
        RED, RED, RED
};

vector<char> newspaperZombieChar = {
        ' ','o',' ',
        '[','=',']',
        ' ','|',' ',
        '/',' ','\\',
        '4','0','0'
};

vector<int> newspaperZombieColor = {
        GREEN, GREY, GREEN,
        LIGHTGREY, LIGHTGREY, LIGHTGREY,
        GREEN, GREY, GREEN,
        GREY, GREEN, GREY,
        RED, RED, RED
};
#endif //PVZ_PIXMAP_H
