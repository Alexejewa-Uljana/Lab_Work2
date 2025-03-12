#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Card.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include <vector>

class Enemy;

class Player {
public:
    Player();
    void showHand() const;
    void playCard(int index, Enemy& enemy);
    void showDeck() const;
    void heal(int amount);
    int getHP() const;
    int getMana() const;
    int getHandSize() const;
    void takeDamage(int damage);
    void addCard(Card* newCard);
    void increaseAttackPower(int amount);
    void restoreMana(int amount);
    void restoreHealth(int amount);
    void addCardToDeck(Card* card);

private:
    int hp;
    int mana;
    int attackPower;
    Deck deck;
    std::vector<Card*> hand;
    void drawCards();
};

#endif
