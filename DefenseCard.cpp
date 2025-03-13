#include "DefenseCard.h"
#include "Player.h"
#include <iostream>


DefenseCard::DefenseCard(int power): Card("Defense Card", power) {}

void DefenseCard::play() {
    std::cout << "Played a Defense Card! You gain a shield!\n";
}

void DefenseCard::claimReward(Player& player) {
    std::cout << "You received a bonus to defense power!\n";
    player.restoreHealth(10);
}

int DefenseCard::getDefensePower() const {
    return defenseValue;
}
