#ifndef SPECIAL_CARD_H
#define SPECIAL_CARD_H

#include "Card.h"
#include "Effect.h"
#include "Player.h"
#include <iostream>

class SpecialCard : public Card {
private:
    Effect effect;

public:
    SpecialCard(const std::string& name, int power, Effect effect);
    void play() override;
    void claimReward(Player& player) override;
    Effect getEffect() const;
};

#endif
