// Алексеева Ульяна st129990@student.spbu.ru

/**
 * @file TestManaSystem.cpp
 * @brief Unit tests for the ManaSystem class.
 */

#include "gtest/gtest.h"
#include "../include/ManaSystem.h"
#include "../include/Player.h"
#include "../include/MagicCard.h"

/**
 * @brief Tests if the ManaSystem correctly determines if a magic card can be cast when enough mana is available.
 */
TEST(ManaSystem, CanCastMagicCard_EnoughMana)
{
    Player player;
    MagicCard magicCard(10, 5);
    EXPECT_TRUE(ManaSystem::canCastMagicCard(player, &magicCard));
}

/**
 * @brief Tests if the ManaSystem correctly determines if a magic card cannot be cast due to insufficient mana.
 */
TEST(ManaSystem, CanCastMagicCard_NotEnoughMana)
{
    Player player;
    MagicCard magicCard(10, 15);
    EXPECT_FALSE(ManaSystem::canCastMagicCard(player, &magicCard));
}

/**
 * @brief Tests if the ManaSystem correctly reduces mana after casting a magic card.
 */
TEST(ManaSystem, CastMagicCard_ReduceMana)
{
    Player player;
    MagicCard magicCard(10, 5);
    ManaSystem::castMagicCard(player, &magicCard);
    EXPECT_EQ(player.getMana(), 5);
}

/**
 * @brief Tests if the ManaSystem does not reduce mana when there is not enough mana to cast a magic card.
 */
TEST(ManaSystem, CastMagicCard_NotEnoughMana)
{
    Player player;
    MagicCard magicCard(10, 15);
    ManaSystem::castMagicCard(player, &magicCard);
    EXPECT_EQ(player.getMana(), 10);
}



