#include "RewardSystem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Gives a random reward to the player.
 * 
 * This method randomly selects a card as a reward and adds it to the player's deck.
 * The types of rewards include Attack, Magic, Defense, Status Effect, and Special cards.
 * 
 * @param player The player receiving the reward.
 */
void RewardSystem::giveReward(Player& player) {
    srand(static_cast<unsigned>(time(nullptr)));

    int rewardType = rand() % 5;

    std::unique_ptr<Card> reward;

    switch (rewardType) {
        case 0: reward = std::make_unique<AttackCard>(10); break;
        case 1: reward = std::make_unique<MagicCard>(20, 5); break;
        case 2: reward = std::make_unique<DefenseCard>(15); break;
        case 3: reward = std::make_unique<StatusEffectCard>("Stun Card", 0, Effect("stun", 5)); break;
        case 4: reward = std::make_unique<SpecialCard>("Mana Boost", 0, Effect("mana", 5)); break;
    }

    player.addCardToDeck(std::move(reward));
    std::cout << "You received a new card as a reward!\n";
}
