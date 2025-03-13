#include "BattleSystem.h"
#include <iostream>

void BattleSystem::startBattle(Player& player, Enemy& enemy) {
    std::cout << "The battle between you" << " and " << enemy.getName() << " has begun!" << std::endl;
}


