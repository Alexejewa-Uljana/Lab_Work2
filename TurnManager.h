#ifndef TURN_MANAGER_H
#define TURN_MANAGER_H

#include "Player.h"
#include "Enemy.h"
#include "Deck.h"
#include "Card.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include "Effect.h"
#include "StatusEffectCard.h"
#include "SpecialCard.h"
#include "RewardSystem.h"

class TurnManager {
public:
    TurnManager(Player& player, Enemy& enemy);
    void startTurn();
private:
    Player& player;
    Enemy& enemy;
    bool playerTurn;
    void enemyTurn();
    void playerClaimRewards(int cardIndex);
    void drawNewCardForPlayer();
    void refillDeck();
    void enemyClaimRewards();
    RewardSystem rewardSystem;
};

#endif
