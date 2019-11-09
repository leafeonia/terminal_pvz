//
// Created by leafeon on 11/6/19.
//

#ifndef PVZ_OBJECTS_H
#define PVZ_OBJECTS_H

#include "common.h"

class Object{
private:
    static int cnt;
protected:
    int row, col, priority, id;
    vector<vector<Pixel>> pixels;
public:
    Object(){id = cnt++;}
    friend class Painter;
    friend class Game;
    bool operator < (const Object& o){return priority < o.priority;}
};

class Grassland: public Object{
public:
    Grassland(int r,int c);
};

class Shop: public Object{
public:
    Shop();
};

class Cursor: public Object{
public:
    Cursor(int r, int c);
};


class Unit: public Object{
protected:
    int timer;
    string type;
public:
    friend class Game;
    Unit(){timer = 0;type = "Undefined";}
    virtual void clockHandler()=0;
};

class InfoBoard: public Unit {
public:
    InfoBoard();
    void clockHandler();
};

class Zombie: public Unit{
protected:
    int hp, attack, speed, move;
public:
    Zombie(int h,int a,int s){hp = h; attack = a;speed = s; move = 1; type = "zombie";}
    void setMove(int val){move = val;}
    void loseHp(int val){hp -= val;}
    bool updateHp();
    int getAtk(){return attack;}
    int getRow(){return row;}
    int getCol(){return col;}
};

class NormalZombie: public Zombie{
public:
    NormalZombie(int r,int c);
    void clockHandler();
};

class Plant: public Unit{
protected:
    int hp, attack, cost;
public:
    Plant(int h, int a, int c){hp = h; attack = a;cost = c; type = "plant";}
    bool updateHp();
    virtual bool interactWithZombie(Zombie* zombie)=0;
};

class PeanutShooter: public Plant{
public:
    PeanutShooter(int r, int c);
    void clockHandler();
    bool interactWithZombie(Zombie* zombie);
};

class Sunflower: public Plant{
public:
    Sunflower(int r,int c);
    void clockHandler();
    bool interactWithZombie(Zombie* zombie);
};

class Bullet: public Unit{
    int atk;
public:
    Bullet(int r,int c,int a);
    void clockHandler();
    bool interactWithZombie(Zombie* zombie);
};


#endif //PVZ_OBJECTS_H
