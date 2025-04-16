/**
 * @file TestEnemyDeck.cpp
 * @brief Contains test cases for the EnemyDeck class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "EnemyDeck.h"
#include "Enemy.h"
#include "AttackCard.h"

/**
 * @test Constructor
 * @brief Tests the constructor of the EnemyDeck class.
 *
 * Verifies that the EnemyDeck object is created with the correct initial size.
 */
TEST(EnemyDeck, Constructor)
{
    EnemyDeck enemyDeck;

    EXPECT_EQ(enemyDeck.getSize(), 0);
}

/**
 * @test AddCard
 * @brief Tests the addCard function of the EnemyDeck class.
 *
 * Verifies that a new card is successfully added to the enemy deck.
 */
TEST(EnemyDeck, AddCard)
{
    EnemyDeck enemyDeck;

    std::unique_ptr<Card> attackCard = std::make_unique<AttackCard>(10);
    enemyDeck.addCard(std::move(attackCard));

    EXPECT_EQ(enemyDeck.getSize(), 1);
}

/**
 * @test DrawCard
 * @brief Tests the drawCard function of the EnemyDeck class.
 *
 * Verifies that the enemy can draw a card from its deck and that the deck size decreases.
 */
TEST(EnemyDeck, DrawCard)
{
    EnemyDeck enemyDeck;

    std::unique_ptr<Card> attackCard = std::make_unique<AttackCard>(10);
    enemyDeck.addCard(std::move(attackCard));

    std::unique_ptr<Card> drawnCard = enemyDeck.drawCard();

    EXPECT_EQ(drawnCard->getName(), "Attack Card");
    EXPECT_EQ(enemyDeck.getSize(), 0);
}
