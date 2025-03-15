#include "Boss.h"
#include "Player.h"
#include <iostream>

Boss::Boss() : Enemy("Boss", 100) {}

Boss::Boss(const std::string& _name, int _hp) : Enemy(_name, _hp) {}

void Boss::useSpecialAbility(Player& player) {
    std::cout << "Boss is using special ability on you!" << std::endl;
    attack(player, 50);
}

void Boss::takeTurn(Player& player) {
    if (isStunned()) {
        std::cout << "Boss is stunned and cannot take action this turn." << std::endl;
        setStunned(getStunnedTurns() - 1);
        return;
    }
    int actionChoice = rand() % 3;

    if (actionChoice == 0) {
        std::cout << "Boss attacks!" << std::endl;
        attack(player, 20);
    } else if (actionChoice == 1) {
        std::cout << "Boss casts a spell!" << std::endl;
        castSpell(player, 30);
    } else {
        std::cout << "Boss uses special ability!" << std::endl;
        useSpecialAbility(player);
    }
}

void Boss::attack(Player& player, int damage) {
    std::cout << "Boss attacks you" << " for " << damage << " damage!" << std::endl;
    player.takeDamage(damage);
}

void Boss::castSpell(Player& player, int spellDamage) {
    std::cout << "Boss casts a spell on you dealing " << spellDamage << " damage!" << std::endl;
    player.takeDamage(spellDamage);
}
