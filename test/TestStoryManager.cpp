// Алексеева Ульяна st129990@student.spbu.ru

/**
 * @file TestStoryManager.cpp
 * @brief Unit tests for the StoryManager class.
 */

#include "gtest/gtest.h"
#include "../include/StoryManager.h"
#include <sstream>

/**
 * @brief Tests displaying the introduction of the story.
 */
TEST(StoryManager, displayIntro)
{
    StoryManager storyManager;
    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf()); // Redirect output
    storyManager.displayIntro();
    EXPECT_EQ("Welcome to the Game!\nIn this game, you will face challenges and fight enemies!\n", output.str());
    std::cout.rdbuf(originalCout); // Restore output
}

/**
 * @brief Tests displaying the game rules.
 */
TEST(StoryManager, displayRules)
{
    StoryManager storyManager;
    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf());
    storyManager.displayRules();
    EXPECT_EQ("Game Rules:\n1. Each player has HP, Mana, and a deck of cards.\n2. You can play cards to attack, defend, or cast spells.\n3. The goal is to reduce the enemy's HP to 0.\n", output.str());
    std::cout.rdbuf(originalCout);
}


