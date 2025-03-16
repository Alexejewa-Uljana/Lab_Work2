#include "gtest/gtest.h"
#include "MagicCard.h"
#include "Player.h"

TEST(MagicCard, Constructor) {
    MagicCard magicCard(5, 5);
    EXPECT_EQ(magicCard.getName(), "Magic Card");
    EXPECT_EQ(magicCard.getManaCost(), 5);
}

TEST(MagicCard, Play) {
    Player player;
    MagicCard magicCard(5, 5);
    player.reduceMana(magicCard.getManaCost());
    EXPECT_EQ(player.getMana(), 5);
}

TEST(MagicCard, ManaCost) {
    MagicCard magicCard(5, 5);
    EXPECT_EQ(magicCard.getManaCost(), 5);
}




