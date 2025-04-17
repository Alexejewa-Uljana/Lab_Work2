#ifndef SPECIAL_CARD_H
#define SPECIAL_CARD_H

#include "Card.h"
#include "Effect.h"
#include "Player.h"
#include <iostream>

/**
 * @class SpecialCard
 * @brief Represents a special card with an effect.
 *
 * Special cards can have various effects that the player can claim or use during the game.
 */
class SpecialCard : public Card
{

private:
    Effect effect; /**< The effect associated with the special card. */

public:

    /**
     * @brief Constructs a special card with a name, power, and effect.
     * @param name The name of the special card.
     * @param power The power of the special card.
     * @param effect The effect of the special card.
     */
    SpecialCard(const std::string& name, int power, Effect effect);

    /**
     * @brief Default destructor for SpecialCard.
     */
    ~SpecialCard() = default;

    /**
     * @brief Plays the special card.
     */
    void play() override;

    /**
     * @brief Claims the reward for the special card.
     * @param player The player claiming the reward.
     */
    void claimReward(Player& player) override;

    /**
     * @brief Gets the effect of the special card.
     * @return The effect of the special card.
     */
    Effect getEffect() const;
};

#endif

