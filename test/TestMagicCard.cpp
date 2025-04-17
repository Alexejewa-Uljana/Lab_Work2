/**
 * @file TestMagicCard.cpp
 * @brief Unit tests for the MagicCard class.
 */

#include "gtest/gtest.h"
#include "../include/MagicCard.h"
#include "../include/Player.h"

/**
 * @brief Tests the constructor of the MagicCard class.
 * 
 * Checks if the card is correctly initialized with a name and mana cost.
 */
TEST(MagicCard, Constructor) {
    MagicCard magicCard(5, 5);
    EXPECT_EQ(magicCard.getName(), "Magic Card");
    EXPECT_EQ(magicCard.getManaCost(), 5);
}

/**
 * @brief Tests playing a MagicCard.
 * 
 * The player's mana should decrease by the card's mana cost.
 */
TEST(MagicCard, Play) {
    Player player;
    MagicCard magicCard(5, 5);
    player.reduceMana(magicCard.getManaCost());
    EXPECT_EQ(player.getMana(), 5);
}

/**
 * @brief Tests the retrieval of the mana cost of a MagicCard.
 */
TEST(MagicCard, ManaCost) {
    MagicCard magicCard(5, 5);
    EXPECT_EQ(magicCard.getManaCost(), 5);
}

