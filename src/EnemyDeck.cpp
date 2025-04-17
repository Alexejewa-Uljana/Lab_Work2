// Алексеева Ульяна st129990@student.spbu.ru
#include "../include/EnemyDeck.h"
#include <iostream>

/**
 * @brief Default constructor for the EnemyDeck.
 *
 * Initializes the deck to be empty.
 */
EnemyDeck::EnemyDeck() {}

/**
 * @brief Destructor for the EnemyDeck.
 *
 * Frees any resources used by the deck.
 */
EnemyDeck::~EnemyDeck() {}

/**
 * @brief Adds a card to the deck.
 * @param card A unique pointer to a Card that will be added to the deck.
 *
 * This method allows cards to be added to the deck for the enemy to use during combat.
 */
void EnemyDeck::addCard(std::unique_ptr<Card> card)
{
    deck.push_back(std::move(card));
}

/**
 * @brief Draws a card from the deck.
 * @return A unique pointer to a Card drawn from the deck, or nullptr if the deck is empty.
 *
 * This method removes and returns the top card of the deck. If the deck is empty, it returns nullptr.
 */
std::unique_ptr<Card> EnemyDeck::drawCard()
{
    if (!deck.empty())
    {
        auto card = std::move(deck.back());
        deck.pop_back();
        return card;
    }
    return nullptr;
}

/**
 * @brief Initializes the deck with default cards.
 *
 * This method adds a few specific cards (Attack and Defense cards) to the deck for the enemy.
 */
void EnemyDeck::initializeDeck()
{
    addCard(std::make_unique<AttackCard>(10));
    addCard(std::make_unique<DefenseCard>(7));
    addCard(std::make_unique<AttackCard>(10));
    addCard(std::make_unique<DefenseCard>(7));
    addCard(std::make_unique<AttackCard>(10));
    std::cout << "Deck initialized with cards.\n";
}

/**
 * @brief Gets the number of cards in the deck.
 * @return The number of cards currently in the deck.
 *
 * This method returns the current size of the deck.
 */
const int EnemyDeck::getSize() const
{
    return deck.size();
}
