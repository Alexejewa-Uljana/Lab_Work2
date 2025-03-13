#include "BossAI.h"
#include <iostream>

BossAI::BossAI(Enemy& b) : boss(b) {}

void BossAI::makeMove(Player* target) {
    if (target) {
        std::cout << "Boss is attacking " << target->getHP() << " HP remaining!\n";
    }
    else {
        std::cout << "BossAI: No valid player to attack!\n";
    }
}
