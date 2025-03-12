#ifndef STORY_MANAGER_H
#define STORY_MANAGER_H

#include <string>

class StoryManager {
public:
    StoryManager();
    void showStory();
    void nextChapter();

private:
    int currentChapter;
};

#endif

