#ifndef EFFECT_H
#define EFFECT_H

#include <string>

class Effect {
public:
    Effect(std::string name, int value);
    void applyEffect();

private:
    std::string name;
    int value;
};

#endif
