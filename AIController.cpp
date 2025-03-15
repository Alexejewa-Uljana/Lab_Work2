#include "AIController.h"
#include <iostream>
#include <cstdlib>

AIController::AIController() {}

void AIController::makeMove(Enemy& enemy, Player& player) {
    int action = rand() % 3;

    switch (action) {
        case 0:
            attackPlayer(enemy, player);
            break;
        case 1:
            useCard(enemy, player);
            break;
        case 2:
            defend(enemy);
            break;
    }
}

void AIController::useCard(Enemy& enemy, Player& player) {
    std::cout << enemy.getName() << " attempts to use a card!\n";
    if (enemy.getDeck()) {
        auto card = enemy.getDeck()->drawCard();
        if (card) {
            card->play();
        } else {
            std::cout << "No cards available in the deck!\n";
        }
    }
}

void AIController::attackPlayer(Enemy& enemy, Player& player) {
    std::cout << enemy.getName() << " attacks the player!\n";
    int damage = 10;
    if (enemy.isStunned()) {
        std::cout << enemy.getName() << " is stunned and cannot attack!\n";
        return;
    }
    player.takeDamage(damage);
}

void AIController::defend(Enemy& enemy) {
    std::cout << enemy.getName() << " defends itself!\n";
    int defenseValue = 5;
    enemy.defend(defenseValue);
}

void AIController::simpleAI(Enemy& enemy, Player& player) {
    if (enemy.getHP() < 15) {
        defend(enemy);
    } else {
        attackPlayer(enemy, player);
    }
}
