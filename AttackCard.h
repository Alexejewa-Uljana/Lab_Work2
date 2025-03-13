#ifndef ATTACKCARD_H
#define ATTACKCARD_H

#include "Card.h"
#include "Player.h"
#include <iostream>

class Player;

class AttackCard : public Card {
public:
    AttackCard(int power); // name always use "Attack card"
    void play() override;
    void claimReward(Player& player) override;

private:
    int attackPower;
};

#endif
