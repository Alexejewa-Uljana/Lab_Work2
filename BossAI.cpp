#include "BossAI.h"
#include "Player.h"
#include <iostream>

BossAI::BossAI(Boss& _boss): boss(_boss) {}

BossAI::~BossAI() {}

void BossAI::takeTurn(Boss& boss, Player& player) {
    if (boss.isStunned()) {
        std::cout << "Boss is stunned and cannot take action this turn." << std::endl;
        boss.setStunned(boss.getStunnedTurns() - 1);
        return;
    }
    makeDecision(boss, player);
}

void BossAI::makeDecision(Boss& boss, Player& player) {
    int decision = rand() % 100;
    if (player.getHP() < player.getHP() * 0.3) {
        std::cout << "Player's health is low! Boss is preparing a powerful attack!\n";
        attack(boss, player);
    }
    else if (boss.getHP() < boss.getHP() * 0.3) {
        std::cout << "Boss' health is low! Boss is attempting to defend or heal!\n";
        if (decision < 50) {
            defend(boss);
        } else {
            useSpecialAbility(boss, player);
        }
    }
    else if (player.getHP() > player.getHP() * 0.7) {
        std::cout << "Player's health is high! Boss uses special ability!" << std::endl;
        useSpecialAbility(boss, player);
    }
    else {
        if (decision < 50) {
            std::cout << "Boss decides to attack!" << std::endl;
            attack(boss, player);
        } else {
            std::cout << "Boss decides to cast a spell!" << std::endl;
            castSpell(boss, player);
        }
    }
}

void BossAI::attack(Boss& boss, Player& player) {
    int damage = 20 + rand() % 20;
    boss.attack(player, damage);
}

void BossAI::castSpell(Boss& boss, Player& player) {
    int spellDamage = 30 + rand() % 20;
    boss.castSpell(player, spellDamage);
}

void BossAI::useSpecialAbility(Boss& boss, Player& player) {
    if (rand() % 2 == 0) {
        std::cout << "Boss uses healing special ability!\n";
        boss.castSpell(player, -20);
    } else {
        std::cout << "Boss uses damage special ability!\n";
        boss.attack(player, 50);
    }
}

void BossAI::defend(Boss& boss) {
    std::cout << "Boss defends this turn, reducing damage taken!" << std::endl;
}


