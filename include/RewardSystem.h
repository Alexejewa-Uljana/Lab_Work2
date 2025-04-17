#ifndef REWARD_SYSTEM_H
#define REWARD_SYSTEM_H

#include "Player.h"
#include "Card.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include <memory>

/**
 * @class RewardSystem
 * @brief Handles the reward system for the player.
 *
 * The RewardSystem class is responsible for giving random rewards to the player.
 * Rewards are randomly chosen from a pool of card types.
 */
class RewardSystem
{

public:

    /**
     * @brief Gives a random reward to the player.
     * @param player The player to receive the reward.
     */
    static void giveReward(Player& player);

};

#endif
