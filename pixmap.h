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
        BLUE,BLUE,BLUE,BLUE,BLUE,
        BLUE,BLUE,BLUE,BLUE,BLUE,
        GREEN,BLUE,GREEN,GREEN,GREEN,
        BLUE,BLUE,BLUE,GREEN,GREEN,
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

#endif //PVZ_PIXMAP_H
