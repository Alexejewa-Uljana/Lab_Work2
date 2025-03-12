#ifndef BOSS_AI_H
#define BOSS_AI_H

#include "Enemy.h"

class BossAI {
public:
    BossAI(Enemy& boss);
    void makeMove(Player* target);

private:
    Enemy& boss;
};

#endif
