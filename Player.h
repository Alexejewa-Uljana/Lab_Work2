#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <vector>
#include "Deck.h"
#include "Card.h"

class Enemy;
class Deck;

/**
 * @class Player
 * @brief Represents the player character in the game.
 * 
 * The Player class is responsible for managing the player's deck, hand, health, mana, and attack power. 
 * It allows the player to interact with the game world, play cards, heal, and more.
 */
class Player {

public:

    /**
     * @brief Default constructor for Player.
     * 
     * Initializes the player's health, mana, attack power, and creates an empty deck.
     */
    Player();

    /**
     * @brief Destructor for Player.
     */
    ~Player();

    /**
     * @brief Displays the player's current hand of cards.
     * 
     * This method prints the player's hand to the console.
     */
    void showHand() const;

    /**
     * @brief Sets the player's name.
     * @param _name The name to set for the player.
     */
    void setName(const std::string& _name);

    /**
     * @brief Sets the player's health.
     * @param _hp The new health value for the player.
     */
    void setHP(int _hp);

    /**
     * @brief Plays a card from the player's hand.
     * @param index The index of the card to play.
     * @param enemy The enemy to interact with when playing the card.
     */
    void playCard(int index, Enemy& enemy);

    /**
     * @brief Displays the player's deck.
     * 
     * This method prints the player's deck to the console.
     */
    void showDeck() const;

    /**
     * @brief Heals the player by a specified amount.
     * @param amount The amount of health to restore to the player.
     */
    void heal(int amount);

    /**
     * @brief Sets the player's deck.
     * @param newDeck A unique pointer to a new deck.
     */
    void setDeck(std::unique_ptr<Deck> newDeck);

    /**
     * @brief Gets the player's deck.
     * @return A pointer to the player's deck.
     */
    Deck* getDeck() const;

    /**
     * @brief Gets the player's current health.
     * @return The player's health.
     */
    int getHP() const;

    /**
     * @brief Gets the player's current mana.
     * @return The player's mana.
     */
    int getMana() const;

    /**
     * @brief Gets the number of cards in the player's hand.
     * @return The size of the player's hand.
     */
    int getHandSize() const;

    /**
     * @brief Applies damage to the player.
     * @param damage The amount of damage to apply.
     */
    void takeDamage(int damage);

    /**
     * @brief Adds a card to the player's hand.
     * @param newCard A unique pointer to the new card.
     */
    void addCard(std::unique_ptr<Card> newCard);

    /**
     * @brief Increases the player's attack power by a specified amount.
     * @param amount The amount to increase the attack power.
     */
    void increaseAttackPower(int amount);

    /**
     * @brief Restores the player's mana by a specified amount.
     * @param amount The amount to restore to the player's mana.
     */
    void restoreMana(int amount);

    /**
     * @brief Restores the player's health by a specified amount.
     * @param amount The amount to restore to the player's health.
     */
    void restoreHealth(int amount);

    /**
     * @brief Adds a card to the player's deck.
     * @param card A unique pointer to the card to add.
     */
    void addCardToDeck(std::unique_ptr<Card> card);

    /**
     * @brief Gets the player's hand of cards.
     * @return A reference to the vector of the player's cards in hand.
     */
    const std::vector<std::unique_ptr<Card>>& getHand() const;

    /**
     * @brief Reduces the player's mana by a specified amount.
     * @param amount The amount of mana to reduce.
     */
    void reduceMana(int amount);

    /**
     * @brief Sets the number of turns the player is stunned.
     * @param turns The number of turns the player will be stunned.
     */
    void setStunned(int turns);

    /**
     * @brief Gets the number of turns the player is stunned.
     * @return The number of turns the player is stunned.
     */
    const int getStunned() const;

    /**
     * @brief Removes a card from the player's hand.
     * @param index The index of the card to remove from the player's hand.
     */
    void removeCard(int index);

    /**
     * @brief Gets the player's attack power.
     * @return The player's attack power.
     */
    const int getAttackPower() const;

    /**
     * @brief Draws cards from the player's deck.
     * 
     * This method ensures the player has three cards in hand by drawing from the deck.
     */
    void drawCards();

private:
    int hp; /**< The player's health. */
    int mana; /**< The player's mana. */
    int attackPower; /**< The player's attack power. */
    std::unique_ptr<Deck> deck; /**< The player's deck of cards. */
    std::vector<std::unique_ptr<Card>> hand; /**< The player's hand of cards. */
    int stunnedTurns = 0; /**< The number of turns the player is stunned. */
};

#endif
