/**
 * @file TestStatusEffectCard.cpp
 * @brief Unit tests for the StatusEffectCard class functionality.
 */

#include "gtest/gtest.h"
#include "../include/StatusEffectCard.h"
#include "../include/Player.h"
#include "../include/Effect.h"

/**
 * @brief Tests the StatusEffectCard constructor and naming.
 */
TEST(StatusEffectCard, Constructor) {
    StatusEffectCard statusEffectCard("Stun Card", 0, Effect("stun", 5));
    EXPECT_EQ(statusEffectCard.getName(), "Stun Card");
}

/**
 * @brief Tests the status effect application to enemies.
 */
TEST(StatusEffectCard, Play) {
    Enemy enemy;
    StatusEffectCard statusEffectCard("Stun Card", 0, Effect("stun", 5));
    enemy.setStunned(statusEffectCard.getEffect().value);
    EXPECT_TRUE(enemy.isStunned());
}
