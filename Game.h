#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Player.h"
#include "Enemy.h"
#include "Deck.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include "StatusEffectCard.h"
#include "SpecialCard.h"

class Game {
public:
    Game();
    void start();
    void playTurn();
    void addCardToDeck(std::unique_ptr<Card> newCard);
    void showGameStatus() const;

private:
    Player player;
    Enemy enemy;
    Deck deck;
    void drawNewCardForPlayer();
    void playerTurn();
    void enemyTurn();
    void refillDeck();
    void playerClaimRewards(int cardIndex);
};

#endif
