// Алексеева Ульяна st129990@student.spbu.ru

/**
 * @file TestDeck.cpp
 * @brief Contains test cases for the Deck class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "../include/Deck.h"
#include "../include/Card.h"
#include "../include/AttackCard.h"
#include "../include/MagicCard.h"
#include "../include/DefenseCard.h"

/**
 * @test Constructor
 * @brief Tests the constructor of the Deck class.
 *
 * Verifies that the Deck object is initialized with the correct size.
 */
TEST(Deck, Constructor)
{
    Deck deck;

    EXPECT_EQ(deck.getSize(), 5);
}

/**
 * @test AddCard
 * @brief Tests the addCard function of the Deck class.
 *
 * Verifies that adding a new card to the deck increases the size of the deck.
 */
TEST(Deck, AddCard)
{
    Deck deck;

    std::unique_ptr<Card> attackCard = std::make_unique<AttackCard>(10);
    deck.addCard(std::move(attackCard));

    EXPECT_EQ(deck.getSize(), 6);
}

/**
 * @test isEmpty
 * @brief Tests the isEmpty function of the Deck class.
 *
 * Verifies that the deck is not empty after adding a card.
 */
TEST(Deck, isEmpty)
{
    Deck deck;

    EXPECT_EQ(deck.isEmpty(), false);
}



