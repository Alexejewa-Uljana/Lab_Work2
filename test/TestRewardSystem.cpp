/**
 * @file TestRewardSystem.cpp
 * @brief Unit tests for the RewardSystem class.
 */

#include "gtest/gtest.h"
#include "../include/RewardSystem.h"
#include "../include/Player.h"

/**
 * @brief Tests if the reward system correctly adds a card to the player's deck.
 */
TEST(RewardSystem, GiveReward_CorrectCardType) {
    Player player;
    RewardSystem::giveReward(player);
    EXPECT_TRUE(player.getDeck()->getSize() > 0);
}
