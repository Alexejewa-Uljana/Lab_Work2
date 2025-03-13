#ifndef MANASYSTEM_H
#define MANASYSTEM_H

#include "MagicCard.h"
#include "Player.h"

class ManaSystem {
public:
    static bool canCastMagicCard(Player& player, MagicCard* magicCard);
    static void castMagicCard(Player& player, MagicCard* magicCard);
};

#endif
