#include "gtest/gtest.h"
#include "Boss.h"

TEST(Boss, constructor)
{
    Boss boss("Dragon", 300);
    EXPECT_EQ("Dragon", boss.getName());
    EXPECT_EQ(300, boss.getHP());
}

TEST(Boss, specialAbility)
{
    Player player;
    Boss boss("Dragon", 300);
    boss.useSpecialAbility(player);
    EXPECT_EQ(player.getHP(), 0);
}

