/**
 * @file TestEnemy.cpp
 * @brief Contains test cases for the Enemy class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "../include/Enemy.h"
#include "../include/Player.h"
#include "../include/EnemyDeck.h"
#include "../include/AIController.h"

/**
 * @test constructor
 * @brief Tests the constructor of the Enemy class.
 * 
 * Verifies that the Enemy object is created with the correct name and HP.
 */
TEST(Enemy, constructor) {
    Enemy enemy("Goblin", 100);

    EXPECT_EQ("Goblin", enemy.getName());
    EXPECT_EQ(100, enemy.getHP());
}

/**
 * @test takeDamage
 * @brief Tests the takeDamage function of the Enemy class.
 * 
 * Verifies that the Enemy object's HP decreases correctly when damage is taken.
 */
TEST(Enemy, takeDamage) {
    Enemy enemy("Goblin", 100);

    enemy.takeDamage(30);

    EXPECT_EQ(70, enemy.getHP());

    enemy.takeDamage(100);

    EXPECT_EQ(0, enemy.getHP());
}

/**
 * @test attack
 * @brief Tests the attack function of the Enemy class.
 * 
 * Verifies that the Enemy attacks the player and reduces their HP.
 */
TEST(Enemy, attack) {
    Player player;
    Enemy enemy("Goblin", 100);
    AIController aiController;

    enemy.setAIController(&aiController);
    enemy.attack(player, 20);

    EXPECT_EQ(true, player.getHP() < 50);
}

/**
 * @test defend
 * @brief Tests the defend function of the Enemy class.
 * 
 * Verifies that the Enemy's HP increases when it defends.
 */
TEST(Enemy, defend) {
    Enemy enemy("Goblin", 100);

    enemy.defend(20);

    EXPECT_EQ(120, enemy.getHP());
}

/**
 * @test stun
 * @brief Tests the stun functionality of the Enemy class.
 * 
 * Verifies that the Enemy can be stunned and that the stun turns decrease as expected.
 */
TEST(Enemy, stun) {
    Enemy enemy("Goblin", 100);

    enemy.setStunned(3);

    EXPECT_TRUE(enemy.isStunned());
    EXPECT_EQ(3, enemy.getStunnedTurns());

    enemy.increaseStunnedTurns();

    EXPECT_EQ(2, enemy.getStunnedTurns());

    enemy.increaseStunnedTurns();

    EXPECT_EQ(1, enemy.getStunnedTurns());

    enemy.increaseStunnedTurns();

    EXPECT_EQ(0, enemy.getStunnedTurns());

    EXPECT_FALSE(enemy.isStunned());
}

/**
 * @test castSpell
 * @brief Tests the castSpell function of the Enemy class.
 * 
 * Verifies that the Enemy casts a spell on the player, decreasing the player's HP.
 */
TEST(Enemy, castSpell) {
    Player player;
    Enemy enemy("Goblin", 100);

    enemy.castSpell(player, 30);

    EXPECT_EQ(20, player.getHP());
}
