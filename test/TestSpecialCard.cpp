// Алексеева Ульяна st129990@student.spbu.ru

/**
 * @file TestSpecialCard.cpp
 * @brief Contains test cases for the SpecialCard class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "../include/SpecialCard.h"
#include "../include/Player.h"
#include "../include/Effect.h"

/**
 * @test SpecialCardConstructor
 * @brief Tests the constructor of the SpecialCard class.
 *
 * Verifies that the card is initialized with correct name and effect.
 */
TEST(SpecialCard, Constructor)
{
    SpecialCard specialCard("Health Card", 0, Effect("heal", 5));
    EXPECT_EQ(specialCard.getName(), "Health Card");
    EXPECT_EQ(specialCard.getEffect().type, "heal");
}

/**
 * @test SpecialCardPlay
 * @brief Tests the play effect of the SpecialCard.
 *
 * Checks if the card correctly restores player's health.
 */
TEST(SpecialCard, Play)
{
    Player player;
    SpecialCard specialCard("Health Card", 0, Effect("heal", 10));
    int initialHealth = player.getHP();
    player.restoreHealth(specialCard.getEffect().value);
    EXPECT_EQ(player.getHP(), initialHealth + 10);
}
