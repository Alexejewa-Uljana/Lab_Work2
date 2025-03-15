#ifndef BOSS_AI_H
#define BOSS_AI_H

#include "Boss.h"
#include "Player.h"

class BossAI {
public:
    BossAI(Boss& boss);
    ~BossAI();
    void takeTurn(Boss& boss, Player& player);
    void attack(Boss& boss, Player& player);
    void castSpell(Boss& boss, Player& player);
private:
    Boss& boss;
    void makeDecision(Boss& boss, Player& player);
    void useSpecialAbility(Boss& boss, Player& player);
    void defend(Boss& boss);
};

#endif // BOSS_AI_H
