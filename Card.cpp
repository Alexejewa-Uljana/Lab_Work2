#include "Card.h"

Card::Card(const std::string& _name, int  _power): name(_name), power(_power) {}

Card::~Card() {}

std::string Card::getName() const {
    return name;
}

int Card::getPower() const {
    return power;
}
