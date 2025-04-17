/**
 * @file TestPlayer.cpp
 * @brief Unit tests for the Player class.
 */

#include "gtest/gtest.h"
#include "../includePlayer.h"
#include "../includeMagicCard.h"

/**
 * @brief Tests adding a card to the player's deck.
 * 
 * The deck size should increase after adding a new card.
 */
TEST(Player, AddCardToDeck) {
    Player player;
    std::unique_ptr<Card> card = std::make_unique<MagicCard>(5, 5);
    player.addCardToDeck(std::move(card));
    EXPECT_EQ(3, player.getDeck()->getSize());
}

/**
 * @brief Tests the player's ability to draw a card.
 */
TEST(Player, DrawCard) {
    Player player;
    std::unique_ptr<Card> card = std::make_unique<MagicCard>(5, 5);
    player.addCardToDeck(std::move(card));
    player.drawCards();
    EXPECT_EQ(3, player.getDeck()->getSize());
}

/**
 * @brief Tests removing a card from the player's deck.
 */
TEST(Player, RemoveCard) {
    Player player;
    std::unique_ptr<Card> card = std::make_unique<MagicCard>(5, 5);
    player.addCardToDeck(std::move(card));
    player.removeCard(0);
    EXPECT_EQ(3, player.getDeck()->getSize());
}

/**
 * @brief Tests the player's mana usage.
 */
TEST(Player, ManaUsage) {
    Player player;
    int initialMana = player.getMana();
    player.reduceMana(10);
    EXPECT_EQ(initialMana - 10, player.getMana());
}

/**
 * @brief Tests the player's mana restoration.
 */
TEST(Player, ManaRestoration) {
    Player player;
    int initialMana = player.getMana();
    player.restoreMana(5);
    EXPECT_EQ(initialMana + 5, player.getMana());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
