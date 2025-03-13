#ifndef ENEMY_H
#define ENEMY_H

#include "EnemyDeck.h"
#include "AIController.h"
#include "Player.h"
#include <string>

class Player;

class Enemy {
public:
    Enemy();
    Enemy(const std::string& _name, int _hp);
    std::string getName() const;
    int getHP() const;
    void setHP(int health);
    void attack(Player& player, int damage);
    void takeTurn(Player& player);
    void takeDamage(int damage);
    void castSpell(Player& player, int spellDamage);
    void defend(int defenseValue);

private:
    std::string name;
    int hp;
    EnemyDeck deck;
    AIController aiController;
};

#endif
