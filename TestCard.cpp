#include "gtest/gtest.h"
#include "Card.h"
#include "AttackCard.h"
#include "MagicCard.h"
#include "DefenseCard.h"

TEST(Card, Constructor) {
    Card card("AttackCard", 10);
    EXPECT_EQ(card.getName(), "AttackCard");
    EXPECT_EQ(card.getPower(), 10);
}


