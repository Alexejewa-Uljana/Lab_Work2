#include "gtest/gtest.h"
#include "Player.h"
#include "MagicCard.h"

TEST(Player, AddCardToDeck) {
    Player player;
    std::unique_ptr<Card> card = std::make_unique<MagicCard>(5, 5);
    player.addCardToDeck(std::move(card));
    EXPECT_EQ(3, player.getDeck()->getSize());
}

TEST(Player, DrawCard) {
    Player player;
    std::unique_ptr<Card> card = std::make_unique<MagicCard>(5, 5);
    player.addCardToDeck(std::move(card));
    int initialDeckSize = player.getDeck()->getSize();
    player.drawCards();
    EXPECT_EQ(3, player.getDeck()->getSize());
}

TEST(Player, RemoveCard) {
    Player player;
    std::unique_ptr<Card> card = std::make_unique<MagicCard>(5, 5);
    player.addCardToDeck(std::move(card));
    player.removeCard(0);
    EXPECT_EQ(3, player.getDeck()->getSize());
}

TEST(Player, ManaUsage) {
    Player player;
    int initialMana = player.getMana();
    player.reduceMana(10);
    EXPECT_EQ(initialMana - 10, player.getMana());
}

TEST(Player, ManaRestoration) {
    Player player;
    int initialMana = player.getMana();
    player.restoreMana(5);
    EXPECT_EQ(initialMana + 5, player.getMana());
}


