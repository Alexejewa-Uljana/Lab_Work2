#ifndef ATTACKCARD_H
#define ATTACKCARD_H

#include "Card.h"
#include "Player.h"
#include <iostream>

/**
 * @class AttackCard
 * @brief The AttackCard class represents an attack card that increases attack power.
 *
 * The AttackCard class is a type of card that, when played, provides a bonus to the player's attack power. 
 * It can be played to deal damage or claim a reward that boosts the player's attack power.
 */
class AttackCard : public Card {

public:
    /**
     * @brief Constructs an AttackCard with specified attack power.
     * @param power The amount of attack power this card provides.
     */
    AttackCard(int power);

    /**
     * @brief Destructor for AttackCard.
     *
     * The destructor cleans up any resources used by the AttackCard object. 
     * In this case, no dynamic memory allocation is used, so it is a default destructor.
     */
    ~AttackCard() = default;

    /**
     * @brief Plays the AttackCard.
     *
     * This method prints a message indicating that an AttackCard has been played. 
     * It can be extended to affect the game state in the future.
     */
    void play() override;

    /**
     * @brief Claims the reward of the AttackCard.
     * @param player The player who will receive the reward.
     *
     * This method provides the player with a bonus to attack power when the card is used.
     */
    void claimReward(Player& player) override;

    /**
     * @brief Gets the attack power of the AttackCard.
     * @return The attack power of the card.
     *
     * This method returns the attack power associated with this AttackCard.
     */
    int getAttackPower() const;

private:
    /**
     * @brief The attack power of the AttackCard.
     *
     * This variable stores the attack power provided by the card.
     */
    int attackPower;
};

#endif



