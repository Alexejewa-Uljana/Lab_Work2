#ifndef BOSS_AI_H
#define BOSS_AI_H

#include "Boss.h"
#include "Player.h"

/**
 * @class BossAI
 * @brief The BossAI class handles the behavior and decision-making of a boss during battle.
 *
 * This class is responsible for managing the boss's actions based on the state of both the boss and
 * the player. It decides whether the boss should attack, cast a spell, heal, or defend.
 */
class BossAI
{

public:

    /**
     * @brief Constructs a BossAI instance associated with a specific Boss.
     * @param boss The Boss instance for which the AI is controlling behavior.
     */
    BossAI(Boss& boss);

    /**
     * @brief Destroys the BossAI instance.
     */
    ~BossAI();

    /**
     * @brief Makes the boss take its turn in combat.
     * @param boss The Boss taking its turn.
     * @param player The Player who is the target of the boss's actions.
     *
     * This method checks if the boss is stunned. If not, it makes a decision about what action to take
     * based on the current state of the battle.
     */
    void takeTurn(Boss& boss, Player& player);

    /**
     * @brief Makes the boss decide on an action based on the current state of the battle.
     * @param boss The Boss making the decision.
     * @param player The Player who is the target of the decision.
     *
     * This method uses various thresholds to determine whether the boss should attack, cast a spell, use
     * a special ability, or defend based on the health of the boss and player.
     */
    void makeDecision(Boss& boss, Player& player);

    /**
     * @brief Makes the boss attack the player.
     * @param boss The Boss attacking the player.
     * @param player The Player receiving the attack.
     *
     * This method deals damage to the player based on the boss's attack.
     */
    void attack(Boss& boss, Player& player);

    /**
     * @brief Makes the boss cast a spell on the player.
     * @param boss The Boss casting the spell.
     * @param player The Player receiving the spell damage.
     *
     * This method deals spell damage to the player.
     */
    void castSpell(Boss& boss, Player& player);

    /**
     * @brief Makes the boss use a special ability (healing or damage).
     * @param boss The Boss using the special ability.
     * @param player The Player affected by the special ability.
     *
     * The boss can either heal or deal damage to the player depending on a random choice.
     */
    void useSpecialAbility(Boss& boss, Player& player);

    /**
     * @brief Makes the boss defend, reducing the damage taken in the next turn.
     * @param boss The Boss defending itself.
     *
     * This method reduces the damage the boss takes in future turns.
     */
    void defend(Boss& boss);

private:

    Boss& boss; /**< Reference to the boss controlled by the AI */
};

#endif // BOSS_AI_H
