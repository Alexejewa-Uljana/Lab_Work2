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
            std::cout << enemy.getName() << " makes the decisive attack!\n";
            enemy.attack(player, 20);
        } else {
            std::cout << enemy.getName() << " trying to defend himself.\n";
            enemy.defend(10);
        }
        return;
    }
    if (playerHP < 20) {
        std::cout << enemy.getName() << " uses strong attack!\n";
        enemy.attack(player, 15);
        return;
    }
    if (enemy.getName() == "Dark Mage") {
        std::cout << enemy.getName() << " uses a magic spell!\n";
        enemy.castSpell(player, 12);
    }
    else if (enemy.getName() == "Orc") {
        std::cout << enemy.getName() << " performs a powerful blow!\n";
        enemy.attack(player, 10);
    }
    else {
        std::cout << enemy.getName() << " attack!\n";
        enemy.attack(player, 8);
    }
}
