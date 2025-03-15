#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

class BattleSystem {
private:
    int difficulty;
    std::unique_ptr<Enemy> enemy;

public:
    BattleSystem(int diff);
    void setDifficulty(int diff);
    Enemy& getEnemy();
    const Enemy& getEnemy() const;
};

#endif // BATTLESYSTEM_H


