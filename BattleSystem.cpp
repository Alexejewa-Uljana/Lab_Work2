#include "BattleSystem.h"
#include <iostream>

/**
 * @brief Constructs a BattleSystem with a given difficulty level.
 * @param difficulty The difficulty level (1 for easy, 2 for medium, 3 for hard).
 *
 * This constructor initializes the BattleSystem with the given difficulty level,
 * which determines the strength and type of the enemies that will be created during the game.
 */
BattleSystem::BattleSystem(int difficulty) : difficulty(difficulty) {}

/**
 * @brief Creates an enemy based on the current difficulty level.
 * @return A pointer to an Enemy or Boss object, depending on the difficulty.
 *
 * This method creates different types of enemies depending on the difficulty level:
 * - Difficulty 1: Returns a Goblin with 30 HP.
 * - Difficulty 2: Returns an Orc with 50 HP.
 * - Difficulty 3: Returns a Dark Lord (Boss) with 100 HP.
 */
Enemy* BattleSystem::createEnemy() {
    if (difficulty == 1) {
        return new Enemy("Goblin", 30);
    } else if (difficulty == 2) {
        return new Enemy("Orc", 50);
    } else {
        return new Boss("Dark Lord", 100);
    }
}

