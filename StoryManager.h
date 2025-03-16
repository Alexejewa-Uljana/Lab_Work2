#ifndef STORY_MANAGER_H
#define STORY_MANAGER_H

#include <string>
#include <iostream>

class StoryManager {
public:
    StoryManager();
    ~StoryManager() = default;
    void showStory();
    void nextChapter();
    int currentChapter;
    void displayIntro();
    void displayRules();
};

#endif
