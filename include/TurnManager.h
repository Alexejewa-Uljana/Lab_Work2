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
 * @brief Manages the turns for the player, enemy, and boss during battle.
 *
 * This class handles alternating turns between the player and the enemy/boss,
 * manages the card system, decks, and rewards.
 */
class TurnManager
{

private:
    BossAI* bossAI; ///< AI system for the boss fights.
    Player& player; ///< Reference to the main player.
    Player* player2; ///< Pointer to the second player (for PvP mode).
    Enemy& enemy; ///< Reference to the enemy character.
    BattleSystem& battleSystem; ///< Reference to the battle system.
    AIController aiController; ///< AI controller for enemy decision-making.
    RewardSystem rewardSystem; ///< Handles player rewards.
    int turnCounter; ///< Counter for the number of turns taken.
    bool isPvP; ///< Flag indicating whether the game is in PvP mode.
    bool isBossFight; ///< Flag indicating whether the battle is against a boss.

public:
    /**
     * @brief Constructor for a standard battle between a player and an enemy.
     * @param p1 The player.
     * @param e The enemy.
     * @param bs The battle system.
     */
    TurnManager(Player& p1, Enemy& e, BattleSystem& bs);

    /**
     * @brief Constructor for a PvP battle.
     * @param p1 The first player.
     * @param p2 The second player.
     * @param bs The battle system.
     */
    TurnManager(Player& p1, Player& p2, BattleSystem& bs);

    /**
     * @brief Constructor for a battle against a boss.
     * @param p1 The player.
     * @param b The boss.
     * @param bs The battle system.
     */
    TurnManager(Player& p1, Boss& b, BattleSystem& bs);

    /**
     * @brief Destructor for TurnManager.
     *
     * Cleans up dynamically allocated BossAI memory.
     */
    ~TurnManager();

    /**
     * @brief Starts the battle loop between the player and the enemy or boss.
     */
    void startBattle();

    /**
     * @brief Handles turns in PvP mode.
     */
    void pvpTurn();

    /**
     * @brief Handles a single turn in a PvP game.
     * @param currentPlayer The player taking the turn.
     * @param opponentPlayer The opposing player.
     */
    void pvpvTurn(Player& currentPlayer, Player& opponentPlayer);

    /**
     * @brief Executes the player's turn.
     */
    void playerTurn();

    /**
     * @brief Executes the enemy's turn.
     */
    void enemyTurn();

    /**
     * @brief Refills the player's deck with new cards when it's empty.
     */
    void refillDeck();

    /**
     * @brief Draws a new card for the player.
     */
    void drawNewCardForPlayer();
};

#endif // TURNMANAGER_H

