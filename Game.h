#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "BattleSystem.h"
#include "TurnManager.h"
#include "StoryManager.h"
#include "World.h"

class Game {
private:
    Player player;
    BattleSystem battleSystem;
    TurnManager turnManager;
    StoryManager storyManager;
    World world;

public:
    Game(int difficulty);
    
    void start();
    void showStoryAndWorldInfo();
    void showGameStatus() const;
    void drawNewCardForPlayer();
    void refillDeck();
};

#endif // GAME_H


