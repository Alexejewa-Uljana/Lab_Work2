#include "RewardSystem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void RewardSystem::giveReward(Player& player) {
    srand(static_cast<unsigned>(time(nullptr)));
    int randomReward = rand() % 5;

    std::unique_ptr<Card> reward;
    if (randomReward == 0) {
        reward = std::make_unique<AttackCard>(10);
        std::cout << "You received an Attack Card!\n";
    }
    else if (randomReward == 1) {
        reward = std::make_unique<MagicCard>(20, 5);
        std::cout << "You received a Magic Card!\n";
    }
    else if (randomReward == 2) {
        reward = std::make_unique<DefenseCard>(15);
        std::cout << "You received a Defense Card!\n";
    }
    else if (randomReward == 3) {
        reward = std::make_unique<StatusEffectCard>("Stun card", 0, Effect("stun", 5));
        std::cout << "You received a Status Effect Card for stun!\n";
    }
    else {
        reward = std::make_unique<SpecialCard>("Special card", 0, Effect("mana", 5));
        std::cout << "You received a Special card for mana!\n";
    }

    player.addCardToDeck(std::move(reward));
}
