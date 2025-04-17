#include "BossAI.h"
#include "Player.h"
#include <iostream>

/**
 * @brief Constructs a BossAI instance associated with a specific Boss.
 * @param _boss The Boss instance for which the AI is controlling behavior.
 */
BossAI::BossAI(Boss& _boss): boss(_boss) {}

/**
 * @brief Destroys the BossAI instance.
 */
BossAI::~BossAI() {}

/**
 * @brief Makes the boss take its turn in combat.
 * @param boss The Boss taking its turn.
 * @param player The Player who is the target of the boss's actions.
 * 
 * This method checks if the boss is stunned. If not, it makes a decision about what action to take
 * based on the current state of the battle.
 */
void BossAI::takeTurn(Boss& boss, Player& player) {
    if (boss.isStunned()) {
        std::cout << "Boss is stunned and cannot take action this turn." << std::endl;
        boss.setStunned(boss.getStunnedTurns() - 1);
        return;
    }

    makeDecision(boss, player);
}

/**
 * @brief Makes the boss decide on an action based on the current state of the battle.
 * @param boss The Boss making the decision.
 * @param player The Player who is the target of the decision.
 * 
 * This method uses various thresholds to determine whether the boss should attack, cast a spell, use
 * a special ability, or defend based on the health of the boss and player.
 */
void BossAI::makeDecision(Boss& boss, Player& player) {
    int decision = rand() % 100;

    int playerLowHPThreshold = player.getHP() * 0.3;
    int bossLowHPThreshold = boss.getHP() * 0.3;

    if (player.getHP() < playerLowHPThreshold) {
        std::cout << "Player's health is low! Boss is preparing a powerful attack!\n";
        attack(boss, player);
    } else if (boss.getHP() < bossLowHPThreshold) {
        std::cout << "Boss's health is low! He is defending or healing!\n";
        (decision < 50) ? defend(boss) : useSpecialAbility(boss, player);
    } else if (player.getHP() > player.getHP() * 0.7) {
        std::cout << "Player is healthy! Boss uses special ability!\n";
        useSpecialAbility(boss, player);
    } else {
        (decision < 50) ? attack(boss, player) : castSpell(boss, player);
    }
}

/**
 * @brief Makes the boss attack the player.
 * @param boss The Boss attacking the player.
 * @param player The Player receiving the attack.
 * 
 * This method deals damage to the player based on the boss's attack.
 */
void BossAI::attack(Boss& boss, Player& player) {
    int damage = 10 + rand() % 10;
    boss.attack(player, damage);
}

/**
 * @brief Makes the boss cast a spell on the player.
 * @param boss The Boss casting the spell.
 * @param player The Player receiving the spell damage.
 * 
 * This method deals spell damage to the player.
 */
void BossAI::castSpell(Boss& boss, Player& player) {
    int spellDamage = 20 + rand() % 5;
    boss.castSpell(player, spellDamage);
}

/**
 * @brief Makes the boss use a special ability (healing or damage).
 * @param boss The Boss using the special ability.
 * @param player The Player affected by the special ability.
 * 
 * The boss can either heal or deal damage to the player depending on a random choice.
 */
void BossAI::useSpecialAbility(Boss& boss, Player& player) {
    if (rand() % 2 == 0) {
        std::cout << "Boss uses healing special ability!\n";
        boss.castSpell(player, -20);
    } else {
        std::cout << "Boss uses damage special ability!\n";
        boss.attack(player, 25);
    }
}

/**
 * @brief Makes the boss defend, reducing the damage taken in the next turn.
 * @param boss The Boss defending itself.
 * 
 * This method reduces the damage the boss takes in future turns.
 */
void BossAI::defend(Boss& boss) {
    std::cout << "Boss defends this turn, reducing damage taken!" << std::endl;
}
