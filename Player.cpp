#include "Player.h"
#include <iostream>
#include "ManaSystem.h"
#include "StatusEffectCard.h"
#include "SpecialCard.h"
#include "Deck.h"
#include "Enemy.h"

Player::Player() : hp(50), mana(10), attackPower(5) {
    deck = std::make_unique<Deck>();
    drawCards();
}

Player::~Player() = default;

void Player::setDeck(std::unique_ptr<Deck> newDeck) {
    deck = std::move(newDeck);
}

void Player::setHP(int _hp) {
    hp = _hp;
}

Deck* Player::getDeck() const {
    return deck.get();
}

void Player::showHand() const {
    std::cout << "Yor current hand:\n";
    for(size_t i = 0; i < hand.size(); ++i) {
        if(hand[i]) std::cout << i << ". " << hand[i]->getName() << std::endl;
        else std::cout << i << ". (empty)\n";
    }
}

void Player::playCard(int index, Enemy& enemy) {
    if (index < 0 || index >= static_cast<int>(hand.size())) {
        std::cout << "Invalid choice!" << std::endl;
        return;
    }
    std::unique_ptr<Card> selectedCard = std::move(hand[index]);
    if (MagicCard* magicCard = dynamic_cast<MagicCard*>(selectedCard.get())) {
        if (!ManaSystem::canCastMagicCard(*this, magicCard)) {
            std::cout << "Not enough mana!\n";
            return;
        } else {
            ManaSystem::castMagicCard(*this, magicCard);
        }
    }
    if (StatusEffectCard* statusCard = dynamic_cast<StatusEffectCard*>(selectedCard.get())) {
        std::cout << "Applying status effect: " << statusCard->getName() << "\n";
        if (statusCard->getEffect().type == "stun") {
            enemy.setStunned(statusCard->getEffect().value);
        }
    }
    if (SpecialCard* specialCard = dynamic_cast<SpecialCard*>(selectedCard.get())) {
        std::cout << "Activating special effect: " << specialCard->getName() << "\n";
        if (specialCard->getEffect().type == "heal") {
            heal(specialCard->getEffect().value);
        } else if (specialCard->getEffect().type == "mana") {
            restoreMana(specialCard->getEffect().value);
        }
    }
    selectedCard->play();
    enemy.takeDamage(10);
    removeCard(index);
}

void Player::setStunned(int turns) {
    stunnedTurns = turns;
}

void Player::showDeck() const {
    if (deck) {
        deck->display();
    } else {
        std::cout << "Player has no deck.\n";
    }
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
    int cardsToDraw = 3 - hand.size();
    for (int i = 0; i < cardsToDraw; ++i) {
        if (deck and !deck->isEmpty()) {
            auto drawnCard = deck->drawCard();
            if (drawnCard) {
                hand.push_back(std::move(drawnCard));
            }
            else {
                std::cout << "No more cards in the deck!\n";
                break;
            }
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
    if (deck) {
        deck->addCard(std::move(card));
    } else {
        std::cout << "Player has no deck to add cards.\n";
    }
}

void Player::reduceMana(int amount) {
    mana -= amount;
    if (mana < 0) mana = 0;
}

void Player::removeCard(int index) {
    if (index >= 0 and index < hand.size()){
        hand.erase(hand.begin() + index);
    }
}
