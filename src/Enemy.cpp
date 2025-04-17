#include "../include/Enemy.h"
#include "../include/Player.h"
#include "../include/EnemyDeck.h"
#include "../include/AIController.h"
#include <iostream>

/**
 * @brief Default constructor that initializes an enemy with a name and default health.
 */
Enemy::Enemy() : hp(30), name("Goblin"), deck(nullptr) {}

/**
 * @brief Constructs an Enemy with a specified name and health.
 * @param _name The name of the enemy.
 * @param _hp The health of the enemy.
 */
Enemy::Enemy(const std::string& _name, int _hp) : name(_name), hp(_hp), deck(nullptr) {}

/**
 * @brief Destroys the Enemy instance and frees associated resources.
 */
Enemy::~Enemy() {
    deck = nullptr;
    delete deck;
}

/**
 * @brief Applies damage to the enemy.
 * @param damage The amount of damage the enemy takes.
 * 
 * This method decreases the enemy's health and prints the result.
 */
void Enemy::takeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        hp = 0;
        std::cout << "Enemy is dead!" << std::endl;
    }
    std::cout << "Enemy takes " << damage << " damage! Health left: " << hp << std::endl;
}

/**
 * @brief The enemy attacks the player.
 * @param player The player being attacked.
 * @param damage The amount of damage dealt by the enemy.
 * 
 * This method makes the enemy attack the player with a specified damage value.
 */
void Enemy::attack(Player& player, int damage) {
    if (aiController) {
        aiController->attackPlayer(*this, player);
    } else {
        std::cout << "Enemy attacks player with power " << attackPower << "!" << std::endl;
        player.takeDamage(attackPower);
    }
}

/**
 * @brief The enemy uses a card from their deck.
 * @param player The player being affected by the card.
 * 
 * This method triggers the enemy to use a card from their deck.
 */
void Enemy::useCard(Player& player) {
    if (aiController) {
        aiController->useCard(*this, player);
    } else {
        std::cout << "Enemy uses a card!" << std::endl;
    }
}

/**
 * @brief Sets the AI controller for the enemy.
 * @param aiController The AI controller that manages the enemy's actions.
 * 
 * This method sets the AI controller that handles the enemy's decision-making.
 */
void Enemy::setAIController(AIController* aiController) {
    this->aiController = aiController;
}

/**
 * @brief Gets the name of the enemy.
 * @return The name of the enemy.
 */
std::string Enemy::getName() const {
    return name;
}

/**
 * @brief Gets the current health of the enemy.
 * @return The current health of the enemy.
 */
int Enemy::getHP() const {
    return hp;
}

/**
 * @brief Sets the health of the enemy.
 * @param health The new health value for the enemy.
 */
void Enemy::setHP(int health) {
    hp = health;
}

/**
 * @brief Increases the number of turns the enemy is stunned.
 * 
 * If the enemy is already stunned, this method reduces the stunned turns.
 */
void Enemy::increaseStunnedTurns() {
    if (stunnedTurns > 0) stunnedTurns--;
}

/**
 * @brief Gets the number of turns the enemy is stunned.
 * @return The number of turns the enemy is stunned.
 */
unsigned Enemy::getStunnedTurns() const {
    return stunnedTurns;
}

/**
 * @brief Checks if the enemy is stunned.
 * @return True if the enemy is stunned, false otherwise.
 */
bool Enemy::isStunned() const {
    return stunnedTurns > 0;
}

/**
 * @brief Sets the number of stunned turns for the enemy.
 * @param turns The number of turns the enemy will be stunned.
 */
void Enemy::setStunned(unsigned turns) {
    stunnedTurns = turns;
}

/**
 * @brief The enemy casts a spell on the player.
 * @param player The player who will be affected by the spell.
 * @param spellDamage The amount of damage dealt by the spell.
 * 
 * This method makes the enemy cast a magic spell on the player.
 */
void Enemy::castSpell(Player& player, int spellDamage) {
    std::cout << name << " uses magic and deals " << spellDamage << " damage!\n";
    player.takeDamage(spellDamage);
}

/**
 * @brief The enemy defends, strengthening its defenses.
 * @param defenseValue The amount of defense added to the enemy.
 * 
 * This method increases the enemy's health based on the defense value.
 */
void Enemy::defend(int defenseValue) {
    std::cout << name << " strengthens its defenses by " << defenseValue << "!\n";
    hp += defenseValue;
}

/**
 * @brief The enemy takes its turn and performs an action.
 * @param player The player who is the target of the enemy's action.
 * 
 * This method handles the enemy's turn by calling the AI controller to make a move.
 */
void Enemy::takeTurn(Player& player) {
    std::cout << name << "'s turn:\n";
    aiController->makeMove(*this, player);
}

/**
 * @brief The enemy draws a card from their deck.
 * 
 * This method allows the enemy to draw a card from their deck if available.
 */
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

/**
 * @brief Sets the deck for the enemy.
 * @param newDeck The new deck to assign to the enemy.
 * 
 * This method assigns a new deck of cards to the enemy.
 */
void Enemy::setDeck(EnemyDeck* newDeck) {
    deck = newDeck;
}

/**
 * @brief Gets the enemy's deck.
 * @return A pointer to the enemy's deck.
 */
EnemyDeck* Enemy::getDeck() {
    return deck;
}
