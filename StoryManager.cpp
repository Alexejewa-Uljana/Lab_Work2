#include "StoryManager.h"
#include <iostream>

StoryManager::StoryManager() : currentChapter(0) {}

void StoryManager::showStory() {
    if (currentChapter == 0) {
        displayIntro();
        displayRules();
        currentChapter++;
    }
}

void StoryManager::nextChapter() {
    std::cout << "Next chapter of the story...\n";
    currentChapter++;
}

void StoryManager::displayIntro() {
    std::cout << "Welcome to the Game!\n";
    std::cout << "In this game, you will face challenges and fight enemies!\n";
}

void StoryManager::displayRules() {
    std::cout << "Game Rules:\n";
    std::cout << "1. Each player has HP, Mana, and a deck of cards.\n";
    std::cout << "2. You can play cards to attack, defend, or cast spells.\n";
    std::cout << "3. The goal is to reduce the enemy's HP to 0.\n";
}
