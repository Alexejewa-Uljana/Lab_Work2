#ifndef TURN_MANAGER_H
#define TURN_MANAGER_H

#include "Player.h"
#include "Enemy.h"

class TurnManager {
public:
    TurnManager(Player& player, Enemy& enemy);
    void startTurn();
    
private:
    Player& player;
    Enemy& enemy;
    bool playerTurn;
};

#endif
