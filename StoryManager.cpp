#include "StoryManager.h"
#include <iostream>

StoryManager::StoryManager() : currentChapter(1) {}

void StoryManager::showStory() {
    std::cout << "Chapter " << currentChapter << ": A new adventure begins...\n";
}

void StoryManager::nextChapter() {
    currentChapter++;
    showStory();
}
