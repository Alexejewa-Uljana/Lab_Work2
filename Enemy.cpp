#include "Enemy.h"
#include "Player.h"
#include "EnemyDeck.h"
#include "AIController.h"
#include <iostream>

Enemy::Enemy() : hp(30), name("Goblin"), deck(nullptr) {}

Enemy::Enemy(const std::string& _name, int _hp) : name(_name), hp(_hp), deck(nullptr) {}

Enemy::~Enemy() {
    deck = nullptr;
}

void Enemy::takeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        hp = 0;
        std::cout << "Enemy is dead!" << std::endl;
    }
    std::cout << "Enemy takes " << damage << " damage! Health left: " << hp << std::endl;
}

void Enemy::attack(Player& player, int damage) {
    if (aiController) {
        aiController->attackPlayer(*this, player);
    } else {
        std::cout << "Enemy attacks player with power " << attackPower << "!" << std::endl;
        player.takeDamage(attackPower);
    }
}

void Enemy::useCard(Player& player) {
    if (aiController) {
        aiController->useCard(*this, player);
    } else {
        std::cout << "Enemy uses a card!" << std::endl;
    }
}

EnemyDeck* Enemy::getDeck() {
    return deck;
}

void Enemy::setAIController(AIController* aiController) {
    this->aiController = aiController;
}

std::string Enemy::getName() const {
    return name;
}

int Enemy::getHP() const {
    return hp;
}

void Enemy::setHP(int _hp) {
    hp = _hp;
}

void Enemy::increaseStunnedTurns() {
    if(stunnedTurns > 0) stunnedTurns--;
}

unsigned Enemy::getStunnedTurns() const {
    return stunnedTurns;
}

bool Enemy::isStunned() const {
    return stunnedTurns > 0;
}

void Enemy::setStunned(unsigned turns) {
    stunnedTurns = turns;
}

void Enemy::castSpell(Player& player, int spellDamage) {
    std::cout << name << " uses magic and deals " << spellDamage << " damage!\n";
    player.takeDamage(spellDamage);
}

void Enemy::defend(int defenseValue) {
    std::cout << name << " strengthens its defenses by " << defenseValue << "!\n";
    hp += defenseValue;
}

void Enemy::takeTurn(Player& player) {
    std::cout << name << "'s turn:\n";
    aiController->makeMove(*this, player);
}

void Enemy::drawCardFromDeck() {
    if (!deck) {
        std::cout << name << " has no deck assigned!\n";
        return;
    }
    auto card = deck->drawCard();
    if (card) {
        hand.push_back(std::move(card));
        std::cout << name << " drew a card.\n";
    } else {
        std::cout << name << "'s deck is empty!\n";
    }
}

void Enemy::setDeck(EnemyDeck* newDeck) {
    deck = newDeck;
}
