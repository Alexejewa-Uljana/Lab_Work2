#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "Enemy.h"
#include "Player.h"
#include "EnemyDeck.h"

class Enemy;

class AIController {
public:
    AIController();
    ~AIController() = default;
    void makeMove(Enemy& enemy, Player& player);
    void useCard(Enemy& enemy, Player& player);
    void attackPlayer(Enemy& enemy, Player& player);
    void defend(Enemy& enemy);

private:
    void simpleAI(Enemy& enemy, Player& player);
};

#endif



