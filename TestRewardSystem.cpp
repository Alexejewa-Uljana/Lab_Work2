#include "gtest/gtest.h"
#include "RewardSystem.h"
#include "Player.h"
#include "Card.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include "StatusEffectCard.h"
#include "SpecialCard.h"

TEST(RewardSystem, GiveReward_CorrectCardType) {
    Player player;
    RewardSystem::giveReward(player);
    EXPECT_TRUE(player.getDeck()->getSize() > 0);
}
