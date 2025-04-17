#include "../include/Deck.h"
#include <iostream>
#include <cstdlib>
#include "../include/AttackCard.h"
#include "../include/DefenseCard.h"
#include "../include/MagicCard.h"
#include "../include/StatusEffectCard.h"
#include "../include/SpecialCard.h"

/**
 * @brief Constructs a Deck and initializes it with a variety of cards.
 */
Deck::Deck() {
    initializeDeck();
}

/**
 * @brief Initializes the deck with a set of pre-defined cards.
 * 
 * This method adds a mix of attack, defense, magic, and special effect cards to the deck.
 */
void Deck::initializeDeck() {
    cards.push_back(std::make_unique<AttackCard>(rand() % 10 + 10));
    cards.push_back(std::make_unique<DefenseCard>(rand() % 10 + 5));
    cards.push_back(std::make_unique<MagicCard>(rand() % 15 + 10, rand() % 5 + 5));
    cards.push_back(std::make_unique<StatusEffectCard>("Healing Potion", 0, Effect("heal", rand() % 5 + 5)));
    cards.push_back(std::make_unique<SpecialCard>("Healing Potion", 0, Effect("heal", rand() % 10 + 5)));
}

/**
 * @brief Gets the current size of the deck.
 * @return The number of cards currently in the deck.
 */
const int Deck::getSize() const {
    return cards.size();
}

/**
 * @brief Draws a card from the deck.
 * @return A unique pointer to the drawn Card, or nullptr if the deck is empty.
 * 
 * This method pops a card from the deck and returns it.
 */
std::unique_ptr<Card> Deck::drawCard() {
    if (!cards.empty()) {
        auto drawnCard = std::move(cards.back());
        cards.pop_back();
        return drawnCard;
    } else {
        return nullptr;
    }
}

/**
 * @brief Displays the current size of the deck.
 */
void Deck::display() const {
    std::cout << "Deck contains " << cards.size() << " cards.\n";
}

/**
 * @brief Adds a card to the deck.
 * @param card A unique pointer to the Card to be added.
 * 
 * This method adds a card to the end of the deck.
 */
void Deck::addCard(std::unique_ptr<Card> card) {
    cards.push_back(std::move(card));
    std::cout << "Card added to deck.\n";
}

/**
 * @brief Checks if the deck is empty.
 * @return True if the deck is empty, false otherwise.
 */
bool Deck::isEmpty() {
    return cards.size() == 0;
}
