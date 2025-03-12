#ifndef CARD_H
#define CARD_H

#include <iostream>

class Player;
class Enemy;

class Card {
public:
    Card(const std::string& _name, int _power);
    virtual ~Card();
    std::string getName() const;
    int getPower() const;
    virtual void play() = 0;
    virtual void claimReward(Player& player) = 0;
private:
    std::string name;
    int power;
};

#endif
