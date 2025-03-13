#ifndef STORY_MANAGER_H
#define STORY_MANAGER_H

#include <string>
#include <iostream>

class StoryManager {
public:
    StoryManager();
    void showStory();
    void nextChapter();

private:
    int currentChapter;
    void displayIntro();
    void displayRules();
};

#endif
