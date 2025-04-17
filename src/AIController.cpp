#include "../include/AIController.h"
#include <iostream>
#include <cstdlib>

/**
 * @brief Default constructor for AIController.
 * 
 * This constructor initializes the AIController without any specific setup.
 */
AIController::AIController() {}

/**
 * @brief Makes a move for the enemy, deciding whether to attack, use a card, or defend.
 * @param enemy The enemy performing the action.
 * @param player The player who is the target of the enemy's action.
 *
 * This method randomly selects one of three actions:
 * - Attack the player
 * - Use a card from the enemy's deck
 * - Defend
 */
void AIController::makeMove(Enemy& enemy, Player& player) {
    int action = rand() % 3;  ///< Randomly select an action.

    switch (action) {
    case 0:
        attackPlayer(enemy, player); ///< Attack action.
        break;
    case 1:
        useCard(enemy, player); ///< Use a card action.
        break;
    case 2:
        defend(enemy); ///< Defend action.
        break;
    }
}

/**
 * @brief The enemy attempts to use a card from their deck.
 * @param enemy The enemy attempting to use a card.
 * @param player The player who is the target of the card's effect.
 *
 * This method draws a card from the enemy's deck and plays it if available.
 * If no cards are available, an error message is displayed.
 */
void AIController::useCard(Enemy& enemy, Player& player) {
    std::cout << enemy.getName() << " attempts to use a card!\n";
    if (enemy.getDeck()) {
        auto card = enemy.getDeck()->drawCard(); ///< Draw a card from the deck.
        if (card) {
            card->play(); ///< Play the drawn card.
        } else {
            std::cout << "No cards available in the deck!\n"; ///< Handle case where no cards are available.
        }
    }
}

/**
 * @brief The enemy attacks the player, dealing damage.
 * @param enemy The enemy performing the attack.
 * @param player The player receiving the attack.
 *
 * This method reduces the player's health by a fixed amount of damage.
 * If the enemy is stunned, the attack is skipped, and the enemy cannot perform the action.
 */
void AIController::attackPlayer(Enemy& enemy, Player& player) {
    std::cout << enemy.getName() << " attacks the player!\n";
    int damage = 10; ///< Fixed damage value.

    if (enemy.isStunned()) { ///< Check if the enemy is stunned.
        std::cout << enemy.getName() << " is stunned and cannot attack!\n";
        return; ///< If stunned, do not perform the attack.
    }

    player.takeDamage(damage); ///< Apply damage to the player.
}

/**
 * @brief The enemy defends itself, reducing incoming damage.
 * @param enemy The enemy performing the defense.
 *
 * This method reduces the damage the enemy takes by increasing its defense.
 * The value of defense is fixed (e.g., 5) and can be modified based on the enemy's characteristics.
 */
void AIController::defend(Enemy& enemy) {
    std::cout << enemy.getName() << " defends itself!\n";
    int defenseValue = 5; ///< Fixed defense value.
    enemy.defend(defenseValue); ///< Apply defense to the enemy.
}

/**
 * @brief A simple AI decision-making method for the enemy based on its health.
 * @param enemy The enemy making the decision.
 * @param player The player who may be affected by the enemy's action.
 *
 * This method checks if the enemy's HP is below 15. If so, the enemy defends itself; otherwise, it attacks the player.
 */
void AIController::simpleAI(Enemy& enemy, Player& player) {
    if (enemy.getHP() < 15) {
        defend(enemy); ///< If HP is low, the enemy defends itself.
    } else {
        attackPlayer(enemy, player); ///< Otherwise, the enemy attacks the player.
    }
}



