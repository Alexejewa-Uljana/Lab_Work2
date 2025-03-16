/**
 * @file TestBossAI.cpp
 * @brief Contains test cases for the BossAI class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "BossAI.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyDeck.h"

/**
 * @test TakeTurn
 * @brief Tests the takeTurn function of the BossAI class.
 * 
 * Verifies that the boss AI can take its turn and interact with the player.
 */
TEST(BossAITest, TakeTurn) {
    Boss boss("Dark Lord", 100);
    BossAI bossAI(boss);
    Player player;

    boss.setHP(50);
    player.setHP(50);

    bossAI.takeTurn(boss, player);

    SUCCEED();
}

/**
 * @test CastSpell
 * @brief Tests the castSpell function of the BossAI class.
 * 
 * Verifies that the boss AI can cast a spell on the player.
 */
TEST(BossAITest, CastSpell) {
    Boss boss("Dark Lord", 100);
    BossAI bossAI(boss);
    Player player;

    boss.setHP(50);
    player.setHP(50);

    bossAI.castSpell(boss, player);

    SUCCEED();
}

/**
 * @test Attack
 * @brief Tests the attack function of the BossAI class.
 * 
 * Verifies that the boss AI can attack the player.
 */
TEST(BossAITest, Attack) {
    Boss boss("Dark Lord", 100);
    BossAI bossAI(boss);
    Player player;

    boss.setHP(50);
    player.setHP(50);

    bossAI.attack(boss, player);

    SUCCEED();
}
