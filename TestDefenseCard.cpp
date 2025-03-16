#include "gtest/gtest.h"
#include "DefenseCard.h"
#include "Player.h"

TEST(DefenseCard, Constructor) {
    DefenseCard defenseCard(5);
    EXPECT_EQ(defenseCard.getName(), "Defense Card");
    EXPECT_EQ(defenseCard.getPower(), 5);
}

TEST(DefenseCard, Play) {
    Player player;
    DefenseCard defenseCard(-5);
    player.heal(defenseCard.getPower());
    EXPECT_EQ(player.getHP(), 45);
}


