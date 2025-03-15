#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "TurnManager.h"
#include "StoryManager.h"
#include "BattleSystem.h"

class Game {
public:
    Game(int difficulty);
    void start();

private:
    Player player;
    StoryManager storyManager;
    BattleSystem battleSystem;
    Enemy* enemy;
    TurnManager* turnManager;
};

#endif



