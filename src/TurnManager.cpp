// Алексеева Ульяна st129990@student.spbu.ru
#include "TurnManager.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include "SpecialCard.h"
#include "StatusEffectCard.h"
#include <iostream>

/**
 * @brief Constructor for TurnManager in a battle with an enemy.
 * @param p The player.
 * @param e The enemy.
 * @param bs The battle system.
 */
TurnManager::TurnManager(Player& p, Enemy& e, BattleSystem& bs)
    : player(p), enemy(e), battleSystem(bs), isBossFight(false), bossAI(nullptr), turnCounter(0) {}

/**
 * @brief Constructor for TurnManager in a battle with a boss.
 * @param p The player.
 * @param b The boss.
 * @param bs The battle system.
 */
TurnManager::TurnManager(Player& p, Boss& b, BattleSystem& bs)
    : player(p), enemy(b), battleSystem(bs), isBossFight(true), turnCounter(0)
{
    bossAI = new BossAI(b);
}

/**
 * @brief Destructor for TurnManager.
 * Frees memory used by BossAI.
 */
TurnManager::~TurnManager()
{
    delete bossAI;
}

/**
 * @brief Starts the battle between the player and the enemy or boss.
 * Includes alternating turns between the player and the enemy.
 */
void TurnManager::startBattle()
{
    while (player.getHP() > 0 && enemy.getHP() > 0)
    {
        playerTurn();
        if (enemy.getHP() > 0)
        {
            if (isBossFight)
            {
                bossAI->takeTurn(dynamic_cast<Boss&>(enemy), player);
            }
            else
            {
                enemyTurn();
            }
        }
    }
    std::cout << ((player.getHP() > 0) ? "You win!" : "You lost...") << std::endl;
    if (bossAI)
    {
        delete bossAI;
        bossAI = nullptr;
    }
}

/**
 * @brief Enemy's turn.
 * Handles the enemy's actions, including card use or attacks.
 */
void TurnManager::enemyTurn()
{
    std::cout << enemy.getName() << "'s turn.\n";
    if (enemy.isStunned())
    {
        std::cout << enemy.getName() << " is stunned and cannot attack this turn!\n";
        enemy.increaseStunnedTurns();
        return;
    }
    if (isBossFight && bossAI)
    {
        bossAI->takeTurn(dynamic_cast<Boss&>(enemy), player);
    }
    else
    {
        aiController.makeMove(enemy, player);
    }
    std::cout << "Player HP: " << player.getHP() << "\n";
}

/**
 * @brief Player's turn.
 * The player selects a card from their hand and applies it.
 */
void TurnManager::playerTurn()
{
    std::cout << "It's your turn!" << std::endl;
    player.showHand();
    std::cout << "Select a card to play (enter index): ";
    int cardIndex;
    std::cin >> cardIndex;

    if (cardIndex < 0 || cardIndex >= player.getHandSize())
    {
        std::cout << "Invalid selection!" << std::endl;
        return;
    }

    const std::unique_ptr<Card>& selectedCard = player.getHand()[cardIndex];

    if (auto attackCard = dynamic_cast<AttackCard*>(selectedCard.get()))
    {
        std::cout << "You attack with " << attackCard->getPower() << " power!" << std::endl;
        enemy.takeDamage(attackCard->getPower());
        player.removeCard(cardIndex);
    }
    else if (auto defenseCard = dynamic_cast<DefenseCard*>(selectedCard.get()))
    {
        std::cout << "You defend with " << defenseCard->getPower() << " defense!" << std::endl;
        player.increaseAttackPower(defenseCard->getPower());
        player.removeCard(cardIndex);
    }
    else if (auto magicCard = dynamic_cast<MagicCard*>(selectedCard.get()))
    {
        if (player.getMana() >= magicCard->getManaCost())
        {
            std::cout << "You cast a spell for " << magicCard->getManaCost() << " mana!" << std::endl;
            player.reduceMana(magicCard->getManaCost());
            enemy.takeDamage(magicCard->getPower());
            player.removeCard(cardIndex);
        }
        else
        {
            std::cout << "Not enough mana to cast this spell!" << std::endl;
            return;
        }
    }
    else if (dynamic_cast<SpecialCard*>(selectedCard.get()) || dynamic_cast<StatusEffectCard*>(selectedCard.get()))
    {
        std::cout << "You use Special Card/Status Effect Card!\n";
        player.playCard(cardIndex, enemy);
        player.removeCard(cardIndex);
    }
    else
    {
        std::cout << "Unknown card type!" << std::endl;
        return;
    }

    if (player.getDeck()->isEmpty())
    {
        std::cout << "No more cards in the deck!\n";
        refillDeck();
    }

    player.drawCards();
    turnCounter++;

    if (turnCounter % 2 == 0)
    {
        player.restoreMana(4);
        std::cout << "Every even move you get 4 mana!\n";
    }

    rewardSystem.giveReward(player);
}

/**
 * @brief Draws a new card for the player.
 * The player receives a card from their deck.
 */
void TurnManager::drawNewCardForPlayer()
{
    if (!player.getDeck())
    {
        std::cout << "No deck assigned to player!" << std::endl;
        return;
    }

    auto newCard = player.getDeck()->drawCard();

    if (newCard)
    {
        std::cout << "You drew a new card!" << std::endl;
        player.addCard(std::move(newCard));
    }
    else
    {
        std::cout << "The deck is empty!" << std::endl;
    }
}

/**
 * @brief Refills the player's deck with new cards.
 * Adds new cards to an empty or used deck.
 */
void TurnManager::refillDeck()
{
    if (!player.getDeck())
    {
        std::cout << "No deck assigned to player!" << std::endl;
        return;
    }

    auto deck = player.getDeck();
    deck->addCard(std::make_unique<AttackCard>(5));
    deck->addCard(std::make_unique<DefenseCard>(5));
    deck->addCard(std::make_unique<MagicCard>(5, 5));
    deck->addCard(std::make_unique<SpecialCard>("Health Card", 0, Effect("heal", 5)));
    deck->addCard(std::make_unique<StatusEffectCard>("Stun Card", 0, Effect("SStun", 2)));

    std::cout << "Deck has been refilled with new cards!" << std::endl;
}


