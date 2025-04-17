// Алексеева Ульяна st129990@student.spbu.ru
#include "../include/StatusEffectCard.h"
#include <iostream>

/**
 * @brief Constructs a status effect card with a name, power, and effect.
 * @param name The name of the status effect card.
 * @param power The power of the status effect card.
 * @param effect The effect of the status effect card.
 */
StatusEffectCard::StatusEffectCard(const std::string& name, int power, Effect effect)
    : Card(name, power), effect(effect) {}

/**
 * @brief Plays the status effect card.
 *
 * This method prints the name of the status effect card being used.
 */
void StatusEffectCard::play()
{
    std::cout << "Using status effect card: " << getName() << "\n";
}

/**
 * @brief Claims the reward for the status effect card.
 * @param player The player claiming the reward.
 *
 * This method prints a message when the status effect card's reward is claimed.
 */
void StatusEffectCard::claimReward(Player& player)
{
    std::cout << "Claiming reward from: " << getName() << "\n";
}

/**
 * @brief Gets the effect of the status effect card.
 * @return The effect of the status effect card.
 */
Effect StatusEffectCard::getEffect() const
{
    return effect;
}
