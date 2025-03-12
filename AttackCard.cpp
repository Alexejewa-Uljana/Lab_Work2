#include "AttackCard.h"
#include "Player.h"
#include <iostream>


AttackCard::AttackCard(int power): Card("Attack Card", power) {}

void AttackCard::play() {
    std::cout << "Played an Attack Card!\n";
}

void AttackCard::claimReward(Player& player) {
    std::cout << "You received a bonus to attack power!\n";
    player.increaseAttackPower(5);
}
