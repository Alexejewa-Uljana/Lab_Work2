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
    virtual void attack(Player& player, int damage);
    virtual void takeTurn(Player& player);
    void takeDamage(int damage);
    virtual void castSpell(Player& player, int spellDamage);
    void defend(int defenseValue);
    void setStunned(int turns);
    bool isStunned();
    int getStunnedTurns() const;
private:
    std::string name;
    int hp;
    EnemyDeck deck;
    AIController aiController;
    int stunnedTurns = 0;
    std::vector<std::unique_ptr<Card>> hand;
};

#endif
