#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "Player.h"
#include <string>

class Boss : public Enemy {
public:
    Boss();
    Boss(const std::string& _name, int _hp);
    ~Boss() = default;
    void useSpecialAbility(Player& player);
    void takeTurn(Player& player) override;
    void attack(Player& player, int damage) override;
    void castSpell(Player& player, int spellDamage) override;
};

#endif
