/**
 * @file TestDefenseCard.cpp
 * @brief Contains test cases for the DefenseCard class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "DefenseCard.h"
#include "Player.h"

/**
 * @test Constructor
 * @brief Tests the constructor of the DefenseCard class.
 * 
 * Verifies that the DefenseCard is created with the correct name and power.
 */
TEST(DefenseCard, Constructor) {
    DefenseCard defenseCard(5);

    EXPECT_EQ(defenseCard.getName(), "Defense Card");
    EXPECT_EQ(defenseCard.getPower(), 5);
}

/**
 * @test Play
 * @brief Tests the play function of the DefenseCard class.
 * 
 * Verifies that playing the DefenseCard heals the player by the correct amount.
 */
TEST(DefenseCard, Play) {
    Player player;
    DefenseCard defenseCard(-5);

    player.heal(defenseCard.getPower());

    EXPECT_EQ(player.getHP(), 45);
}
