#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include "Enemy.h"
#include "Boss.h"

class BattleSystem {
public:
    BattleSystem(int difficulty);
    ~BattleSystem() = default;
    Enemy* createEnemy();

private:
    int difficulty;
};

#endif
