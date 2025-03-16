#ifndef WORLD_H
#define WORLD_H

#include <iostream>

/**
 * @class World
 * @brief Manages the world in the game.
 * 
 * World manages the current level and world loading.
 */
class World {

public:
    /**
     * @brief Constructor for the world.
     * Initializes the world level.
     */
    World();

    /**
     * @brief Default destructor.
     */
    ~World() = default;

    /**
     * @brief Loads the world.
     */
    void load();

    /**
     * @brief Returns the world level.
     * @return The current level of the world.
     */
    int getLevel() const;

private:
    int level; /**< Current world level. */
};

#endif

