#include "Enemy.h"
#include "Player.h"
#include "AIController.h"
#include <iostream>

Enemy::Enemy() : hp(30), name("Goblin") {}
Enemy::Enemy(const std::string& _name, int _hp) : name(_name), hp(_hp), aiController() {}

std::string Enemy::getName() const {
    return name;
}

int Enemy::getHP() const {
    return hp;
}

void Enemy::setHP(int _hp) {
    hp = _hp;
}

int Enemy::getStunnedTurns() const {
    return stunnedTurns;
}

bool Enemy::isStunned() {
    return stunnedTurns > 0;
}

void Enemy::attack(Player& player, int damage) {
    if (stunnedTurns > 0) {
        std::cout << name << "is stunned and cannot attack!\n";
        stunnedTurns--;
        return;
    }
    std::cout << name << " attacks the player with " << damage << " damage!\n";
    player.takeDamage(damage);
}

void Enemy::setStunned(int turns) {
    stunnedTurns = turns;
}

void Enemy::castSpell(Player& player, int spellDamage) {
    std::cout << name << " uses magic and deals damage " << spellDamage << " damage!\n";
    player.takeDamage(spellDamage);
}

void Enemy::defend(int defenseValue) {
    std::cout << name << " strengthens its defenses on  " << defenseValue << "!\n";
    hp += defenseValue;
}

void Enemy::takeTurn(Player& player) {
    std::cout << name << "'s turn:\n";
    aiController.makeMove(*this, player);
}

void Enemy::takeDamage(int damage) {
    hp -= damage;
    std::cout << name << " takes " << damage << " damage!\n";
    if (hp <= 0) {
        std::cout << name << " has been defeated!\n";
    }
}
