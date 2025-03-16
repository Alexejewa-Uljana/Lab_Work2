#include "BattleSystem.h"
#include <iostream>

BattleSystem::BattleSystem(int difficulty) : difficulty(difficulty) {}

Enemy* BattleSystem::createEnemy() {
    if (difficulty == 1) {
        return new Enemy("Goblin", 30);
    } else if (difficulty == 2) {
        return new Enemy("Orc", 50);
    } else {
        return new Boss("Dark Lord", 100);
    }
}


