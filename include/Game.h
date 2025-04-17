#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "TurnManager.h"
#include "StoryManager.h"
#include "BattleSystem.h"
#include "Artifact.h"

/**
 * @class Game
 * @brief The Game class represents the core game logic, including the player, story, combat, and game progression.
 *
 * This class manages the game's state, running the story and combat system, and handling the progression of the game.
 */
class Game
{

public:

    /**
     * @brief Constructs a Game instance with a specific difficulty level.
     * @param difficulty The difficulty level of the game.
     */
    Game(int difficulty);

    /**
     * @brief Destructor for the Game.
     *
     * Cleans up resources when the game ends.
     */
    ~Game();

    /**
     * @brief Starts the game, initializing the game state and running the main game loop.
     *
     * This method begins the game and allows the player to interact with the story, combat, and other game systems.
     */
    void start();

private:

    /**
     * @brief The player participating in the game.
     *
     * This instance represents the player in the game world.
     */
    Player player;

    /**
     * @brief The story manager handling the narrative events of the game.
     *
     * The StoryManager handles story progression and events.
     */
    StoryManager storyManager;

    /**
     * @brief The battle system for handling combat between the player and enemies.
     *
     * The BattleSystem is responsible for managing the combat logic of the game.
     */
    BattleSystem battleSystem;

    /**
     * @brief The enemy that the player will face.
     *
     * The enemy represents an opponent controlled by the game or AI.
     */
    Enemy* enemy;

    /**
     * @brief The turn manager managing the order of actions during each game turn.
     *
     * The TurnManager tracks and controls whose turn it is and when actions can happen.
     */
    TurnManager* turnManager;

    /**
     * @brief The artifact that can provide bonuses or affect the game world.
     *
     * This artifact can be a special item that influences the player's progress.
     */
    Artifact artifact;
};

#endif

