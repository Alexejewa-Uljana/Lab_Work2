#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "Player.h"
#include <string>

/**
 * @class Boss
 * @brief The Boss class represents a powerful enemy character with special abilities.
 *
 * The Boss class is a derived class of the `Enemy` class, representing a more powerful enemy
 * that has a special ability and multiple actions in battle. A boss can attack, cast spells,
 * or use its special ability, which is typically stronger than regular attacks.
 */
class Boss : public Enemy {

public:
    /**
     * @brief Default constructor that creates a Boss with a default name and health.
     */
    Boss();

    /**
     * @brief Constructs a Boss with a specific name and health.
     * @param _name The name of the Boss.
     * @param _hp The health points of the Boss.
     */
    Boss(const std::string& _name, int _hp);

    /**
     * @brief Destructor for the Boss class.
     */
    ~Boss() = default;

    /**
     * @brief Uses the Boss's special ability on the player.
     * @param player The player who is targeted by the special ability.
     *
     * This ability deals significant damage to the player, and it is unique to the Boss.
     */
    void useSpecialAbility(Player& player);

    /**
     * @brief Takes the Boss's turn in combat, determining the action to take.
     * @param player The player who is the target of the Boss's actions.
     *
     * The Boss randomly selects an action from attacking, casting a spell, or using its special ability.
     */
    void takeTurn(Player& player) override;

    /**
     * @brief Attacks the player and deals damage.
     * @param player The player who is being attacked.
     * @param damage The amount of damage dealt by the attack.
     *
     * This method is used when the Boss performs a basic attack.
     */
    void attack(Player& player, int damage) override;

    /**
     * @brief Casts a spell on the player that deals damage.
     * @param player The player who is the target of the spell.
     * @param spellDamage The amount of damage dealt by the spell.
     *
     * This method is used when the Boss casts a spell.
     */
    void castSpell(Player& player, int spellDamage) override;

};

#endif

