#ifndef STATUS_EFFECT_CARD_H
#define STATUS_EFFECT_CARD_H

#include "Card.h"
#include "Effect.h"
#include "Player.h"
#include <iostream>
#include "Enemy.h"

/**
 * @class StatusEffectCard
 * @brief Represents a card that applies a status effect to an enemy or player.
 *
 * StatusEffectCards can apply effects like stun, poison, etc., during the game.
 */
class StatusEffectCard : public Card
{

private:
    Effect effect; /**< The effect associated with the status effect card. */

public:

    /**
     * @brief Constructs a status effect card with a name, power, and effect.
     * @param name The name of the status effect card.
     * @param power The power of the status effect card.
     * @param effect The effect of the status effect card.
     */
    StatusEffectCard(const std::string& name, int power, Effect effect);

    /**
     * @brief Default destructor for StatusEffectCard.
     */
    ~StatusEffectCard() = default;

    /**
     * @brief Plays the status effect card.
     */
    void play() override;

    /**
     * @brief Claims the reward for the status effect card.
     * @param player The player claiming the reward.
     */
    void claimReward(Player& player) override;

    /**
     * @brief Gets the effect of the status effect card.
     * @return The effect of the status effect card.
     */
    Effect getEffect() const;
};

#endif
