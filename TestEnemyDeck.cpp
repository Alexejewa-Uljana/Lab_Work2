#include "gtest/gtest.h"
#include "EnemyDeck.h"
#include "Enemy.h"
#include "AttackCard.h"

TEST(EnemyDeck, Constructor) {
    EnemyDeck enemyDeck;
    EXPECT_EQ(enemyDeck.getSize(), 0);
}

TEST(EnemyDeck, AddCard) {
    EnemyDeck enemyDeck;
    std::unique_ptr<Card> attackCard = std::make_unique<AttackCard>(10);
    enemyDeck.addCard(std::move(attackCard));
    EXPECT_EQ(enemyDeck.getSize(), 1);
}

TEST(EnemyDeck, DrawCard) {
    EnemyDeck enemyDeck;
    std::unique_ptr<Card> attackCard = std::make_unique<AttackCard>(10);
    enemyDeck.addCard(std::move(attackCard));
    std::unique_ptr<Card> drawnCard = enemyDeck.drawCard();
    EXPECT_EQ(drawnCard->getName(), "Attack Card");
    EXPECT_EQ(enemyDeck.getSize(), 0);
}

