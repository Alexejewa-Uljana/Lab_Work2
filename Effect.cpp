#include "Effect.h"
#include <iostream>

/**
 * @brief Constructs an Effect with a specified type and value.
 * @param t The type of the effect (e.g., "heal", "damage").
 * @param v The value of the effect (e.g., healing amount or damage value).
 */
Effect::Effect(const std::string& t, int v) : type(t), value(v) {}

/**
 * @brief Applies the effect to the game state.
 * 
 * This method prints out the effect type and value.
 */
void Effect::applyEffect() {
    std::cout << "Applying effect: " << type << " with value " << value << "\n";
}

