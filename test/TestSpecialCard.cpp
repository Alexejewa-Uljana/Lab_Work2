// Алексеева Ульяна st129990@student.spbu.ru

/**
 * @file TestSpecialCard.cpp
 * @brief Unit tests for the SpecialCard class functionality.
 */

#include "gtest/gtest.h"
#include "../include/SpecialCard.h"  // Fixed missing space
#include "../include/Player.h"
#include "../include/Effect.h"  // Fixed missing space

/**
 * @brief Tests the SpecialCard constructor and basic properties.
 */
TEST(SpecialCard, Constructor)
{
    SpecialCard specialCard("Health Card", 0, Effect("heal", 5));
    EXPECT_EQ(specialCard.getName(), "Health Card");
    EXPECT_EQ(specialCard.getEffect().type, "heal");
}

/**
 * @brief Tests the card playing mechanics and health restoration.
 */
TEST(SpecialCard, Play)
{
    Player player;
    SpecialCard specialCard("Health Card", 0, Effect("heal", 10));
    int initialHealth = player.getHP();
    player.restoreHealth(specialCard.getEffect().value);
    EXPECT_EQ(player.getHP(), initialHealth + 10);
}
