#include "Player.h"
#include <iostream>
#include "Enemy.h"

Player::Player() : hp(50), mana(10), attackPower(5) {
    drawCards();
}

void Player::showHand() const {
    if (hand.empty()) {
        std::cout << "Your hand is empty!" << std::endl;
        return;
    }
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << i << ". ";
        hand[i]->play();
    }
}

void Player::playCard(int index, Enemy& enemy) {
    if (index < 0 || index >= static_cast<int>(hand.size())) {
        std::cout << "Invalid choice!" << std::endl;
        return;
    }

    hand[index]->play();
    enemy.takeDamage(10);
    hand.erase(hand.begin() + index);
}

void Player::showDeck() const {
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

const std::vector<std::unique_ptr<Card>>& Player::getHand() const {
    return hand;
}

void Player::takeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        std::cout << "Player has been defeated!" << std::endl;
    }
}

void Player::drawCards() {
    for (int i = 0; i < 3; ++i) {
        auto drawnCard = deck.drawCard();
        if (drawnCard) {
            hand.push_back(std::move(drawnCard));
        }
    }
}

int Player::getHandSize() const {
    return static_cast<int>(hand.size());
}

void Player::addCard(std::unique_ptr<Card> newCard) {
    std::cout << "New card added: " << newCard->getName() << std::endl;
    hand.push_back(std::move(newCard));
}

void Player::increaseAttackPower(int amount) {
    attackPower += amount;
}

void Player::restoreMana(int amount) {
    mana += amount;
    if (mana > 100) mana = 100;
}

void Player::restoreHealth(int amount) {
    hp += amount;
    if (hp > 100) hp = 100;
}

void Player::addCardToDeck(std::unique_ptr<Card> card) {
    deck.addCard(std::move(card));
}
