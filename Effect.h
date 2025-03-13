#ifndef EFFECT_H
#define EFFECT_H

#include <string>

struct Effect {
    std::string type;
    int value;

    Effect(const std::string& t = "none", int v = 0);
    void applyEffect();
};

#endif


