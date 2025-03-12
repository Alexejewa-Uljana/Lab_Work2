#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    Card* drawCard();
    void display() const;
    void addCard(Card* card);
private:
    std::vector<Card*> cards;
    void initializeDeck();
};

#endif
