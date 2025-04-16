// Алексеева Ульяна st129990@student.spbu.ru
#include "MagicCard.h"
#include "Player.h"
#include <iostream>

/**
 * @brief Constructs a MagicCard with a specified power and mana cost.
 * @param power The power of the card (how much damage or effect it has).
 * @param _manaCost The mana cost of the card.
 */
MagicCard::MagicCard(int power, int _manaCost) : Card("Magic Card", power)
{
    manaCost = _manaCost;
}

/**
 * @brief Default constructor that creates a MagicCard with default values.
 *
 * This constructor initializes the MagicCard with a default power of 5.
 */
MagicCard::MagicCard() : Card("Magic Card", 5) {}

/**
 * @brief Plays the MagicCard, triggering a spell cast.
 *
 * This method simulates the action of casting a powerful spell when the MagicCard is played.
 */
void MagicCard::play()
{
    std::cout << "Played a Magic Card! You cast a powerful spell.\n";
}

/**
 * @brief Claims the reward for playing the MagicCard.
 * @param player The player receiving the reward.
 *
 * This method restores mana to the player when the MagicCard is played.
 */
void MagicCard::claimReward(Player& player)
{
    std::cout << "You received a bonus to mana!\n";
    player.restoreMana(10);
}

/**
 * @brief Returns the mana cost of the card.
 * @return The mana cost of the MagicCard.
 */
int MagicCard::getManaCost() const
{
    return manaCost;
}
