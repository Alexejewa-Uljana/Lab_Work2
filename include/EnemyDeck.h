#ifndef ENEMYDECK_H
#define ENEMYDECK_H

#include <vector>
#include <memory>
#include "Card.h"
#include "AttackCard.h"
#include "DefenseCard.h"

/**
 * @class EnemyDeck
 * @brief The EnemyDeck class represents the deck of cards that an enemy uses during combat.
 *
 * The deck contains different types of cards that the enemy can draw and play during their turn.
 * It allows the addition of new cards, drawing cards, and initializing the deck with specific cards.
 */
class EnemyDeck
{

public:

    /**
     * @brief Default constructor for the EnemyDeck.
     *
     * Initializes the deck to be empty.
     */
    EnemyDeck();

    /**
     * @brief Destructor for the EnemyDeck.
     *
     * Frees any resources used by the deck.
     */
    ~EnemyDeck();

    /**
     * @brief Adds a card to the deck.
     * @param card A unique pointer to a Card that will be added to the deck.
     *
     * This method allows cards to be added to the deck for the enemy to use during combat.
     */
    void addCard(std::unique_ptr<Card> card);

    /**
     * @brief Draws a card from the deck.
     * @return A unique pointer to a Card drawn from the deck, or nullptr if the deck is empty.
     *
     * This method removes and returns the top card of the deck. If the deck is empty, it returns nullptr.
     */
    std::unique_ptr<Card> drawCard();

    /**
     * @brief Initializes the deck with default cards.
     *
     * This method adds a few specific cards (Attack and Defense cards) to the deck for the enemy.
     */
    void initializeDeck();

    /**
     * @brief Gets the number of cards in the deck.
     * @return The number of cards currently in the deck.
     *
     * This method returns the current size of the deck.
     */
    const int getSize() const;

private:

    /**
     * @brief A vector that holds the unique pointers to the cards in the deck.
     *
     * This vector holds all the cards available to the enemy in their deck.
     */
    std::vector<std::unique_ptr<Card>> deck;
};

#endif
