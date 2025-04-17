#include "gtest/gtest.h"
#include "StatusEffectCard.h"
#include "Player.h"
#include "Effect.h"

TEST(StatusEffectCard, Constructor) {
    StatusEffectCard statusEffectCard("Stun Card", 0, Effect("stun", 5));
    EXPECT_EQ(statusEffectCard.getName(), "Stun Card");
}

TEST(StatusEffectCard, Play) {
    Enemy enemy;
    StatusEffectCard statusEffectCard("Stun Card", 0, Effect("stun", 5));
    enemy.setStunned(statusEffectCard.getEffect().value);
    EXPECT_TRUE(enemy.isStunned() == true);
}

