#include "gtest/gtest.h"
#include "BossAI.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyDeck.h"
TEST(BossAITest, TakeTurn) {
    Boss boss("Dark Lord", 100);
    BossAI bossAI(boss);
    Player player;
    boss.setHP(50);
    player.setHP(50);
    bossAI.takeTurn(boss, player);
    SUCCEED();
}

TEST(BossAITest, CastSpell) {
    Boss boss("Dark Lord", 100);
    BossAI bossAI(boss);
    Player player;
    boss.setHP(50);
    player.setHP(50);
    bossAI.castSpell(boss, player);
    SUCCEED();
}

TEST(BossAITest, Attack) {
    Boss boss("Dark Lord", 100);
    BossAI bossAI(boss);
    Player player;
    boss.setHP(50);
    player.setHP(50);
    bossAI.attack(boss, player);
    SUCCEED();
}


