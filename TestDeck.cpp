#include "gtest/gtest.h"
#include "Deck.h"
#include "Card.h"
#include "AttackCard.h"
#include "MagicCard.h"
#include "DefenseCard.h"

TEST(Deck, Constructor) {
    Deck deck;
    EXPECT_EQ(deck.getSize(), 5);
}

TEST(Deck, AddCard) {
    Deck deck;
    std::unique_ptr<Card> attackCard = std::make_unique<AttackCard>(10);
    deck.addCard(std::move(attackCard));
    EXPECT_EQ(deck.getSize(), 6);
}

TEST(Deck, isEmpty) {
    Deck deck;
    EXPECT_EQ(deck.isEmpty(), false);
}
