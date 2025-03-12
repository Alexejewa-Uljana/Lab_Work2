#include "MagicCard.h"
#include "Player.h"
#include <iostream>

MagicCard::MagicCard(int power): Card("Magic Card", power) {}

MagicCard::MagicCard(): Card("Magic Card", 5) {}
void MagicCard::play() {
    std::cout << "Played a Magic Card! You cast a powerful spell.\n";
}

void MagicCard::claimReward(Player& player) {
    std::cout << "You received a bonus to mana!\n";
    player.restoreMana(10);
}
