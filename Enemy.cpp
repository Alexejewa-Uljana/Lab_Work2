#include "Enemy.h"
#include "Player.h"
#include "AIController.h"
#include <iostream>

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

void Enemy::attack(Player& player, int damage) {
    std::cout << name << " attacks the player with " << damage << " damage!/n";
    player.takeDamage(damage);
}

void Enemy::castSpell(Player& player, int spellDamage) {
    std::cout << name << " использует магию и наносит " << spellDamage << " урона!\n";
    player.takeDamage(spellDamage);
}

void Enemy::defend(int defenseValue) {
    std::cout << name << " усиливает свою защиту на " << defenseValue << "!\n";
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


