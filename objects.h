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
    bool operator < (const Object& o){return priority == o.priority ? id < o.id : priority < o.priority;}
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
    int hp, attack, speed, move, score, slowed;
public:
    Zombie(int h,int a,int sp, int sc){hp = h; attack = a;speed = sp; score = sc; slowed = false; move = 100; type = "zombie";}
    int getMove(){return move;}
    void setMove(int val){move = val;}
//    void setSpeed(int val){speed = val;}
//    int getSpeed(){return speed;}
    virtual void loseHp(int val){hp -= val;}
    bool updateHp();
    int getAtk(){return attack;}
    int getRow(){return row;}
    int getCol(){return col;}
    void getFrozen();
};

class NormalZombie: public Zombie{
public:
    NormalZombie(int r,int c);
    void clockHandler();
};

class FlagZombie: public Zombie{
public:
    FlagZombie(int r,int c);
    void clockHandler();
};

class FootballZombie: public Zombie{
public:
    FootballZombie(int r,int c);
    void clockHandler();
    void loseHp(int val);
};

class ConeheadZombie: public Zombie{
public:
    ConeheadZombie(int r,int c);
    void clockHandler();
};

class DancingKingZombie: public Zombie{
public:
    DancingKingZombie(int r,int c);
    void clockHandler();
};

class DancingGuyZombie: public Zombie{
public:
    DancingGuyZombie(int r,int c);
    void clockHandler();
};

class NewspaperZombie: public Zombie{
public:
    NewspaperZombie(int r,int c);
    void clockHandler();
};

class Plant: public Unit{
protected:
    int hp, attack, cost;
public:
    Plant(int h, int a, int c){hp = h; attack = a;cost = c; type = "plant";}
    virtual bool updateHp();
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

class Garlic: public Plant{
    int protection_time;
public:
    Garlic(int r,int c);
    void clockHandler();
    bool interactWithZombie(Zombie* zombie);
};

class Wallnut: public Plant{
public:
    Wallnut(int r,int c);
    void clockHandler();
    bool interactWithZombie(Zombie* zombie);
};

class Thorn: public Plant{
public:
    Thorn(int r,int c);
    void clockHandler();
    bool interactWithZombie(Zombie* zombie);
    bool updateHp();
};

class Pepper: public Plant{
public:
    Pepper(int r,int c);
    void clockHandler();
    bool interactWithZombie(Zombie* zombie);
    bool updateHp();
};

class SnowPea: public Plant{
public:
    SnowPea(int r,int c);
    void clockHandler();
    bool interactWithZombie(Zombie* zombie);
};

class Watermelon: public Plant{
public:
    Watermelon(int r,int c);
    void clockHandler();
    bool interactWithZombie(Zombie* zombie);
};

class Bullet: public Unit{
protected:
    int atk;
public:
    Bullet(int r,int c,int a);
    void clockHandler();
    virtual bool interactWithZombie(Zombie* zombie);
};

class Pea: public Bullet{
public:
    Pea(int r,int c,int a);
};

class FrozenBullet: public Bullet{
public:
    FrozenBullet(int r,int c,int a);
    bool interactWithZombie(Zombie* zombie);
    bool updateHp();
};

class Melon: public Bullet{
public:
    Melon(int r,int c,int a);
};


#endif //PVZ_OBJECTS_H
