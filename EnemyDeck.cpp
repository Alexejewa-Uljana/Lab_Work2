#include "EnemyDeck.h"

void EnemyDeck::addCard(std::unique_ptr<Card> card) {
    cards.push_back(std::move(card));
}

std::unique_ptr<Card> EnemyDeck::drawCard() {
    if (cards.empty()) return nullptr;
    auto card = std::move(cards.back());
    cards.pop_back();
    return card;
}
