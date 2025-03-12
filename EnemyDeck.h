#ifndef ENEMYDECK_H
#define ENEMYDECK_H

#include "Card.h"
#include <vector>
#include <memory>

class EnemyDeck {
public:
    void addCard(std::unique_ptr<Card> card);
    std::unique_ptr<Card> drawCard();

private:
    std::vector<std::unique_ptr<Card>> cards;
};

#endif
