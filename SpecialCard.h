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
    SpecialCard(const std::string& name, int power, Effect effect)
        : Card(name, power), effect(effect) {}

    void play() override {
        std::cout << "Using special card: " << getName() << "\n";
    }

    void claimReward(Player& player) override {
        std::cout << "Claiming special card reward: " << getName() << "\n";
    }
    Effect getEffect() const {
        return effect;
    }
};

#endif
