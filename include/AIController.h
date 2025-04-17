/**
 * @file AIController.h
 * @brief Header file for AIController class, which manages AI behavior during the game.
 */

#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>


class Enemy;
/**
 * @class AIController
 * @brief Class that controls the AI's actions during the battle.
 */
class AIController {

public:
    /**
     * @brief Default constructor.
     */
    AIController();

    /**
     * @brief Decides the AI's next move based on a random action.
     * @param enemy The enemy controlled by the AI.
     * @param player The player in the battle.
     */
    void makeMove(Enemy& enemy, Player& player);

    /**
     * @brief AI attempts to use a card if available in the enemy's deck.
     * @param enemy The enemy controlled by the AI.
     * @param player The player in the battle.
     */
    void useCard(Enemy& enemy, Player& player);

    /**
     * @brief AI attacks the player.
     * @param enemy The enemy controlled by the AI.
     * @param player The player in the battle.
     */
    void attackPlayer(Enemy& enemy, Player& player);

    /**
     * @brief AI defends itself, reducing damage from the player.
     * @param enemy The enemy controlled by the AI.
     */
    void defend(Enemy& enemy);

    /**
     * @brief A simple AI strategy where the AI defends if health is low, otherwise attacks.
     * @param enemy The enemy controlled by the AI.
     * @param player The player in the battle.
     */
    void simpleAI(Enemy& enemy, Player& player);
};

#endif // AI_CONTROLLER_H
