#include "Game.h"
#include <iostream>

Game::Game(int difficulty) : player(), battleSystem(difficulty) {
    if (difficulty < 3) {
        enemy = std::make_unique<Enemy>("Orc", 50);
        turnManager = std::make_unique<TurnManager>(player, *enemy, battleSystem);
    } else {
        boss = std::make_unique<Boss>("Dark Overlord", 150);
        turnManager = std::make_unique<TurnManager>(player, *boss, battleSystem);
    }
    player.setHP(100);
}

void Game::start() {
    std::cout << "The battle begins!\n";
    turnManager->startBattle();
}

void Game::showGameStatus() const {
    std::cout << "Player HP: " << player.getHP() << "\n";
    if (enemy) {
        std::cout << "Enemy HP: " << enemy->getHP() << "\n";
    } else if (boss) {
        std::cout << "Boss HP: " << boss->getHP() << "\n";
    }
}


