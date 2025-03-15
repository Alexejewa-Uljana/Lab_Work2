#ifndef MAGICCARD_H
#define MAGICCARD_H

#include "Card.h"
#include <iostream>
#include "Player.h"

class MagicCard : public Card {
public:
    MagicCard(int power, int _manaCost);
    MagicCard();
    int getManaCost() const;
    void play() override;
    void claimReward(Player& player) override;
private:
    int manaCost;
};

#endif
