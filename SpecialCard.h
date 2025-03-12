#ifndef SPECIALCARD_H
#define SPECIALCARD_H

#include "Card.h"
#include <iostream>

class SpecialCard : public Card {
public:
    void play() override {
        std::cout << "Played Special Card!" << std::endl;
    }
};

#endif
