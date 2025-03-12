#ifndef STATUSEFFECTCARD_H
#define STATUSEFFECTCARD_H

#include "Card.h"
#include <iostream>

class StatusEffectCard : public Card {
public:
    void play() override {
        std::cout << "Played Status Effect Card!" << std::endl;
    }
};

#endif
