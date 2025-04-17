// Алексеева Ульяна st129990@student.spbu.ru
#include "../include/SpecialCard.h"
#include "../include/Effect.h"
#include <iostream>

/**
 * @brief Constructs a special card with a name, power, and effect.
 * @param name The name of the special card.
 * @param power The power of the special card.
 * @param effect The effect of the special card.
 */
SpecialCard::SpecialCard(const std::string& name, int power, Effect effect)
    : Card(name, power), effect(effect) {}

/**
 * @brief Plays the special card.
 *
 * This method prints the name of the special card being used.
 */
void SpecialCard::play()
{
    std::cout << "Using special card: " << getName() << "\n";
}

/**
 * @brief Claims the reward for the special card.
 * @param player The player claiming the reward.
 *
 * This method prints a message when the special card's reward is claimed.
 */
void SpecialCard::claimReward(Player& player)
{
    std::cout << "Claiming special card reward: " << getName() << "\n";
}

/**
 * @brief Gets the effect of the special card.
 * @return The effect of the special card.
 */
Effect SpecialCard::getEffect() const
{
    return effect;
}
