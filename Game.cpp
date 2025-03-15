#include "Game.h"
#include <iostream>

Game::Game(int difficulty) 
    : storyManager(), battleSystem(difficulty) {
    std::cout << "Game initialized with difficulty: " << difficulty << std::endl;
    enemy = battleSystem.createEnemy();
    turnManager = new TurnManager(player, *enemy, battleSystem);
}

void Game::start() {
    storyManager.showStory();
    turnManager->startBattle();
}


