#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include "Player.h"
#include "Enemy.h"
#include "RewardSystem.h"

class TurnManager {
private:
    Player& player;
    Enemy& enemy;
    RewardSystem rewardSystem;

public:
    TurnManager(Player& p, Enemy& e);
    
    void startTurn();
    void drawNewCardForPlayer();
    void refillDeck();
};

#endif // TURNMANAGER_H
