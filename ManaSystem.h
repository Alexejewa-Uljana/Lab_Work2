#ifndef MANASYSTEM_H
#define MANASYSTEM_H

#include "MagicCard.h"
#include "Player.h"

/**
 * @class ManaSystem
 * @brief The ManaSystem class manages the player's mana and determines whether they can cast magic cards.
 * 
 * This class provides methods to check if the player has enough mana to cast a magic card and to reduce the player's mana
 * when a magic card is cast.
 */
class ManaSystem {

public:

    /**
     * @brief Checks if the player can cast the given magic card based on their current mana.
     * @param player The player attempting to cast the magic card.
     * @param magicCard The magic card the player wants to cast.
     * @return true if the player has enough mana to cast the card, false otherwise.
     * 
     * This method checks the player's current mana and compares it to the mana cost of the magic card.
     */
    static bool canCastMagicCard(Player& player, MagicCard* magicCard);

    /**
     * @brief Casts a magic card and reduces the player's mana.
     * @param player The player casting the magic card.
     * @param magicCard The magic card to be cast.
     * 
     * This method reduces the player's mana based on the mana cost of the magic card.
     * If the player does not have enough mana, an error message is displayed.
     */
    static void castMagicCard(Player& player, MagicCard* magicCard);
};

#endif
