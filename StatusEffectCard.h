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
    StatusEffectCard(const std::string& name, int power, Effect effect)
        : Card(name, power), effect(effect) {}

    void play() override {
        std::cout << "Using status effect card: " << getName() << "\n";
    }

    void claimReward(Player& player) override {
        std::cout << "Claiming reward from: " << getName() << "\n";
    }

    Effect getEffect() const {
        return effect;
    }
};

#endif

