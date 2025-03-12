#include "Effect.h"
#include <iostream>

Effect::Effect(std::string n, int v) : name(n), value(v) {}

void Effect::applyEffect() {
    std::cout << "Applying effect: " << name << " with value " << value << "\n";
}
