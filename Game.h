#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "BattleSystem.h"
#include "TurnManager.h"
#include <memory>

class Game {
private:
    Player player;
    std::unique_ptr<Enemy> enemy;
    std::unique_ptr<Boss> boss;
    BattleSystem battleSystem;
    std::unique_ptr<TurnManager> turnManager;

public:
    Game(int difficulty);
    void start();
    void showGameStatus() const;
};

#endif // GAME_H


