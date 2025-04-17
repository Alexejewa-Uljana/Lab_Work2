#ifndef ENEMY_H
#define ENEMY_H

#include "EnemyDeck.h"
#include "AIController.h"
#include "Player.h"
#include "EnemyDeck.h"
#include <string>
#include <vector>
#include <memory>

class Player;
class AIController;
class EnemyDeck;

/**
 * @class Enemy
 * @brief The Enemy class represents an enemy in the game that can attack, defend, use cards, and take actions during combat.
 *
 * The enemy has health, a deck of cards, an AI controller for decision-making, and can take actions such as attacking, defending, or casting spells.
 */
class Enemy
{

public:

    /**
     * @brief Default constructor that initializes an enemy with a name and default health.
     */
    Enemy();

    /**
     * @brief Constructs an Enemy with a specified name and health.
     * @param _name The name of the enemy.
     * @param _hp The health of the enemy.
     */
    Enemy(const std::string& _name, int _hp);

    /**
     * @brief Destroys the Enemy instance and frees associated resources.
     */
    ~Enemy();

    /**
     * @brief Applies damage to the enemy.
     * @param damage The amount of damage the enemy takes.
     *
     * This method decreases the enemy's health and prints the result.
     */
    void takeDamage(int damage);

    /**
     * @brief The enemy attacks the player.
     * @param player The player being attacked.
     * @param damage The amount of damage dealt by the enemy.
     *
     * This method makes the enemy attack the player with a specified damage value.
     */
    virtual void attack(Player& player, int damage);

    /**
     * @brief The enemy uses a card from their deck.
     * @param player The player being affected by the card.
     *
     * This method triggers the enemy to use a card from their deck.
     */
    void useCard(Player& player);

    /**
     * @brief Sets the AI controller for the enemy.
     * @param aiController The AI controller that manages the enemy's actions.
     *
     * This method sets the AI controller that handles the enemy's decision-making.
     */
    void setAIController(AIController* aiController);

    /**
     * @brief Gets the name of the enemy.
     * @return The name of the enemy.
     */
    std::string getName() const;

    /**
     * @brief Gets the current health of the enemy.
     * @return The current health of the enemy.
     */
    int getHP() const;

    /**
     * @brief Sets the health of the enemy.
     * @param health The new health value for the enemy.
     */
    void setHP(int health);

    /**
     * @brief Increases the number of turns the enemy is stunned.
     *
     * If the enemy is already stunned, this method reduces the stunned turns.
     */
    void increaseStunnedTurns();

    /**
     * @brief Gets the number of turns the enemy is stunned.
     * @return The number of turns the enemy is stunned.
     */
    unsigned getStunnedTurns() const;

    /**
     * @brief Checks if the enemy is stunned.
     * @return True if the enemy is stunned, false otherwise.
     */
    bool isStunned() const;

    /**
     * @brief Sets the number of stunned turns for the enemy.
     * @param turns The number of turns the enemy will be stunned.
     */
    void setStunned(unsigned turns);

    /**
     * @brief The enemy casts a spell on the player.
     * @param player The player who will be affected by the spell.
     * @param spellDamage The amount of damage dealt by the spell.
     *
     * This method makes the enemy cast a magic spell on the player.
     */
    virtual void castSpell(Player& player, int spellDamage);

    /**
     * @brief The enemy defends, strengthening its defenses.
     * @param defenseValue The amount of defense added to the enemy.
     *
     * This method increases the enemy's health based on the defense value.
     */
    void defend(int defenseValue);

    /**
     * @brief The enemy takes its turn and performs an action.
     * @param player The player who is the target of the enemy's action.
     *
     * This method handles the enemy's turn by calling the AI controller to make a move.
     */
    virtual void takeTurn(Player& player);

    /**
     * @brief The enemy draws a card from their deck.
     *
     * This method allows the enemy to draw a card from their deck if available.
     */
    void drawCardFromDeck();

    /**
     * @brief Sets the deck for the enemy.
     * @param newDeck The new deck to assign to the enemy.
     *
     * This method assigns a new deck of cards to the enemy.
     */
    void setDeck(EnemyDeck* newDeck);

    /**
     * @brief Gets the enemy's deck.
     * @return A pointer to the enemy's deck.
     */
    EnemyDeck* getDeck();

private:

    std::string name; /**< The name of the enemy */
    int attackPower; /**< The attack power of the enemy */
    int hp; /**< The health of the enemy */
    int stunnedTurns = 0; /**< The number of turns the enemy is stunned */
    EnemyDeck* deck = nullptr; /**< A pointer to the enemy's deck */
    AIController* aiController; /**< A pointer to the AI controller */
    std::vector<std::unique_ptr<Card>> hand; /**< The cards currently in the enemy's hand */
};

#endif
