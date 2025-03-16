#ifndef STATUS_EFFECT_CARD_H
#define STATUS_EFFECT_CARD_H

#include "Card.h"
#include "Effect.h"
#include "Player.h"
#include <iostream>
#include "Enemy.h"

class StatusEffectCard : public Card {
private:
    Effect effect;

public:
    StatusEffectCard(const std::string& name, int power, Effect effect);
    ~StatusEffectCard() = default;
    void play() override;

    void claimReward(Player& player) override ;

    Effect getEffect() const;
};

#endif

