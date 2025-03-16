#include "gtest/gtest.h"
#include "World.h"

TEST(World, constructor) {
    World world;
    EXPECT_EQ(1, world.getLevel());
}

TEST(World, load) {
    World world;
    world.load();
    EXPECT_EQ(1, world.getLevel());
}

TEST(World, getLevel) {
    World world;
    EXPECT_EQ(1, world.getLevel());
    world.load();
    EXPECT_EQ(1, world.getLevel());
}


