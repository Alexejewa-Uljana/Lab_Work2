#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include "Enemy.h"
#include "Boss.h"

/**
 * @class BattleSystem
 * @brief The BattleSystem class handles the creation of enemies based on the difficulty level.
 *
 * The BattleSystem is responsible for creating enemies when a battle begins. It adjusts the enemy's
 * strength and type based on the specified difficulty level (easy, medium, or hard).
 */
class BattleSystem
{

public:
    /**
     * @brief Constructs a BattleSystem with a given difficulty.
     * @param difficulty The difficulty level (1 for easy, 2 for medium, 3 for hard).
     */
    BattleSystem(int difficulty);

    /**
     * @brief Destructor for the BattleSystem.
     *
     * The destructor cleans up any resources associated with the BattleSystem object.
     * In this case, no dynamic memory is directly managed, so it's a default destructor.
     */
    ~BattleSystem() = default;

    /**
     * @brief Creates an enemy based on the current difficulty level.
     * @return A pointer to an Enemy or Boss object, depending on the difficulty.
     *
     * This method creates different types of enemies (Goblin, Orc, or Dark Lord) based on the difficulty:
     * - Difficulty 1: Creates a Goblin with 30 HP.
     * - Difficulty 2: Creates an Orc with 50 HP.
     * - Difficulty 3: Creates a Dark Lord (Boss) with 100 HP.
     */
    Enemy* createEnemy();

private:
    /**
     * @brief The difficulty level of the battle.
     *
     * This variable stores the difficulty level that determines the type and strength of the enemy.
     * - 1 for easy (Goblin)
     * - 2 for medium (Orc)
     * - 3 for hard (Dark Lord)
     */
    int difficulty;
};

#endif


