#include "EnemyDeck.h"
#include <iostream>

EnemyDeck::EnemyDeck() {}

void EnemyDeck::addCard(std::unique_ptr<Card> card) {
    deck.push_back(std::move(card));
}

std::unique_ptr<Card> EnemyDeck::drawCard() {
    if (!deck.empty()) {
        auto card = std::move(deck.back());
        deck.pop_back();
        return card;
    }
    return nullptr;
}

void EnemyDeck::initializeDeck() {
    addCard(std::make_unique<AttackCard>(10));
    addCard(std::make_unique<DefenseCard>(7));
    addCard(std::make_unique<AttackCard>(10));
    addCard(std::make_unique<DefenseCard>(7));
    addCard(std::make_unique<AttackCard>(10));
    std::cout << "Deck initialized with cards.\n";
}



