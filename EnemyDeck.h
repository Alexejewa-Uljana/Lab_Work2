#ifndef ENEMYDECK_H
#define ENEMYDECK_H

#include <vector>
#include <memory>
#include "Card.h"
#include "AttackCard.h"
#include "DefenseCard.h"

class EnemyDeck {
public:
    EnemyDeck();
    ~EnemyDeck();
    void addCard(std::unique_ptr<Card> card);
    std::unique_ptr<Card> drawCard();
    void initializeDeck();
    const int getSize() const;

private:
    std::vector<std::unique_ptr<Card>> deck;
};

#endif
