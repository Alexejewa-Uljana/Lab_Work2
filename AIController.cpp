#include "AIController.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

AIController::AIController() {}

void AIController::makeMove(Enemy& enemy, Player& player) {
    int enemyHP = enemy.getHP();
    int playerHP = player.getHP();
    if (enemyHP < 15) {
        if (playerHP < 15) {
            std::cout << enemy.getName() << " делает решающую атаку!\n";
            enemy.attack(player, 20);
        } else {
            std::cout << enemy.getName() << " пытается защититься.\n";
            enemy.defend(10);
        }
        return;
    }
    if (playerHP < 20) {
        std::cout << enemy.getName() << " использует сильную атаку!\n";
        enemy.attack(player, 15);
        return;
    }
    if (enemy.getName() == "Dark Mage") {
        std::cout << enemy.getName() << " использует магическое заклинание!\n";
        enemy.castSpell(player, 12);
    }
    else if (enemy.getName() == "Orc") {
        std::cout << enemy.getName() << " выполняет мощный удар!\n";
        enemy.attack(player, 10);
    }
    else {
        std::cout << enemy.getName() << " атакует!\n";
        enemy.attack(player, 8);
    }
}
