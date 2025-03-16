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

TEST(PlayerTest, SetAndGetHP) {
    Player player;
    player.setHP(40);
    EXPECT_EQ(player.getHP(), 40);
}

TEST(PlayerTest, HealTest) {
    Player player;
    player.setHP(30);
    player.heal(10);
    EXPECT_EQ(player.getHP(), 40);

    player.heal(20);
    EXPECT_EQ(player.getHP(), 50);
}

TEST(PlayerTest, TakeDamageTest) {
    Player player;
    player.setHP(50);
    player.takeDamage(20);
    EXPECT_EQ(player.getHP(), 30);
    player.takeDamage(30);
    EXPECT_EQ(player.getHP(), 0);
}

TEST(PlayerTest, IncreaseAttackPower) {
    Player player;
    player.increaseAttackPower(5);
    EXPECT_EQ(player.getAttackPower(), 10);

    player.increaseAttackPower(-3);
    EXPECT_EQ(player.getAttackPower(), 7);
}
