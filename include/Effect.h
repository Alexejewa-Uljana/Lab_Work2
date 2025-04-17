#ifndef EFFECT_H
#define EFFECT_H

#include <string>

/**
 * @struct Effect
 * @brief The Effect struct represents an effect with a type and a value.
 *
 * Effects can be applied to characters or game elements, such as healing or damage.
 */
struct Effect
{

    /**
     * @brief The type of effect (e.g., "heal", "damage").
     *
     * This string represents the effect type, which defines the nature of the effect.
     */
    std::string type;

    /**
     * @brief The value of the effect (e.g., amount of healing or damage).
     *
     * This integer represents the magnitude of the effect, such as how much damage or healing to apply.
     */
    int value;

    /**
     * @brief Constructs an Effect with a specified type and value.
     * @param t The type of the effect (default is "none").
     * @param v The value of the effect (default is 0).
     */
    Effect(const std::string& t = "none", int v = 0);

    /**
     * @brief Destroys the Effect instance.
     */
    ~Effect() = default;

    /**
     * @brief Applies the effect to a target.
     *
     * This method prints out the effect type and value.
     */
    void applyEffect();
};

#endif
