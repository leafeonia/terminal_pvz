//
// Created by leafeon on 11/6/19.
//

#include "objects.h"
#include "Painter.h"
#include "Game.h"
#include "pixmap.h"

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
        else if(i == h / 2 - 1){
            string s = "        peashooter        sunflower        garlic        wallnut        snowpea";
            for (auto ch: s) line.push_back(Pixel(ch, DARKPURPLE));
            for (int j = s.length();j < WIDTH;j++) line.push_back(Pixel(' ', DARKPURPLE));
        }
        else if(i == h / 2 + 1){
            string s = "           100                50             50             50            150  ";
            for (auto ch: s) line.push_back(Pixel(ch, DARKPURPLE));
            for (int j = s.length();j < WIDTH;j++) line.push_back(Pixel(' ', DARKPURPLE));
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
    pixels = Painter::pixmapGenerate(5,5,peanutChars,peanutColor);
}

void PeanutShooter::clockHandler() {
    timer++;
    if(timer == 25){
        timer = 0;
        Bullet *bullet = new Bullet(row + 1, col + 4, attack);
        Game::addUnit(bullet);
    }
}

bool PeanutShooter::interactWithZombie(Zombie* zombie) {
    int zr = zombie->getRow();
    int zc = zombie->getCol();
    if(zr >= row - 2 && zr <= row && zc >= col - 2 && zc <= col + 5) {
        if(timer % 10 == 0) hp -= zombie->getAtk();
        if(zombie->getMove() == 100) zombie->setMove(0);
    }
    return false;
}

Sunflower::Sunflower(int r, int c): Plant(SUNFLOWER_HP, SUNFLOWER_ATK, SUNFLOWER_COST) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    pixels = Painter::pixmapGenerate(5,3,sunflowerChars,sunflowerColor);
}

void Sunflower::clockHandler() {
    timer++;
    if(timer == 100){
        timer = 0;
        Game::addSunshine(50);
    }
}

bool Sunflower::interactWithZombie(Zombie *zombie) {
    int zr = zombie->getRow();
    int zc = zombie->getCol();
    if(zr >= row - 2 && zr <= row && zc >= col - 2 && zc <= col + 3) {
        if(timer % 10 == 0)hp -= zombie->getAtk();
        if(zombie->getMove() == 100) zombie->setMove(0);
    }
    return false;
}

Garlic::Garlic(int r, int c): Plant(GARLIC_HP, GARLIC_ATK, GARLIC_COST) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    protection_time = 10;
    pixels = Painter::pixmapGenerate(4, 4, garlicChars, garlicColor);
}

void Garlic::clockHandler() {if(protection_time > 0) protection_time--;}

bool Garlic::interactWithZombie(Zombie *zombie) {
    int zr = zombie->getRow();
    int zc = zombie->getCol();
    if(zr == row - 1 && zc >= col - 2 && zc <= col + 4) {
        if(protection_time == 0) {
            hp -= zombie->getAtk();
            protection_time = 10;
        }
        if(zr < (HEIGHT / NR_ROW)) zombie->setMove(-HEIGHT / NR_ROW); // FIRST LINE, MUST GO DOWN
        else if(zr > (NR_ROW - 1) * (HEIGHT / NR_ROW)) zombie->setMove(HEIGHT / NR_ROW); //LAST LINE, MUST GO UP
        else{
            int coin = rand() % 2 * 2 - 1; //1 or -1
            zombie->setMove(coin * (HEIGHT / NR_ROW));
        }
    }
    return false;
}

Wallnut::Wallnut(int r, int c):Plant(WALLNUT_HP, WALLNUT_ATK, WALLNUT_COST) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    pixels = Painter::pixmapGenerate(5, 5, wallnutChars, wallnutColor);
}

void Wallnut::clockHandler() {timer++;}

bool Wallnut::interactWithZombie(Zombie *zombie) {
    if(hp < 200) pixels[2][2] = Pixel('^',BROWN);
    int zr = zombie->getRow();
    int zc = zombie->getCol();
    if(zr >= row - 2 && zr <= row && zc >= col - 2 && zc <= col + 5) {
        if(timer % 10 == 0)hp -= zombie->getAtk();
        if(zombie->getMove() == 100) zombie->setMove(0);
    }
    return false;
}

SnowPea::SnowPea(int r, int c): Plant(SNOW_HP, SNOW_ATK, SNOW_COST) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    pixels = Painter::pixmapGenerate(5,5,peanutChars, snowpeaColor);
}

void SnowPea::clockHandler() {
    timer++;
    if(timer == 30){
        timer = 0;
        FrozenBullet *bullet = new FrozenBullet(row + 1, col + 4, attack);
        Game::addUnit(bullet);
    }
}

bool SnowPea::interactWithZombie(Zombie *zombie) {
    int zr = zombie->getRow();
    int zc = zombie->getCol();
    if(zr >= row - 2 && zr <= row && zc >= col - 2 && zc <= col + 5) {
        if(timer % 10 == 0) hp -= zombie->getAtk();
        if(zombie->getMove() == 100) zombie->setMove(0);
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

FrozenBullet::FrozenBullet(int r, int c, int a):Bullet(r,c,a) {}

bool FrozenBullet::interactWithZombie(Zombie *zombie) {
    int zr = zombie->getRow();
    int zc = zombie->getCol();
    if(zr >= row - 2 && zr <= row && zc >= col - 1 && zc <= col) {
        zombie->loseHp(atk);
        zombie->setSpeed(zombie->getSpeed() + 5);
        return true;
    }
    return false;
}

bool Zombie::updateHp() {
    if(hp <= 0) {
        Game::addScore(score);
        return true;
    }
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

NormalZombie::NormalZombie(int r,int c):Zombie(NORMALZB_HP, NORMALZB_ATK, NORMALZB_SPEED, NORMALZB_SCORE) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    pixels = Painter::pixmapGenerate(5, 3, normalZombieChars, normalZombieColor);
}

void NormalZombie::clockHandler() {
    if(hp < 150){
        pixels[1][2] = Pixel(' ', GREEN);
    }
    timer++;
    if(timer == speed){
        timer = 0;
        if(move == 100) col--;
        else if(move == 0) move = 100;
        else if(move < 0){
            row++;
            move++;
        }
        else{
            row--;
            move--;
        }
        Painter::updateObject(*this, row, col);
        if(col == 0){
            Painter::updateScreen();
            Painter::gameover();
        }
    }

}

FlagZombie::FlagZombie(int r, int c): Zombie(NORMALZB_HP, NORMALZB_ATK, FLAGZB_SPEED, FLAGZB_SCORE) {
    row = r;
    col = c;
    priority = PRI_UNITPLUS;
    pixels = Painter::pixmapGenerate(5, 4, flagZombieChars, flagZombieColor);
}

void FlagZombie::clockHandler() {
    if(hp < 150){
        pixels[1][3] = Pixel(' ', GREEN);
    }
    timer++;
    if(timer == speed){
        timer = 0;
        if(move == 100) col--;
        else if(move == 0) move = 100;
        else if(move < 0){
            row++;
            move++;
        }
        else{
            row--;
            move--;
        }
        Painter::updateObject(*this, row, col);
        if(col == 0){
            Painter::updateScreen();
            Painter::gameover();
        }
    }
}

ConeheadZombie::ConeheadZombie(int r, int c):Zombie(CONEZB_HP, NORMALZB_ATK, NORMALZB_SPEED, CONEZB_SCORE) {
    row = r;
    col = c;
    priority = PRI_UNIT;
    pixels = Painter::pixmapGenerate(5, 3, coneZombieChars,coneZombieColor);
}

void ConeheadZombie::clockHandler() {
    timer++;
    if(hp < 150){
        pixels[1][2] = Pixel(' ', GREEN);
    }
    if(hp < NORMALZB_HP) {
        pixels[0][1] = Pixel('o', GREY);
    }
    if(timer == speed){
        timer = 0;
        if(move == 100) col--;
        else if(move == 0) move = 100;
        else if(move < 0){
            row++;
            move++;
        }
        else{
            row--;
            move--;
        }
        Painter::updateObject(*this, row, col);
        if(col == 0){
            Painter::updateScreen();
            Painter::gameover();
        }
    }
}