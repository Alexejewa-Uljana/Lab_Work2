#include "RewardSystem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void RewardSystem::giveReward(Player& player) {
    srand(static_cast<unsigned>(time(nullptr)));
    int randomReward = rand() % 3;

    std::unique_ptr<Card> reward;
    if (randomReward == 0) {
        reward = std::make_unique<AttackCard>(10);
        std::cout << "You received an Attack Card!" << std::endl;
    } else if (randomReward == 1) {
        reward = std::make_unique<MagicCard>(20);
        std::cout << "You received a Magic Card!" << std::endl;
    } else {
        reward = std::make_unique<DefenseCard>(15);
        std::cout << "You received a Defense Card!" << std::endl;
    }

    player.addCardToDeck(std::move(reward));
}
