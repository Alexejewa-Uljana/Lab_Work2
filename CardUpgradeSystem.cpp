#include "CardUpgradeSystem.h"
#include <iostream>

void CardUpgradeSystem::upgradeCard(Card* card) {
    std::cout << "Upgrading ";
    card->play();
    std::cout << " Card upgraded!\n";
}
