#include "Player.h"
#include <iostream>
#include "Enemy.h"

Player::Player() : hp(50), mana(10), attackPower(5) {
    drawCards();
}

void Player::showHand() const {
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << i + 1 << ". ";
        hand[i]->play();
    }
}

void Player::playCard(int index, Enemy& enemy) {
    if (index >= 0 && index < hand.size()) {
        hand[index]->play();
        enemy.takeDamage(10);
        hand.erase(hand.begin() + index);
    } else {
        std::cout << "Invalid choice!\n";
    }
}

void Player::showDeck() const {
    std::cout << "Your deck:\n";
    deck.display();
}

void Player::heal(int amount) {
    hp += amount;
    if (hp > 50) hp = 50;
}

int Player::getHP() const {
    return hp;
}

int Player::getMana() const {
    return mana;
}

void Player::takeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        std::cout << "Player has been defeated!\n";
    }
}

void Player::drawCards() {
    for (int i = 0; i < 3; ++i) {
        Card* drawnCard = deck.drawCard();
        if (drawnCard) {
            hand.push_back(drawnCard);
        }
    }
}

int Player::getHandSize() const {
    return hand.size();
}

void Player::addCard(Card* newCard) {
    hand.push_back(newCard);
    std::cout << "Добавлена новая карта: " << newCard->getName() << "!\n";
}

void Player::increaseAttackPower(int amount) {
    attackPower += amount;
    std::cout << "Attack power increased by " << amount << "!\n";
}

void Player::restoreMana(int amount) {
    mana += amount;
    if (mana > 100) mana = 100;
    std::cout << "Mana restored by " << amount << "!\n";
}

void Player::restoreHealth(int amount) {
    hp += amount;
    if (hp > 100) hp = 100;
    std::cout << "Health restored by " << amount << "!\n";
}

void Player::addCardToDeck(Card* card) {
    deck.addCard(card);
    std::cout << "Card added to deck!\n";
}
