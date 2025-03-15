#include "BattleSystem.h"
#include <iostream>

BattleSystem::BattleSystem(int diff) : difficulty(diff) {
    setDifficulty(diff);
}

void BattleSystem::setDifficulty(int diff) {
    difficulty = diff;
    if (difficulty == 1) {
        enemy = std::make_unique<Enemy>("Weak Goblin", 50);
    }
    else if (difficulty == 2) {
        enemy = std::make_unique<Enemy>("Armored Knight", 100);
    }
    else if (difficulty == 3) {
        enemy = std::make_unique<Boss>("Dark Lord", 200);
    }
    else {
        std::cout << "Invalid difficulty level! Defaulting to medium.\n";
        enemy = std::make_unique<Enemy>("Armored Knight", 100);
    }
}

Enemy& BattleSystem::getEnemy() {
    return *enemy;
}

const Enemy& BattleSystem::getEnemy() const {
    return *enemy;
}


