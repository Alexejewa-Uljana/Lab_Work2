#include "Deck.h"
#include <iostream>
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include "StatusEffectCard.h"
#include "SpecialCard.h"

Deck::Deck() {
    initializeDeck();
}

void Deck::initializeDeck() {
    cards.push_back(std::make_unique<AttackCard>(5));
    cards.push_back(std::make_unique<DefenseCard>(5));
    cards.push_back(std::make_unique<MagicCard>(5, 5));
    cards.push_back(std::make_unique<StatusEffectCard>("Stun Card", 0, Effect("stun", 2)));
    cards.push_back(std::make_unique<SpecialCard>("Healing Potion", 0, Effect("heal", 10)));
}

std::unique_ptr<Card> Deck::drawCard() {
    if (!cards.empty()) {
        auto drawnCard = std::move(cards.back());
        cards.pop_back();
        return drawnCard;
    }
    else return nullptr;
}

void Deck::display() const {
    std::cout << "Deck contains " << cards.size() << " cards.\n";
}

void Deck::addCard(std::unique_ptr<Card> card) {
    cards.push_back(std::move(card));
    std::cout << "Card added to deck.\n";
}

bool Deck::isEmpty() {
    return cards.size() == 0;
}
