#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include "TurnManager.h"
#include "Player.h"
#include "Enemy.h"

class BattleSystem {
public:
    void startBattle(Player& player, Enemy& enemy);
};

#endif
