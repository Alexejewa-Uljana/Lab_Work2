#include "gtest/gtest.h"
#include "AIController.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyDeck.h"

TEST(AIControllerTest, MakeMoveTest) {
    AIController ai;
    Enemy enemy;
    Player player;

    enemy.setHP(50);
    player.setHP(50);

    ai.makeMove(enemy, player);

    SUCCEED();
}
