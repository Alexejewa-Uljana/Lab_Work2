// Алексеева Ульяна st129990@student.spbu.ru

/**
 * @file TestAIController.cpp
 * @brief Contains test cases for the AIController class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "../include/AIController.h"
#include "../include/Enemy.h"
#include "../include/Player.h"
#include "../include/EnemyDeck.h"

/**
 * @test MakeMoveTest
 * @brief Tests the makeMove function of the AIController class.
 *
 * Verifies that the AI makes a move without throwing any exceptions.
 */
TEST(AIControllerTest, MakeMoveTest)
{
    AIController ai;
    Enemy enemy;
    Player player;

    enemy.setHP(50);
    player.setHP(50);

    ai.makeMove(enemy, player);

    SUCCEED();
}
