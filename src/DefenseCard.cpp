#include "../include/DefenseCard.h"
#include "../include/Player.h"
#include <iostream>

/**
 * @brief Constructs a DefenseCard with a specified power.
 * @param power The defensive power of the card.
 */
DefenseCard::DefenseCard(int power) : Card("Defense Card", power) {}

/**
 * @brief Plays the DefenseCard.
 * 
 * This method applies the defensive effect of the card, providing the player with a shield.
 */
void DefenseCard::play() {
    std::cout << "Played a Defense Card! You gain a shield!\n";
}

/**
 * @brief Claims the reward associated with playing the DefenseCard.
 * @param player The player who will receive the reward.
 * 
 * This method increases the player's defense and restores health.
 */
void DefenseCard::claimReward(Player& player) {
    std::cout << "You received a bonus to defense power!\n";
    player.restoreHealth(10);
}

/**
 * @brief Gets the defense power of the card.
 * @return The defensive power of the card.
 */
int DefenseCard::getDefensePower() const {
    return defenseValue;
}
