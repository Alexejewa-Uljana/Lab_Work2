/**
 * @file TestBoss.cpp
 * @brief Contains test cases for the Boss class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "../include/Boss.h"

/**
 * @test constructor
 * @brief Tests the constructor of the Boss class.
 * 
 * Verifies that a Boss object is created with the correct name and HP.
 */
TEST(Boss, constructor) {
    Boss boss("Dragon", 300);

    EXPECT_EQ("Dragon", boss.getName());
    EXPECT_EQ(300, boss.getHP());
}

/**
 * @test specialAbility
 * @brief Tests the special ability of the Boss class.
 * 
 * Verifies that the special ability of the Boss can modify the player's HP correctly.
 */
TEST(Boss, specialAbility) {
    Player player;
    Boss boss("Dragon", 300);

    boss.useSpecialAbility(player);

    EXPECT_EQ(player.getHP(), 0);
}
