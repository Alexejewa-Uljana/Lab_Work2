#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include "Player.h"
#include "Enemy.h"
#include "BattleSystem.h"
#include "RewardSystem.h"
#include "AIController.h"

class TurnManager {
private:
    Player& player;
    Enemy& enemy;
    BattleSystem& battleSystem;
    RewardSystem rewardSystem;
    AIController aiController; // AI для врага

public:
    TurnManager(Player& player, Enemy& enemy, BattleSystem& battleSystem);

    void startTurn();
    void enemyTurn();  // Ход врага через AIController
    void drawNewCardForPlayer();
    void refillDeck();
    void startBattle(); // Начало битвы (игровой цикл)
};

#endif // TURNMANAGER_H
