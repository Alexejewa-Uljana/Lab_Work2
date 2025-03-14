#include "Game.h"
#include <iostream>

Game::Game(int difficulty) 
    : player(), deck(), battleSystem(difficulty), storyManager(), world(), difficulty(difficulty) {
    setDifficulty(difficulty);
    turnManager = std::make_unique<TurnManager>(player, *enemy, battleSystem);
    player.setHP(100);
}

void Game::start() {
    std::cout << "Welcome to the game!\n";

    // Проверяем, есть ли метод showIntro() в StoryManager
    // Если его нет в StoryManager, либо добавляем его, либо убираем эту строку.
    // storyManager.showIntro();

    std::cout << "Battle begins!\n";
    turnManager->startBattle();

    if (player.getHP() > 0) {
        std::cout << "You survived this battle. What will you do next?\n";
    } else {
        std::cout << "Game Over.\n";
    }
}

void Game::setDifficulty(int difficulty) {
    if (difficulty == 1) {
        enemy = std::make_unique<Enemy>("Goblin", 50);
    } else if (difficulty == 2) {
        enemy = std::make_unique<Enemy>("Orc", 75);
    } else {
        enemy = std::make_unique<Boss>("Dark Mage", 100);
    }
}

void Game::showGameStatus() const {
    std::cout << "Player HP: " << player.getHP() << "\n";
    std::cout << "Enemy HP: " << enemy->getHP() << "\n";
}


