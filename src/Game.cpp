// Алексеева Ульяна st129990@student.spbu.ru
#include "Game.h"
#include <iostream>

Game::Game(int difficulty)
    : storyManager(), battleSystem(difficulty)
{
    std::cout << "Game initialized with difficulty: " << difficulty << std::endl;
    enemy = battleSystem.createEnemy();
    turnManager = new TurnManager(player, *enemy, battleSystem);
}

Game::~Game() {}

void Game::start()
{
    storyManager.showStory();
    std::cout << "A random artifact is given before thr battle...\n";
    artifact.grantArtifact(player);
    turnManager->startBattle();
}


