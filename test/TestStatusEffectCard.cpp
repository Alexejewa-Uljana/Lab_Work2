// Алексеева Ульяна st129990@student.spbu.ru

/**
 * @file TestStatusEffectCard.cpp
 * @brief Contains test cases for the StatusEffectCard class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "StatusEffectCard.h"
#include "Player.h"
#include "Effect.h"

/**
 * @test StatusEffectCardConstructor
 * @brief Tests the constructor of the StatusEffectCard class.
 *
 * Verifies that the card is initialized with correct name.
 */
TEST(StatusEffectCard, Constructor)
{
    StatusEffectCard statusEffectCard("Stun Card", 0, Effect("stun", 5));
    EXPECT_EQ(statusEffectCard.getName(), "Stun Card");
}

/**
 * @test StatusEffectCardPlay
 * @brief Tests the play effect of the StatusEffectCard.
 *
 * Checks if the card correctly stuns the enemy.
 */
TEST(StatusEffectCard, Play)
{
    Enemy enemy;
    StatusEffectCard statusEffectCard("Stun Card", 0, Effect("stun", 5));
    enemy.setStunned(statusEffectCard.getEffect().value);
    EXPECT_TRUE(enemy.isStunned());
}
