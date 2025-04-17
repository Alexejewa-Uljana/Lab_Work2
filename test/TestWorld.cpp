// Алексеева Ульяна st129990@student.spbu.ru

/**
 * @file TestWorld.cpp
 * @brief Unit tests for the World class.
 */

#include "gtest/gtest.h"
#include "../include/World.h"

/**
 * @brief Tests the constructor of the World class.
 */
TEST(World, constructor)
{
    World world;
    EXPECT_EQ(1, world.getLevel());
}

/**
 * @brief Tests the load functionality of the World class.
 */
TEST(World, load)
{
    World world;
    world.load();
    EXPECT_EQ(1, world.getLevel());
}

/**
 * @brief Tests the getLevel function of the World class.
 */
TEST(World, getLevel)
{
    World world;
    EXPECT_EQ(1, world.getLevel());
    world.load();
    EXPECT_EQ(1, world.getLevel());
}
