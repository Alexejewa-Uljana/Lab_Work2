#include "gtest/gtest.h"
#include "AttackCard.h"
#include "Player.h"
#include "Enemy.h"

TEST(AttackCard, Constructor) {
    AttackCard attackCard(10);
    EXPECT_EQ(attackCard.getName(), "Attack Card");
    EXPECT_EQ(attackCard.getPower(), 10);
}

TEST(AttackCard, Play) {
    Player player;
    AttackCard attackCard(10);
    Enemy enemy("Goblin", 30);
    int initialEnemyHP = enemy.getHP();
    enemy.takeDamage(attackCard.getPower());
    EXPECT_LT(enemy.getHP(), initialEnemyHP);
}
