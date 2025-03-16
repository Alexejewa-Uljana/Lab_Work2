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
    Deck();
    ~Deck() = default; 
    std::unique_ptr<Card> drawCard();
    void display() const;
    void addCard(std::unique_ptr<Card> card);
    void initializeDeck();
    bool isEmpty();
    const int getSize() const;
private:
    std::vector<std::unique_ptr<Card>> cards;
};

#endif
