#include "RewardSystem.h"
#include <iostream>
#include "cstdlib"

void RewardSystem::giveReward(Player& player) {
    Card* rewardCard = nullptr;
    int randomChoice = rand() % 3;
    if(randomChoice == 0) rewardCard = new AttackCard(10);
    else if(randomChoice == 1) rewardCard = new MagicCard(20);
    else rewardCard = new DefenseCard(15);
    std::cout << "Player received a new card!\n";
    rewardCard->claimReward(player);
    player.addCardToDeck(rewardCard);
}
