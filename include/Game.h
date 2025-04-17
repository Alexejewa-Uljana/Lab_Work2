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
class Game {

public:

    /**
     * @brief Constructs a Game instance with a specific difficulty level.
     * 
     * Initializes the game based on the difficulty parameter. 
     * The difficulty level determines the starting health points for the players.
     * 
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
     * This method begins the game, interacts with the story, handles combat, and other game systems.
     */
    void start();

private:

    /**
     * @brief The player participating in the game.
     * 
     * This instance represents the first player in the game world.
     */
    Player player;

    /**
     * @brief The second player participating in the game (for PvP mode).
     * 
     * This instance represents the second player in the game world (in PvP mode).
     */
    Player player2;

    /**
     * @brief The story manager handling the narrative events of the game.
     * 
     * The StoryManager handles story progression, events, and chapters.
     */
    StoryManager storyManager;

    /**
     * @brief The battle system for handling combat between the player and enemies.
     * 
     * The BattleSystem is responsible for managing the combat mechanics, 
     * such as attack, defense, and health points.
     */
    BattleSystem* battleSystem;

    /**
     * @brief The enemy that the player will face in the game.
     * 
     * The enemy is created in AI mode and represents the opponent controlled by the game.
     */
    Enemy* enemy;

    /**
     * @brief The turn manager managing the order of actions during each game turn.
     * 
     * The TurnManager tracks the current turn, whose turn it is, and when actions can happen.
     */
    TurnManager* turnManager;

    /**
     * @brief The artifact that can provide bonuses or affect the game world.
     * 
     * The Artifact can grant special powers or items to the player.
     */
    Artifact artifact;
};

#endif

