// Алексеева Ульяна st129990@student.spbu.ru
#include "../include/ManaSystem.h"
#include <iostream>

/**
 * @brief Checks if the player can cast the given magic card based on their current mana.
 * @param player The player attempting to cast the magic card.
 * @param magicCard The magic card the player wants to cast.
 * @return true if the player has enough mana to cast the card, false otherwise.
 *
 * This method checks the player's current mana and compares it to the mana cost of the magic card.
 */
bool ManaSystem::canCastMagicCard(Player& player, MagicCard* magicCard)
{
    if (!magicCard) return false;
    return player.getMana() >= magicCard->getManaCost();
}

/**
 * @brief Casts a magic card and reduces the player's mana.
 * @param player The player casting the magic card.
 * @param magicCard The magic card to be cast.
 *
 * This method reduces the player's mana based on the mana cost of the magic card.
 * If the player does not have enough mana, an error message is displayed.
 */
void ManaSystem::castMagicCard(Player& player, MagicCard* magicCard)
{
    if (canCastMagicCard(player, magicCard))
    {
        int manaCost = magicCard->getManaCost();
        player.reduceMana(manaCost);
        std::cout << "Mana reduced by " << manaCost << ". Remaining: " << player.getMana() << std::endl;
    }
    else
    {
        std::cout << "Not enough mana to play this card!" << std::endl;
    }
}
