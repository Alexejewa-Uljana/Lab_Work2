#ifndef DEFENSECARD_H
#define DEFENSECARD_H

#include "Card.h"
#include <iostream>
#include "Player.h"

class Player;

class DefenseCard : public Card {
public:
    DefenseCard(int power);
    void play() override;
    void claimReward(Player& player) override;

private:
    int defenseValue;
};

#endif
