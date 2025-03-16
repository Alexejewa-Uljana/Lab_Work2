#include "Player.h"
#include <iostream>
#include "ManaSystem.h"
#include "StatusEffectCard.h"
#include "SpecialCard.h"
#include "Deck.h"
#include "Enemy.h"

/**
 * @brief Default constructor for the Player class.
 * 
 * Initializes the player with default values for health, mana, attack power, and an empty deck.
 */
Player::Player() : hp(50), mana(10), attackPower(5) {
    deck = std::make_unique<Deck>();
    drawCards();
}

/**
 * @brief Destructor for the Player class.
 */
Player::~Player() {}

/**
 * @brief Sets the player's deck.
 * @param newDeck A unique pointer to the new deck to be assigned to the player.
 * 
 * This method replaces the current deck with a new one.
 */
void Player::setDeck(std::unique_ptr<Deck> newDeck) {
    deck = std::move(newDeck);
}

/**
 * @brief Sets the player's health.
 * @param _hp The new health value for the player.
 */
void Player::setHP(int _hp) {
    hp = _hp;
}

/**
 * @brief Gets the player's deck.
 * @return A pointer to the player's deck.
 */
Deck* Player::getDeck() const {
    return deck.get();
}

/**
 * @brief Gets the player's attack power.
 * @return The player's attack power.
 */
const int Player::getAttackPower() const {
    return attackPower;
}

/**
 * @brief Sets the number of turns the player is stunned.
 * @param turns The number of turns the player will be stunned.
 */
void Player::setStunned(int turns) {
    stunnedTurns = turns;
}

/**
 * @brief Gets the number of turns the player is stunned.
 * @return The number of turns the player is stunned.
 */
const int Player::getStunned() const {
    return stunnedTurns;
}

/**
 * @brief Displays the player's hand of cards.
 * 
 * This method prints the player's hand to the console.
 */
void Player::showHand() const {
    std::cout << "Your current hand:\n";
    for(size_t i = 0; i < hand.size(); ++i) {
        if(hand[i]) {
            std::cout << i << ". " << hand[i]->getName() << ". ";
            if (hand[i]->getPower() != 0) {
                std::cout << "Power: " << hand[i]->getPower() << std::endl;
            } else {
                std::cout << std::endl;
            }
        } else {
            std::cout << i << ". (empty)\n";
        }
    }
}

/**
 * @brief Plays a card from the player's hand.
 * @param index The index of the card in the player's hand.
 * @param enemy The enemy the player is interacting with.
 * 
 * This method plays a card from the player's hand and applies its effect to the enemy or the player.
 */
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
    enemy.takeDamage(selectedCard->getPower());
    drawCards();
}

/**
 * @brief Displays the player's deck.
 * 
 * This method prints the contents of the player's deck to the console.
 */
void Player::showDeck() const {
    if (deck) {
        deck->display();
    } else {
        std::cout << "Player has no deck.\n";
    }
}

/**
 * @brief Heals the player by a specified amount.
 * @param amount The amount of health to restore to the player.
 * 
 * This method increases the player's health, ensuring it does not exceed the maximum value.
 */
void Player::heal(int amount) {
    hp += amount;
    if (hp > 50) hp = 50;
}

/**
 * @brief Gets the player's current health.
 * @return The player's current health.
 */
int Player::getHP() const {
    return hp;
}

/**
 * @brief Gets the player's current mana.
 * @return The player's current mana.
 */
int Player::getMana() const {
    return mana;
}

/**
 * @brief Gets the player's hand of cards.
 * @return A reference to the player's hand of cards.
 */
const std::vector<std::unique_ptr<Card>>& Player::getHand() const {
    return hand;
}

/**
 * @brief The player takes damage.
 * @param damage The amount of damage to be inflicted on the player.
 * 
 * This method reduces the player's health by the given amount of damage.
 */
void Player::takeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        std::cout << "Player has been defeated!" << std::endl;
    }
}

/**
 * @brief Draws cards from the player's deck.
 * 
 * This method draws cards from the deck until the player has 3 cards in their hand.
 */
void Player::drawCards() {
    int cardsToDraw = 3 - hand.size();
    for (int i = 0; i < cardsToDraw; ++i) {
        if (deck and !deck->isEmpty()) {
            auto drawnCard = deck->drawCard();
            if (drawnCard) {
                hand.push_back(std::move(drawnCard));
            } else {
                std::cout << "No more cards in the deck!\n";
                break;
            }
        }
    }
}

/**
 * @brief Gets the size of the player's hand.
 * @return The number of cards in the player's hand.
 */
int Player::getHandSize() const {
    return static_cast<int>(hand.size());
}

/**
 * @brief Adds a new card to the player's hand.
 * @param newCard A unique pointer to the card to be added.
 */
void Player::addCard(std::unique_ptr<Card> newCard) {
    std::cout << "New card added: " << newCard->getName() << std::endl;
    hand.push_back(std::move(newCard));
}

/**
 * @brief Increases the player's attack power.
 * @param amount The amount to increase the player's attack power by.
 */
void Player::increaseAttackPower(int amount) {
    attackPower += amount;
}

/**
 * @brief Restores the player's mana.
 * @param amount The amount of mana to restore.
 */
void Player::restoreMana(int amount) {
    mana += amount;
    if (mana > 100) mana = 100;
}

/**
 * @brief Restores the player's health.
 * @param amount The amount of health to restore.
 */
void Player::restoreHealth(int amount) {
    hp += amount;
    if (hp > 100) hp = 100;
}

/**
 * @brief Adds a card to the player's deck.
 * @param card A unique pointer to the card to be added.
 * 
 * This method adds a new card to the player's deck.
 */
void Player::addCardToDeck(std::unique_ptr<Card> card) {
    if (deck) {
        deck->addCard(std::move(card));
    } else {
        std::cout << "Player has no deck to add cards.\n";
    }
}

/**
 * @brief Reduces the player's mana.
 * @param amount The amount of mana to reduce.
 */
void Player::reduceMana(int amount) {
    mana -= amount;
    if (mana < 0) mana = 0;
}

/**
 * @brief Removes a card from the player's hand.
 * @param index The index of the card to remove.
 */
void Player::removeCard(int index) {
    if (index >= 0 and index < hand.size()) {
        hand.erase(hand.begin() + index);
    }
}

