//
// Created by leafeon on 11/6/19.
//

#include "objects.h"
#include "Painter.h"
#include "Game.h"

int Object::cnt = 0;

Grassland::Grassland(int r, int c) {
    row = r;
    col = c;
    priority = PRI_BACKGROUND;
    int w = WIDTH / NR_COL;
    int h = HEIGHT / NR_ROW;
    for (int i = 0; i < h; ++i) {
        vector<Pixel> line;
        if(i == h - 1){
            for (int j = 0; j < w - 1; ++j) {
                line.push_back(Pixel(' ', DARKGREEN));
            }
            line.push_back(Pixel(' ', DEEPGREEN));
        }
        else{
            //line.push_back(Pixel(' ', DARKGREEN));
            for (int j = 0; j < w; ++j) {
                line.push_back(Pixel(' ', GREEN));
            }
            //line.push_back(Pixel(' ', DARKGREEN));
        }
        pixels.push_back(line);
    }
}

Shop::Shop() {
    row = HEIGHT;
    col = 0;
    priority = PRI_BACKGROUND;
    int w = WIDTH;
    int h = SHOP_HEIGHT;
    for (int i = 0; i < h; ++i) {
        vector<Pixel> line;
        vector<int> colors = {RED, ORANGE, YELLOW, GREEN, INDIGO, BLUE, PURPLE};
        if(i == 0 || i == h - 1){
            for (int j = 0; j < w; ++j) {
                line.push_back(Pixel(' ', colors[j % colors.size()]));
            }
        }
        else if(i == h / 2){
            for (int j = 0; j < 8; ++j) {
                line.push_back(Pixel(' ', DARKPURPLE));
            }
            for (auto ch: "peanut shooter 100") {
                line.push_back(Pixel(ch, DARKPURPLE));
            }
            for (int j = 0; j < 8; ++j) {
                line.push_back(Pixel(' ', DARKPURPLE));
            }
            for (auto ch: "sunflower 50") {
                line.push_back(Pixel(ch, DARKPURPLE));
            }
            for (int j = 16 + strlen("peanut shooter 100") + strlen("sunflower 50"); j < WIDTH; ++j) {
                line.push_back(Pixel(' ', DARKPURPLE));
            }
        }
        else{
            for (int j = 0; j < w; ++j) {
                line.push_back(Pixel(' ', DARKPURPLE));
            }
        }
        pixels.push_back(line);
    }
}

Cursor::Cursor(int r, int c) {
    row = r;
    col = c;
    priority = PRI_CURSOR;
    vector<Pixel> line;
    for (int j = 0; j < 2; ++j) {
        line.push_back(Pixel(' ', WHITE));
    }
    pixels.push_back(line);
}

InfoBoard::InfoBoard() {
    row = HEIGHT + 2;
    col = WIDTH - 30;
    priority = PRI_UNIT;
    vector<Pixel> line;
    for(auto ch: "sunshine: 0   score: 0") line.push_back(Pixel(ch, DARKPURPLE));
    pixels.push_back(line);
}

void InfoBoard::clockHandler() {
    vector<Pixel> line;
    string info = "sunshine: " + to_string(Game::sunshine) + "   score: " + to_string(Game::score);
    for(auto ch: info) line.push_back(Pixel(ch, DARKPURPLE));
    vector<vector<Pixel> > tmp;
    tmp.push_back(line);
    Painter::updateObject(*this, row, col, tmp);
}

bool Plant::updateHp() {
    if(hp <= 0) return true;
    int width = pixels[0].size();
    string s_hp = to_string(hp);
    vector<Pixel> hp_bar;
    for (int i = 0; i < width - s_hp.length(); ++i) {
        hp_bar.push_back(Pixel(' ', RED));
    }
    for (int i = 0; i < s_hp.length(); ++i) {
        hp_bar.push_back(Pixel(s_hp[i],RED));
    }
    for (int i = 0; i < s_hp.length(); ++i) {
        pixels[pixels.size() - 1] = hp_bar;
    }
    Painter::updateObject(*this, row, col, pixels);
    return false;
}

PeanutShooter::PeanutShooter(int r, int c):Plant(PEANUT_HP, PEANUT_ATK, PEANUT_COST) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    vector<char> chars = {
            '/','^','\\','_','_',
            '\\','_','/','-','-',
            ' ','|',' ',' ',' ',
            'x','-','x',' ',' ',
            ' ','1','0','0',' '
    };
    vector<int> colors = {
            DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,
            DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,DEEPGREEN,
            GREEN,DEEPGREEN,GREEN,GREEN,GREEN,
            DEEPGREEN,DEEPGREEN,DEEPGREEN,GREEN,GREEN,
            RED,RED,RED,RED,RED
    };
    pixels = Painter::pixmapGenerate(5,5,chars,colors);
}

void PeanutShooter::clockHandler() {
    timer++;
    if(timer == 10){
        timer = 0;
        Bullet *bullet = new Bullet(row + 1, col + 4, attack);
        Game::addUnit(bullet);
    }
}

bool PeanutShooter::interactWithZombie(Zombie* zombie) {
    int zr = zombie->getRow();
    int zc = zombie->getCol();
    if(zr >= row - 2 && zr <= row && zc <= col + 5 && timer % 5 == 0) {
        hp -= zombie->getAtk();
        zombie->setMove(0);
    }
    return false;
}

Sunflower::Sunflower(int r, int c): Plant(SUNFLOWER_HP, SUNFLOWER_ATK, SUNFLOWER_COST) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    vector<char> chars = {
            'o','o','o',
            'o','x','o',
            'o','o','o',
            '\\','|','/',
            ' ','5','0'
    };
    vector<int> color = {
            YELLOW,YELLOW,YELLOW,
            YELLOW,BROWN,YELLOW,
            YELLOW,YELLOW,YELLOW,
            DEEPGREEN,DEEPGREEN,DEEPGREEN,
            RED,RED,RED
    };
    pixels = Painter::pixmapGenerate(5,3,chars,color);
}

void Sunflower::clockHandler() {
    timer++;
    if(timer == 10){
        timer = 0;
        Game::addSunshine(50);
    }
}

bool Sunflower::interactWithZombie(Zombie *zombie) {
    int zr = zombie->getRow();
    int zc = zombie->getCol();
    if(zr >= row - 2 && zr <= row && zc <= col + 4) {
        hp -= zombie->getAtk();
        zombie->setMove(0);
    }
    return false;
}

Bullet::Bullet(int r, int c, int a) {
    row = r;
    col = c;
    atk = a;
    priority = PRI_BULLET;
    type = "bullet";
    vector<Pixel> line;
    line.push_back(Pixel('(', DEEPGREEN));
    line.push_back(Pixel(')', DEEPGREEN));
    pixels.push_back(line);
}

void Bullet::clockHandler() {
    col++;
    Painter::updateObject(*this, row, col);
}

bool Bullet::interactWithZombie(Zombie *zombie) {
    int zr = zombie->getRow();
    int zc = zombie->getCol();
    if(zr >= row - 2 && zr <= row && zc >= col - 1 && zc <= col) {
        zombie->loseHp(atk);
        return true;
    }
    return false;
}

bool Zombie::updateHp() {
    if(hp <= 0) return true;
    string s_hp = to_string(hp);
    vector<Pixel> hp_bar;
    for (int i = 0; i < 3 - s_hp.length(); ++i) {
        hp_bar.push_back(Pixel(' ', RED));
    }
    for (int i = 0; i < s_hp.length(); ++i) {
        hp_bar.push_back(Pixel(s_hp[i],RED));
    }
    for (int i = 0; i < s_hp.length(); ++i) {
        pixels[pixels.size() - 1] = hp_bar;
    }
    Painter::updateObject(*this, row, col, pixels);
    return false;
}

NormalZombie::NormalZombie(int r,int c):Zombie(500, 10, 5) {
    row = r;
    col = c;
    priority = PRI_BULLET;
    vector<char> chars = {
            ' ','o',' ',
            '/','x','\\',
            ' ','|',' ',
            '/',' ','\\',
            '5','0','0'
    };
    vector<int> colors = {
            GREEN,GREY,GREEN,
            GREY,GREY,GREY,
            GREEN,GREY,GREEN,
            GREY,GREEN,GREY,
            RED, RED, RED

    };
    pixels = Painter::pixmapGenerate(5, 3, chars, colors);
}

void NormalZombie::clockHandler() {
    timer++;
    if(timer == speed){
        timer = 0;
        if(move == 1) col--;
        else if(move == 0) move = 1;
        Painter::updateObject(*this, row, col);
    }

}

