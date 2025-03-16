#include "gtest/gtest.h"
#include "Game.h"

TEST(Game, constructor)
{
    Game game{2};
    bool fl = (2 == game.getDifficulty());
    EXPECT_EQ(1, fl);
}

TEST(Game, Start)
{
    Game game{2};
    game.start();
    bool fl = (game.isStarted());
    EXPECT_EQ(1, fl);
}
