#include "../include/Game.h"
#include <iostream>

/**
 * @brief Constructs a Game instance with a specific difficulty level.
 * 
 * Initializes the game based on the selected game mode. The player can choose between AI or PvP mode,
 * and the game's difficulty level affects the player's and player2's initial health points (HP).
 * 
 * @param difficulty The difficulty level of the game (1 - easy, 2 - medium, 3 - hard).
 */
Game::Game(int difficulty) {
    std::cout << "Choose game mode (1 - vs AI, 2 - PvP): ";
    int mode;
    std::cin >> mode;
    if (mode != 2) {
       std::cout <<"against AI mode\n";
       battleSystem = new BattleSystem(difficulty);
       enemy = battleSystem->createEnemy();
       turnManager = new TurnManager(player, *enemy, *battleSystem);
       std::cout << "Game initialized with difficulty: " << difficulty << std::endl;
    }
    else{
        std::cout << "PvP mode\n";
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

/**
 * @brief Destructor for the Game.
 * 
 * Cleans up any dynamically allocated resources when the game ends.
 */
Game::~Game() {}

/**
 * @brief Starts the game, initializing the game state and running the main game loop.
 * 
 * This method begins the game, shows the story, grants a random artifact to the player,
 * and starts the battle system.
 */
void Game::start() {
    storyManager.showStory();
    std::cout << "A random artifact is given before the battle...\n";
    artifact.grantArtifact(player);
    turnManager->startBattle();
}

