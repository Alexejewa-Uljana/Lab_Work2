/**
 * @file TestAttackCard.cpp
 * @brief Contains test cases for the AttackCard class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "../include/AttackCard.h"
#include "../include/Player.h"
#include "../include/Enemy.h"

/**
 * @test Constructor
 * @brief Tests the constructor of the AttackCard class.
 * 
 * Verifies that the name and power of the AttackCard are set correctly.
 */
TEST(AttackCard, Constructor) {
    AttackCard attackCard(10);

    EXPECT_EQ(attackCard.getName(), "Attack Card");
    EXPECT_EQ(attackCard.getPower(), 10);
}

/**
 * @test Play
 * @brief Tests the play function of the AttackCard class.
 * 
 * Verifies that the attack power of the AttackCard is applied correctly to the enemy.
 */
TEST(AttackCard, Play) {
    Player player;
    AttackCard attackCard(10);
    Enemy enemy("Goblin", 30);

    int initialEnemyHP = enemy.getHP();
    enemy.takeDamage(attackCard.getPower());

    EXPECT_LT(enemy.getHP(), initialEnemyHP);
}
