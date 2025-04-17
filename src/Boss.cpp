#include "../include/Boss.h"
#include "../include/Player.h"
#include <iostream>

/**
 * @brief Default constructor for the Boss class.
 *
 * This constructor initializes the Boss with a default name ("Boss") and a default health (100).
 */
Boss::Boss() : Enemy("Boss", 100) {}

/**
 * @brief Constructor for creating a Boss with a custom name and health.
 * @param _name The name of the Boss.
 * @param _hp The health points of the Boss.
 */
Boss::Boss(const std::string& _name, int _hp) : Enemy(_name, _hp) {}

/**
 * @brief Uses the Boss's special ability on the player.
 * @param player The player who is the target of the special ability.
 *
 * The special ability deals significant damage (50 damage points) to the player.
 */
void Boss::useSpecialAbility(Player& player) {
    std::cout << "Boss is using special ability on you!" << std::endl;
    attack(player, 50); // The special ability uses the Boss's attack method to deal 50 damage
}

/**
 * @brief The Boss takes its turn in battle, choosing an action based on randomness.
 * @param player The player who is the target of the Boss's actions.
 *
 * The Boss may attack, cast a spell, or use a special ability. The action is chosen randomly.
 * If the Boss is stunned, it cannot take any action.
 */
void Boss::takeTurn(Player& player) {
    if (isStunned()) {
        std::cout << "Boss is stunned and cannot take action this turn." << std::endl;
        setStunned(getStunnedTurns() - 1); // Decrease the stunned turns
        return;
    }

    int actionChoice = rand() % 3;

    if (actionChoice == 0) {
        std::cout << "Boss attacks!" << std::endl;
        attack(player, 20); // Boss performs a regular attack
    } else if (actionChoice == 1) {
        std::cout << "Boss casts a spell!" << std::endl;
        castSpell(player, 30); // Boss casts a spell
    } else {
        std::cout << "Boss uses special ability!" << std::endl;
        useSpecialAbility(player); // Boss uses special ability
    }
}

/**
 * @brief The Boss attacks the player, dealing a specified amount of damage.
 * @param player The player who takes the damage from the attack.
 * @param damage The amount of damage dealt by the attack.
 *
 * This function outputs a message indicating the Boss's attack and applies damage to the player.
 */
void Boss::attack(Player& player, int damage) {
    std::cout << "Boss attacks you" << " for " << damage << " damage!" << std::endl;
    player.takeDamage(damage); // Apply the damage to the player
}

/**
 * @brief The Boss casts a spell on the player, dealing specified spell damage.
 * @param player The player who takes the damage from the spell.
 * @param spellDamage The amount of damage dealt by the spell.
 *
 * This function outputs a message indicating the Boss's spell and applies damage to the player.
 */
void Boss::castSpell(Player& player, int spellDamage) {
    std::cout << "Boss casts a spell on you dealing " << spellDamage << " damage!" << std::endl;
    player.takeDamage(spellDamage); // Apply spell damage to the player
}

