#include "gtest/gtest.h"
#include "StoryManager.h"
#include <sstream>

TEST(StoryManager, displayIntro)
{
    StoryManager storyManager;

    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf());  // Redirecting output
    storyManager.displayIntro();
    EXPECT_EQ("Welcome to the Game!\nIn this game, you will face challenges and fight enemies!\n", output.str());
    std::cout.rdbuf(originalCout);  // Restore original output
}

TEST(StoryManager, displayRules)
{
    StoryManager storyManager;

    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf());
    storyManager.displayRules();
    EXPECT_EQ("Game Rules:\n1. Each player has HP, Mana, and a deck of cards.\n2. You can play cards to attack, defend, or cast spells.\n3. The goal is to reduce the enemy's HP to 0.\n", output.str());
    std::cout.rdbuf(originalCout);
}

TEST(StoryManager, nextChapter)
{
    StoryManager storyManager;
    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf());
    storyManager.nextChapter();
    EXPECT_EQ("Next chapter of the story...\n", output.str());
    std::cout.rdbuf(originalCout);
}

TEST(StoryManager, showStory)
{
    StoryManager storyManager;
    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf());
    storyManager.showStory();
    EXPECT_TRUE(output.str().find("Welcome to the Game!") != std::string::npos);
    std::cout.rdbuf(originalCout);
}
