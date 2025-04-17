// Алексеева Ульяна st129990@student.spbu.ru
#include "../include/World.h"
#include <iostream>

/**
 * @brief Constructor for creating the world.
 * Sets the initial level.
 */
World::World() : level(1) {}

/**
 * @brief Loads the world and prints the current level.
 */
void World::load()
{
    std::cout << "Loading world...\n";
    std::cout << "Current level: " << level << ".\n";
}

/**
 * @brief Returns the current level of the world.
 * @return The current world level.
 */
int World::getLevel() const
{
    return level;
}

