#ifndef MAGICCARD_H
#define MAGICCARD_H

#include "Card.h"
#include <iostream>
#include "Player.h"

class Player;

class MagicCard : public Card {
public:
    MagicCard(int power);
    MagicCard();
    void play() override;
    void claimReward(Player& player) override;
};

#endif
