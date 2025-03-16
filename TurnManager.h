#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "BattleSystem.h"
#include "AIController.h"
#include "BossAI.h"
#include "RewardSystem.h"

class TurnManager {

private:
    Player& player;
    Enemy& enemy;
    BattleSystem& battleSystem;
    AIController aiController;
    BossAI* bossAI;
    bool isBossFight;
    RewardSystem rewardSystem;
    int turnCounter;
public:
    TurnManager(Player& player, Enemy& enemy, BattleSystem& battleSystem);
    TurnManager(Player& player, Boss& boss, BattleSystem& battleSystem);

    void startBattle();
    void playerTurn();
    void enemyTurn();
    void refillDeck();
    void drawNewCardForPlayer();
};

#endif // TURNMANAGER_H


