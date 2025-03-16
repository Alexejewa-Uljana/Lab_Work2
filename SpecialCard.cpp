#include "SpecialCard.h"
#include "Effect.h"
#include <iostream>

SpecialCard::SpecialCard(const std::string& name, int power, Effect effect)
        : Card(name, power), effect(effect) {}

void SpecialCard::play() {
    std::cout << "Using special card: " << getName() << "\n";
}

void SpecialCard::claimReward(Player& player) {
    std::cout << "Claiming special card reward: " << getName() << "\n";
}

Effect SpecialCard::getEffect() const {
    return effect;
}
