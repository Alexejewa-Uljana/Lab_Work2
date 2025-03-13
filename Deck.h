#ifndef DECK_H
#define DECK_H

#include <memory>
#include <vector>
#include "Card.h"
#include "Effect.h"
#include "StatusEffectCard.h"
#include "SpecialCard.h"

class Deck {
public:
    Deck(); // use initializeDeck
    std::unique_ptr<Card> drawCard(); // take out card from back of deck
    void display() const; // cout szie of cards
    void addCard(std::unique_ptr<Card> card); // Add card in the end of deck
    void initializeDeck(); // add 3 cards in Deck for start game
private:
    std::vector<std::unique_ptr<Card>> cards; // set of cards
};

#endif
