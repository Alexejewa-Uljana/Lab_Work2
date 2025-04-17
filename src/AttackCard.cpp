// Алексеева Ульяна st129990@student.spbu.ru
#include "../include/AttackCard.h"
#include "../include/Player.h"
#include <iostream>

/**
 * @brief Constructs an AttackCard with specified attack power.
 * @param power The attack power of this card.
 *
 * This constructor initializes the AttackCard with the given attack power and passes the card's name
 * and power to the base class Card.
 */
AttackCard::AttackCard(int power): Card("Attack Card", power) {}

/**
 * @brief Plays the AttackCard.
 *
 * When the AttackCard is played, this method prints a message indicating that the card was used.
 * Additional functionality can be added to affect the game state or the player.
 */
void AttackCard::play()
{
    std::cout << "Played an Attack Card!\n";
}

/**
 * @brief Claims the reward for playing the AttackCard.
 * @param player The player receiving the reward.
 *
 * This method provides the player with a bonus to their attack power when the card is played.
 * The player will have their attack power increased by a fixed amount.
 */
void AttackCard::claimReward(Player& player)
{
    std::cout << "You received a bonus to attack power!\n";
    player.increaseAttackPower(5);  ///< Increase the player's attack power by 5.
}

/**
 * @brief Returns the attack power of the AttackCard.
 * @return The attack power of the AttackCard.
 *
 * This method returns the amount of attack power that the card provides.
 */
int AttackCard::getAttackPower() const
{
    return attackPower;
}

