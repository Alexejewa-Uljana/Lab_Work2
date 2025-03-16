#include "StatusEffectCard.h"
#include <iostream>

StatusEffectCard::StatusEffectCard(const std::string& name, int power, Effect effect)
        : Card(name, power), effect(effect) {}

void StatusEffectCard::play() {
        std::cout << "Using status effect card: " << getName() << "\n";
    }

void StatusEffectCard::claimReward(Player& player) {
    std::cout << "Claiming reward from: " << getName() << "\n";
}

Effect StatusEffectCard::getEffect() const {
    return effect;
}
