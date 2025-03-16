#include "Card.h"

/**
 * @brief Constructs a Card with a specified name and power.
 * @param _name The name of the card.
 * @param _power The power associated with the card.
 */
Card::Card(const std::string& _name, int _power): name(_name), power(_power) {}

/**
 * @brief Destroys the Card instance.
 */
Card::~Card() {}

/**
 * @brief Gets the name of the card.
 * @return The name of the card.
 */
std::string Card::getName() const {
    return name;
}

/**
 * @brief Gets the power of the card.
 * @return The power of the card.
 */
int Card::getPower() const {
    return power;
}

