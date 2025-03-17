#ifndef CARD_H
#define CARD_H

#include <iostream>

/**
 * @class Card
 * @brief The Card class represents a card that can be used by players or enemies in battle.
 * 
 * Cards have a name and a power, and they can be played or claimed for their effects in the game.
 */
class Player;

class Card {

public:

    /**
     * @brief Constructs a Card with a specified name and power.
     * @param _name The name of the card.
     * @param _power The power associated with the card.
     */
    Card(const std::string& _name, int _power);

    /**
     * @brief Destroys the Card instance.
     */
    virtual ~Card();

    /**
     * @brief Gets the name of the card.
     * @return The name of the card.
     */
    std::string getName() const;

    /**
     * @brief Gets the power of the card.
     * @return The power of the card.
     */
    int getPower() const;

    /**
     * @brief Plays the card, applying its effect.
     * 
     * This method must be implemented by subclasses to define the specific behavior of the card.
     */
    virtual void play() = 0;

    /**
     * @brief Claims the reward from playing the card.
     * @param player The player receiving the reward.
     * 
     * This method must be implemented by subclasses to define the specific reward mechanics.
     */
    virtual void claimReward(Player& player) = 0;

private:

    std::string name; /**< The name of the card */
    int power; /**< The power of the card */
};

#endif
