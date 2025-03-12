#ifndef REWARD_SYSTEM_H
#define REWARD_SYSTEM_H

#include <vector>
#include "Card.h"
#include "MagicCard.h"
#include "DefenseCard.h"
#include "AttackCard.h"

class RewardSystem {
public:
    void giveReward(Player& player);
private:
    std::vector<Card*> rewards;
};

#endif
