#ifndef REWARD_SYSTEM_H
#define REWARD_SYSTEM_H

#include "Player.h"
#include "Card.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include <memory>

class RewardSystem {
public:
    static void giveReward(Player& player);
};

#endif
