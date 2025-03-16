#ifndef ATTACKCARD_H
#define ATTACKCARD_H

#include "Card.h"
#include "Player.h"
#include <iostream>

class Player;

class AttackCard : public Card {
public:
    AttackCard(int power);
    ~AttackCard() = default;
    void play() override;
    void claimReward(Player& player) override;
    int getAttackPower() const;

private:
    int attackPower;
};

#endif
