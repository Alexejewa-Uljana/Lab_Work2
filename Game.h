#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "BattleSystem.h"

class Game {
public:
    Game();
    void start();
    void battle();

private:
    Player player;
    Enemy enemy;
    BattleSystem battleSystem;
};

#endif
