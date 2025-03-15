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

    int playerLowHPThreshold = player.getHP() * 0.3;
    int bossLowHPThreshold = boss.getHP() * 0.3;

    if (player.getHP() < playerLowHPThreshold) {
        std::cout << "Player's health is low! Boss is preparing a powerful attack!\n";
        attack(boss, player);
    }
    else if (boss.getHP() < bossLowHPThreshold) {
        std::cout << "Boss's health is low! He is defending or healing!\n";
        (decision < 50) ? defend(boss) : useSpecialAbility(boss, player);
    }
    else if (player.getHP() > player.getHP() * 0.7) {
        std::cout << "Player is healthy! Boss uses special ability!\n";
        useSpecialAbility(boss, player);
    }
    else {
        (decision < 50) ? attack(boss, player) : castSpell(boss, player);
    }
}

void BossAI::attack(Boss& boss, Player& player) {
    int damage = 10 + rand() % 10;
    boss.attack(player, damage);
}

void BossAI::castSpell(Boss& boss, Player& player) {
    int spellDamage = 20 + rand() % 5;
    boss.castSpell(player, spellDamage);
}

void BossAI::useSpecialAbility(Boss& boss, Player& player) {
    if (rand() % 2 == 0) {
        std::cout << "Boss uses healing special ability!\n";
        boss.castSpell(player, -20);
    } else {
        std::cout << "Boss uses damage special ability!\n";
        boss.attack(player, 25);
    }
}

void BossAI::defend(Boss& boss) {
    std::cout << "Boss defends this turn, reducing damage taken!" << std::endl;
}


