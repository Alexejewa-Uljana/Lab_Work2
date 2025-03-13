#include "Effect.h"
#include <iostream>

Effect::Effect(const std::string& t, int v) : type(t), value(v) {}

void Effect::applyEffect() {
    std::cout << "Applying effect: " << type << " with value " << value << "\n";
}
