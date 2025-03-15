#ifndef ENEMY_H
#define ENEMY_H

#include "EnemyDeck.h"
#include "AIController.h"
#include "Player.h"
#include "EnemyDeck.h"
#include <string>
#include <vector>
#include <memory>

class Player;
class AIController;
class EnemyDeck;

class Enemy {
public:
    Enemy();
    Enemy(const std::string& _name, int _hp);
    ~Enemy();
    void takeDamage(int damage);
    virtual void attack(Player& player, int damage);
    void useCard(Player& player);
    void setAIController(AIController* aiController);
    std::string getName() const;
    int getHP() const;
    void setHP(int health);
    virtual void takeTurn(Player& player);
    virtual void castSpell(Player& player, int spellDamage);
    void defend(int defenseValue);
    void setStunned(unsigned turns);
    bool isStunned() const;
    unsigned getStunnedTurns() const;
    void drawCardFromDeck();
    void setDeck(EnemyDeck* newDeck);
    EnemyDeck* getDeck();
    void increaseStunnedTurns();
private:
    std::string name;
    int attackPower;
    int hp;
    int stunnedTurns = 0;
    EnemyDeck* deck = nullptr;
    AIController* aiController;
    std::vector<std::unique_ptr<Card>> hand;
};

#endif


