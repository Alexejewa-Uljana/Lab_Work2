#include "ManaSystem.h"
#include <iostream>

ManaSystem::ManaSystem() : mana(10) {}

void ManaSystem::useMana(int amount) {
    if (mana >= amount) {
        mana -= amount;
    } else {
        std::cout << "Not enough mana!" << std::endl;
    }
}

void ManaSystem::restoreMana(int amount) {
    mana += amount;
}

int ManaSystem::getMana() const {
    return mana;
}
