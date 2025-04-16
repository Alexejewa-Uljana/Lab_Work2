#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "BattleSystem.h"
#include "AIController.h"
#include "BossAI.h"
#include "RewardSystem.h"

/**
 * @class TurnManager
 * @brief Manages the turns for the player and the enemy during battle.
 *
 * TurnManager organizes and handles alternating turns between the player and the enemy,
 * and manages the card system, decks, and rewards.
 */
class TurnManager
{

private:
    Player& player; /**< Reference to the player. */
    Enemy& enemy; /**< Reference to the enemy. */
    BattleSystem& battleSystem; /**< The battle system. */
    AIController aiController; /**< AI controller for the enemy. */
    BossAI* bossAI; /**< AI for the boss, if it's a boss fight. */
    bool isBossFight; /**< Flag indicating whether it's a boss fight. */
    RewardSystem rewardSystem; /**< Reward system for the player. */
    int turnCounter; /**< Turn counter. */

public:
    /**
     * @brief Constructor for TurnManager in a battle with an enemy.
     * @param player The player.
     * @param enemy The enemy.
     * @param battleSystem The battle system.
     */
    TurnManager(Player& player, Enemy& enemy, BattleSystem& battleSystem);

    /**
     * @brief Constructor for TurnManager in a battle with a boss.
     * @param player The player.
     * @param boss The boss.
     * @param battleSystem The battle system.
     */
    TurnManager(Player& player, Boss& boss, BattleSystem& battleSystem);

    /**
     * @brief Destructor for TurnManager.
     * Frees the memory used by BossAI.
     */
    ~TurnManager();

    /**
     * @brief Starts the battle between the player and the enemy or boss.
     */
    void startBattle();

    /**
     * @brief Player's turn.
     */
    void playerTurn();

    /**
     * @brief Enemy's turn.
     */
    void enemyTurn();

    /**
     * @brief Refills the player's deck with new cards.
     */
    void refillDeck();

    /**
     * @brief Draws a new card for the player.
     */
    void drawNewCardForPlayer();
};

#endif // TURNMANAGER_H



