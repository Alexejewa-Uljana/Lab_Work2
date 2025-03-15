#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "TurnManager.h"
#include "StoryManager.h"
#include "BattleSystem.h"
#include "Artifact.h"

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
    Artifact artifact;
};

#endif



