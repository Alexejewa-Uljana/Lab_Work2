#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "Player.h"
#include <string>

class Boss : public Enemy {
public:
    Boss();
    Boss(const std::string& _name, int _hp);

    // Метод использования специальной способности
    void useSpecialAbility(Player& player);

    // Переопределенный метод хода
    void takeTurn(Player& player) override;
    void attack(Player& player, int damage) override;  // Переопределяем метод атаки для боса
    void castSpell(Player& player, int spellDamage) override;  // Переопределяем метод заклинания для боса
};

#endif
