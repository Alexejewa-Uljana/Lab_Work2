#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

class BattleSystem {
private:
    int difficulty;  // Уровень сложности (1 - простой, 2 - средний, 3 - сложный)
    std::unique_ptr<Enemy> enemy;  // Указатель на текущего врага

public:
    BattleSystem(int diff);
    
    void setDifficulty(int diff);
    Enemy& getEnemy();
    const Enemy& getEnemy() const;
};

#endif // BATTLESYSTEM_H


