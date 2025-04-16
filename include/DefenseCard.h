#ifndef DEFENSECARD_H
#define DEFENSECARD_H

#include "Card.h"
#include <iostream>
#include "Player.h"

/**
 * @class DefenseCard
 * @brief The DefenseCard class represents a card that grants defense capabilities to the player.
 *
 * The defense card can be played to provide the player with a shield or defensive power.
 */
class Player;

class DefenseCard : public Card
{

public:

    /**
     * @brief Constructs a DefenseCard with a specified power.
     * @param power The defensive power of the card.
     */
    DefenseCard(int power);

    /**
     * @brief Destroys the DefenseCard instance.
     */
    ~DefenseCard() = default;

    /**
     * @brief Plays the DefenseCard.
     *
     * This method applies the defensive effect of the card, providing the player with a shield.
     */
    void play() override;

    /**
     * @brief Claims the reward associated with playing the DefenseCard.
     * @param player The player who will receive the reward.
     *
     * This method increases the player's defense and restores health.
     */
    void claimReward(Player& player) override;

    /**
     * @brief Gets the defense power of the card.
     * @return The defensive power of the card.
     */
    int getDefensePower() const;

private:

    int defenseValue; /**< The defensive value provided by the card */
};

#endif

