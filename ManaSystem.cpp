#include "ManaSystem.h"
#include <iostream>

bool ManaSystem::canCastMagicCard(Player& player, MagicCard* magicCard) {
    if (!magicCard) return false;
    return player.getMana() >= magicCard->getManaCost();
}

void ManaSystem::castMagicCard(Player& player, MagicCard* magicCard) {
    if (canCastMagicCard(player, magicCard)) {
        int manaCost = magicCard->getManaCost();
        player.reduceMana(manaCost);
        std::cout << "Mana reduced by " << manaCost << ". Remaining: " << player.getMana() << std::endl;
    } else {
        std::cout << "Not enough mana to play this card!" << std::endl;
    }
}
