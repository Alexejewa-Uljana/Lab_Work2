#include "gtest/gtest.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyDeck.h"
#include "AIController.h"

TEST(Enemy, constructor) {
    Enemy enemy("Goblin", 100);
    EXPECT_EQ("Goblin", enemy.getName());
    EXPECT_EQ(100, enemy.getHP());
}

TEST(Enemy, takeDamage) {
    Enemy enemy("Goblin", 100);
    enemy.takeDamage(30);
    EXPECT_EQ(70, enemy.getHP());
    enemy.takeDamage(100);
    EXPECT_EQ(0, enemy.getHP());
}

TEST(Enemy, attack) {
    Player player;
    Enemy enemy("Goblin", 100);
    AIController aiController;
    enemy.setAIController(&aiController);
    enemy.attack(player, 20);
    EXPECT_EQ(true, player.getHP() < 50);
}

TEST(Enemy, defend) {
    Enemy enemy("Goblin", 100);
    enemy.defend(20);

    EXPECT_EQ(120, enemy.getHP());
}

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

TEST(Enemy, castSpell) {
    Player player;
    Enemy enemy("Goblin", 100);
    enemy.castSpell(player, 30);
    EXPECT_EQ(20, player.getHP());
}

