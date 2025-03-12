#include "Deck.h"
#include <iostream>
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"

Deck::Deck() {
    initializeDeck();
}

void Deck::initializeDeck() {
    cards.push_back(new AttackCard(5));
    cards.push_back(new DefenseCard(5));
    cards.push_back(new MagicCard(5));
}

Card* Deck::drawCard() {
    if (!cards.empty()) {
        Card* drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    }
    return nullptr;
}

void Deck::display() const {
    std::cout << "Deck contains " << cards.size() << " cards.\n";
}

void Deck::addCard(Card* card) {
    if(card) {
        cards.push_back(card);
        std::cout << "Card added to deck.\n";
    }
    else {
        std::cout << "Cannot add null card!\n";
    }
}
