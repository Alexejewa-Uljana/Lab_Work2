#include "TurnManager.h"
#include <iostream>

TurnManager::TurnManager(Player& p, Enemy& e) : player(p), enemy(e), playerTurn(true) {}

void TurnManager::startTurn() {
    if (playerTurn) {
        std::cout << "Player's turn.\n";
        playerTurn = false;
    } else {
        std::cout << "Enemy's turn.\n";
        enemy.attack(player);
        playerTurn = true;
    }
}
