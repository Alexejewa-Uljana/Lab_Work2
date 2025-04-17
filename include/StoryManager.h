#ifndef STORY_MANAGER_H
#define STORY_MANAGER_H

#include <string>
#include <iostream>

/**
 * @class StoryManager
 * @brief Manages the story flow in the game.
 *
 * This class handles displaying various chapters and the game rules.
 */
class StoryManager
{

public:
    /**
     * @brief Default constructor for StoryManager.
     * Initializes the current chapter of the game.
     */
    StoryManager();

    /**
     * @brief Default destructor.
     */
    ~StoryManager() = default;

    /**
     * @brief Displays the story and game rules.
     * Displays the intro and rules if the current chapter is 0.
     */
    void showStory();

    /**
     * @brief Proceeds to the next chapter.
     * Increments the current chapter number.
     */
    void nextChapter();

    /**
     * @brief Displays the game introduction.
     * Shows introductory information about the game.
     */
    void displayIntro();

    /**
     * @brief Displays the game rules.
     * Shows the basic rules of the game.
     */
    void displayRules();

    int currentChapter; /**< The current chapter number. */
};

#endif
