#include "Game.h"
#include <iostream>

Game::Game(int difficulty) {
    std::cout << "Choose game mode (1 - vs AI, 2 - PvP): ";
    int mode;
    std::cin >> mode;
    if (mode == 1) {
       battleSystem = new BattleSystem(difficulty);
       enemy = battleSystem->createEnemy();
       turnManager = new TurnManager(player, *enemy, *battleSystem);
       std::cout << "Game initialized with difficulty: " << difficulty << std::endl;
    }
    else if (mode == 2) {
        if(difficulty == 1) {
            player.setHP(50);
            player2.setHP(50);
        }
        else if(difficulty == 2) {
           player.setHP(70);
           player2.setHP(70);
        }
        else {
            player.setHP(100);
            player2.setHP(100);
        }
        battleSystem = new BattleSystem(difficulty);
        turnManager = new TurnManager(player, player2, *battleSystem);
    }
}

Game::~Game() {}

void Game::start() {
    storyManager.showStory();
    std::cout << "A random artifact is given before thr battle...\n";
    artifact.grantArtifact(player);
    turnManager->startBattle();
}

