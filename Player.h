#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <vector>
#include "Deck.h"
#include "Card.h"

class Enemy;
class Deck;

class Player {
public:
    Player();
    ~Player();
    void showHand() const;
    void setName(const std::string& _name);
    void setHP(int _hp);
    void playCard(int index, Enemy& enemy);
    void showDeck() const;
    void heal(int amount);
    void setDeck(std::unique_ptr<Deck> newDeck);
    Deck* getDeck() const;
    int getHP() const;
    int getMana() const;
    int getHandSize() const;
    void takeDamage(int damage);
    void addCard(std::unique_ptr<Card> newCard);
    void increaseAttackPower(int amount);
    void restoreMana(int amount);
    void restoreHealth(int amount);
    void addCardToDeck(std::unique_ptr<Card> card);
    const std::vector<std::unique_ptr<Card>>& getHand() const;
    void reduceMana(int amount);
    void setStunned(int turns);
    void removeCard(int index);
    void drawCards();
private:
    int hp;
    int mana;
    int attackPower;
    std::unique_ptr<Deck> deck;
    std::vector<std::unique_ptr<Card>> hand;
    int stunnedTurns = 0;
};

#endif
