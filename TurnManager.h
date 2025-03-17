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
class TurnManager {

private:
    BossAI* bossAI;
    Player& player;
    Player* player2;
    Enemy& enemy;
    BattleSystem& battleSystem;
    AIController aiController;
    RewardSystem rewardSystem;
    int turnCounter;
    bool isPvP;
    bool isBossFight;

public:
    /**
     * @brief Constructor for TurnManager in a battle with an enemy.
     * @param player The player.
     * @param enemy The enemy.
     * @param battleSystem The battle system.
     */
    TurnManager(Player& p1, Enemy& e, BattleSystem& bs);

    // Конструктор для PvP
    TurnManager(Player& p1, Player& p2, BattleSystem& bs);

    // Конструктор для сражения с боссом
    TurnManager(Player& p1, Boss& b, BattleSystem& bs);

    /**
     * @brief Destructor for TurnManager.
     * Frees the memory used by BossAI.
     */
    ~TurnManager();

    /**
     * @brief Starts the battle between the player and the enemy or boss.
     */
    void pvpTurn();
    void startBattle();
    void pvpvTurn(Player& currentPlayer, Player& opponentPlayer);

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
