//
// Created by leafeon on 11/6/19.
//

#include "Game.h"
#include "Painter.h"

Game::Game():cursor(10000,10000) { //I'm so far far away that you can't see me~
    srand(time(NULL));
    status = "idle";
    shop_row = HEIGHT + SHOP_HEIGHT / 2 - 1;
    shop_col = vector<int>{5, 23, 40, 54, 69};
    shop_idx = board_row = board_col = 0;
//    pthread_mutex_init(&mutex_lock, NULL);
    sunshine_timer = 0;
    zombie_wave = 0;
    difficulty = 5000;
//    sunshine = score = 0;
}

int Game::score = 0;
int Game::sunshine = 50;
vector<Unit*> Game::units = vector<Unit*>();

void Game::init_screen() {
    system("clear");
    for (int i = 0; i < NR_ROW; ++i) {
        for (int j = 0; j < NR_COL; ++j) {
            Painter::addObject(Grassland(i * (HEIGHT / NR_ROW), j * (WIDTH / NR_COL)));
        }
    }
    Painter::addObject(Shop());
    Painter::addObject(cursor);
    addUnit(&infoBoard);
//    NormalZombie* normalZombie = new NormalZombie(1,10);
//    addUnit(normalZombie);
    Painter::updateScreen();
}

void Game::inputHandler(char ch) {
//    pthread_mutex_lock(&mutex_lock);
    if(ch == 'b' && status == "idle"){
        Painter::updateObject(cursor, shop_row, shop_col[shop_idx]);
        Painter::updateScreen();
        status = "shop";
    }
    else if(ch == 'c' && status == "idle"){
        Painter::updateObject(cursor, board_row * (HEIGHT / NR_ROW) + HEIGHT / NR_ROW / 2,
                              board_col * (WIDTH / NR_COL) + WIDTH / NR_COL / 2);
        Painter::updateScreen();
        status = "uproot";
    }
    else if(status == "shop"){
        if(ch == 'd'){
            shop_idx = (shop_idx + 1) % shop_col.size();
            Painter::updateObject(cursor, shop_row, shop_col[shop_idx]);
            Painter::updateScreen();
        }
        if(ch == 'a'){
            shop_idx = shop_idx == 0 ? shop_col.size() - 1 : shop_idx - 1;
            Painter::updateObject(cursor, shop_row, shop_col[shop_idx]);
            Painter::updateScreen();
        }
        if(ch == '\n'){
            Painter::updateObject(cursor, board_row * (HEIGHT / NR_ROW) + HEIGHT / NR_ROW / 2,
                                  board_col * (WIDTH / NR_COL) + WIDTH / NR_COL / 2);
            Painter::updateScreen();
            status = "set";
        }
        if(ch == 'x'){
            Painter::updateObject(cursor, 10000, 10000);
            Painter::updateScreen();
            status = "idle";
        }
    }
    else if(status == "set" || status == "uproot"){
        if(ch == 'x'){
            Painter::updateObject(cursor, 10000, 10000);
            Painter::updateScreen();
            status = "idle";
        }
        else if(ch == 'd' || ch == 'a' || ch == 'w' || ch == 's'){
            if(ch == 'd') board_col = board_col == NR_COL - 1 ? 0 : board_col + 1;
            else if(ch == 'a') board_col = board_col == 0 ? NR_COL - 1 : board_col - 1;
            else if(ch == 'w') board_row = board_row == 0 ? NR_ROW - 1 : board_row - 1;
            else if(ch == 's') board_row = board_row == NR_ROW - 1 ? 0 : board_row + 1;
            Painter::updateObject(cursor, board_row * (HEIGHT / NR_ROW) + HEIGHT / NR_ROW / 2,
                                  board_col * (WIDTH / NR_COL) + WIDTH / NR_COL / 2);
            Painter::updateScreen();
        }
        else if(ch == '\n'){
            int pos_row = 1 + board_row * (HEIGHT / NR_ROW);
            int pos_col = 5 + board_col * (WIDTH / NR_COL);
            if(status == "set"){
                if(shop_idx == 0 && Game::setAvailable(pos_row, pos_col) && consumeSunshine(PEANUT_COST) ) {
                    PeanutShooter* peanutShooter = new PeanutShooter(pos_row, pos_col);
                    addUnit(peanutShooter);
                }
                else if(shop_idx == 1 && Game::setAvailable(pos_row, pos_col) && consumeSunshine(SUNFLOWER_COST) ){
                    Sunflower* sunflower = new Sunflower(pos_row, pos_col);
                    addUnit(sunflower);
                }
                else if(shop_idx == 2 && Game::setAvailable(pos_row, pos_col) && consumeSunshine(GARLIC_COST)){
                    Garlic* garlic = new Garlic(pos_row + 1, pos_col);
                    addUnit(garlic);
                }
                else if(shop_idx == 3 && Game::setAvailable(pos_row, pos_col) && consumeSunshine(WALLNUT_COST)){
                    Wallnut* wallnut = new Wallnut(pos_row, pos_col);
                    addUnit(wallnut);
                }
                else if(shop_idx == 4 && Game::setAvailable(pos_row, pos_col) && consumeSunshine(SNOW_COST)){
                    SnowPea* snowpea = new SnowPea(pos_row, pos_col);
                    addUnit(snowpea);
                }
            }
            else{
                for (int i = 0; i < units.size(); ++i) {
                    if(units[i]->type == "plant" && units[i]->row == pos_row && units[i]->col == pos_col){
                        deleteUnit(units[i]->id);
                        break;
                    }
                }
            }
            Painter::updateObject(cursor, 10000, 10000);
            Painter::updateScreen();
            status = "idle";
        }
    }
//    pthread_mutex_unlock(&mutex_lock);
}

bool Game::setAvailable(int r, int c) {
    for (int i = 0; i < units.size(); ++i) {
        if (units[i]->row == r && units[i]->col == c && units[i]->type == "plant") return false;
    }
    return true;
}

void Game::addUnit(Unit* unit) {
    units.push_back(unit);
    Painter::addObject(*unit);
}

void Game::addSunshine(int num) {
    sunshine += num;
}

bool Game::consumeSunshine(int num) {
    if(sunshine < num) return false;
    sunshine -= num;
    return true;
}

void Game::addScore(int num) {
    score += num;
}

void Game::sendTimeSignal() {
    sunshine_timer++;
    if(sunshine_timer == 100){
        sunshine_timer = 0;
        if(difficulty > 1000) difficulty -= 100;
        addSunshine(50);
    }
    for(int i = 0;i < units.size();i++){
        units[i]->clockHandler();
    }
    interaction();
    generateZombie();
    Painter::updateScreen();
//    generateZombie();
}

void Game::interaction() {
    vector<int> toBeDeleted;
    for (int i = 0; i < units.size(); ++i) {
        if (units[i]->type == "zombie"){
            Zombie* zombie = dynamic_cast<Zombie*>(units[i]);
            if(!zombie) continue;
            for (int j = 0; j < units.size(); ++j) {
                if(units[j]->type == "plant"){
                    Plant* plant = dynamic_cast<Plant*>(units[j]);
                    if(!plant) continue;
                    if(plant->interactWithZombie(zombie)) toBeDeleted.push_back(units[j]->id);
                }
                else if(units[j]->type == "bullet"){
                    Bullet* bullet = dynamic_cast<Bullet*>(units[j]);
                    if(!bullet) continue;
                    if(bullet->col > WIDTH || bullet->interactWithZombie(zombie)) toBeDeleted.push_back(units[j]->id);
                }
            }
        }
    }
    for (int i = 0; i < units.size(); ++i) {
        if (units[i]->type == "zombie"){
            Zombie* zombie = dynamic_cast<Zombie*>(units[i]);
            if(!zombie) continue;
            if(zombie->updateHp()) toBeDeleted.push_back(units[i]->id);
        }
        else if (units[i]->type == "plant"){
            Plant* plant = dynamic_cast<Plant*>(units[i]);
            if(!plant) continue;
            if(plant->updateHp()) toBeDeleted.push_back(units[i]->id);
        }
    }
    for(auto unit: toBeDeleted) deleteUnit(unit);
}

void Game::deleteUnit(int unitId) {
    int idx = 0;
    while(idx < units.size()) {
        if(units[idx]->id == unitId){
            Unit* waste = units[idx];
            units.erase(units.begin() + idx);
            Painter::deleteObject(*waste);
            delete waste;

        }
        else idx++;
    }
}

void Game::generateZombie() {
    if(zombie_wave > 0){
//        cout << "Wait" << endl;
        zombie_wave--;
        if(zombie_wave % 50 == 0){
            for (int i = 0; i < NR_ROW; ++i) {
                addUnit(new NormalZombie(1 + i * (HEIGHT / NR_ROW), WIDTH));
            }
        }
        return;
    }
    int random = rand() % difficulty;
//    cout << random << endl;
    int row = 1 + random % 5 * HEIGHT / NR_ROW;
    if(random < 50){
//        cout << "Normal" << endl;
        addUnit(new NormalZombie(row, WIDTH));
    }
    else if(random < 60){
//        cout << "Flag" << endl;
        zombie_wave = 150;
        addUnit(new FlagZombie(1 + 2 * (HEIGHT / NR_ROW), WIDTH));
    }
    else if(random < 80){
//        cout << "Cone" << endl;
        addUnit(new ConeheadZombie(row, WIDTH));
    }
//    cout << random << endl;
}