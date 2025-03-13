#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Deck.h"
#include "BattleSystem.h"
#include "TurnManager.h"
#include "StoryManager.h"
#include "World.h"
#include "Card.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include "Effect.h"
#include "SpecialCard.h"
#include "StatusEffectCard.h"

class Game {
public:
    Game();
    void start();
private:
    Player player;
    Enemy enemy;
    Deck deck;
    BattleSystem battleSystem;
    TurnManager turnManager;
    StoryManager storyManager;
    World world;
    void showGameStatus() const;
    void drawNewCardForPlayer();
    void refillDeck();
    void showStoryAndWorldInfo();
};

#endif
