#ifndef MAGICCARD_H
#define MAGICCARD_H

#include "Card.h"
#include <iostream>
#include "Player.h"

/**
 * @class MagicCard
 * @brief The MagicCard class represents a card that can be played by the player to cast a spell.
 *
 * Magic cards are used to cast spells, providing a specific power and a mana cost.
 * The player can also receive rewards after playing the Magic card.
 */
class MagicCard : public Card
{

public:

    /**
     * @brief Constructs a MagicCard with a specified power and mana cost.
     * @param power The power of the card (how much damage or effect it has).
     * @param _manaCost The mana cost of the card.
     */
    MagicCard(int power, int _manaCost);

    /**
     * @brief Default constructor that creates a MagicCard with default values.
     *
     * This constructor initializes the MagicCard with a default power of 5.
     */
    MagicCard();

    /**
     * @brief Destructor for the MagicCard.
     */
    ~MagicCard() = default;

    /**
     * @brief Returns the mana cost of the card.
     * @return The mana cost of the MagicCard.
     */
    int getManaCost() const;

    /**
     * @brief Plays the MagicCard, triggering a spell cast.
     *
     * This method simulates the action of casting a powerful spell when the MagicCard is played.
     */
    void play() override;

    /**
     * @brief Claims the reward for playing the MagicCard.
     * @param player The player receiving the reward.
     *
     * This method restores mana to the player when the MagicCard is played.
     */
    void claimReward(Player& player) override;

private:

    /**
     * @brief The mana cost of the MagicCard.
     *
     * This value determines how much mana is required to play the card.
     */
    int manaCost;
};

#endif

