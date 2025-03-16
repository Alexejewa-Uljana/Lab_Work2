#include "gtest/gtest.h"
#include "SpecialCard.h"
#include "Player.h"
#include "Effect.h"

TEST(SpecialCard, Constructor) {
    SpecialCard specialCard("Health Card", 0, Effect("heal", 5));
    EXPECT_EQ(specialCard.getName(), "Health Card");
    EXPECT_EQ(specialCard.getEffect().type, "heal");
}

TEST(SpecialCard, Play) {
    Player player;
    SpecialCard specialCard("Health Card", 0, Effect("heal", 10));
    int initialHealth = player.getHP();
    player.restoreHealth(specialCard.getEffect().value);
    EXPECT_EQ(player.getHP(), initialHealth + 10);
}
