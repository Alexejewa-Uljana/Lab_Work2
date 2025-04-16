#ifndef DECK_H
#define DECK_H

#include <memory>
#include <vector>
#include "Card.h"
#include "Effect.h"
#include "StatusEffectCard.h"
#include "SpecialCard.h"

/**
 * @class Deck
 * @brief The Deck class represents a collection of cards from which players can draw.
 *
 * The deck is initialized with a variety of cards, including attack, defense, magic, status effects, and special cards.
 * It allows players to draw cards, add new cards, and check the current size of the deck.
 */
class Deck
{

public:

    /**
     * @brief Constructs a Deck and initializes it with a variety of cards.
     */
    Deck();

    /**
     * @brief Destroys the Deck instance.
     */
    ~Deck() = default;

    /**
     * @brief Draws a card from the deck.
     * @return A unique pointer to the drawn Card, or nullptr if the deck is empty.
     *
     * This method pops a card from the deck and returns it.
     */
    std::unique_ptr<Card> drawCard();

    /**
     * @brief Displays the current size of the deck.
     */
    void display() const;

    /**
     * @brief Adds a card to the deck.
     * @param card A unique pointer to the Card to be added.
     *
     * This method adds a card to the end of the deck.
     */
    void addCard(std::unique_ptr<Card> card);

    /**
     * @brief Initializes the deck with a set of pre-defined cards.
     *
     * This method adds a mix of attack, defense, magic, and special effect cards to the deck.
     */
    void initializeDeck();

    /**
     * @brief Checks if the deck is empty.
     * @return True if the deck is empty, false otherwise.
     */
    bool isEmpty();

    /**
     * @brief Gets the current size of the deck.
     * @return The number of cards currently in the deck.
     */
    const int getSize() const;

private:

    std::vector<std::unique_ptr<Card>> cards; /**< A vector of unique pointers to the cards in the deck */
};

#endif

