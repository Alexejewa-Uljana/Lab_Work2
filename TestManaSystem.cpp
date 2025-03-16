#include "gtest/gtest.h"
#include "ManaSystem.h"
#include "Player.h"
#include "MagicCard.h"

TEST(ManaSystem, CanCastMagicCard_EnoughMana) {
    Player player;
    MagicCard magicCard(10, 5);
    EXPECT_TRUE(ManaSystem::canCastMagicCard(player, &magicCard));
}

TEST(ManaSystem, CanCastMagicCard_NotEnoughMana) {
    Player player;
    MagicCard magicCard(10, 15);
    EXPECT_FALSE(ManaSystem::canCastMagicCard(player, &magicCard));
}

TEST(ManaSystem, CastMagicCard_ReduceMana) {
    Player player;
    MagicCard magicCard(10, 5);
    ManaSystem::castMagicCard(player, &magicCard);
    EXPECT_EQ(player.getMana(), 5);
}

TEST(ManaSystem, CastMagicCard_NotEnoughMana) {
    Player player;
    MagicCard magicCard(10, 15);
    ManaSystem::castMagicCard(player, &magicCard);
    EXPECT_EQ(player.getMana(), 10);
}
