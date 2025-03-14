#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Deck.h"
#include "BattleSystem.h"
#include "TurnManager.h"
#include "StoryManager.h"
#include "World.h"

class Game {
private:
    Player player;
    std::unique_ptr<Enemy> enemy;
    Deck deck;
    BattleSystem battleSystem;
    std::unique_ptr<TurnManager> turnManager;
    StoryManager storyManager;
    World world;
    int difficulty;

public:
    Game(int difficulty);
    void start();
    void setDifficulty(int difficulty);
    void showGameStatus() const;
};

#endif // GAME_H
