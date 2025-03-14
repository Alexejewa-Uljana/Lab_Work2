#include "TurnManager.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include "SpecialCard.h"
#include "StatusEffectCard.h"
#include <iostream>

TurnManager::TurnManager(Player& p, Enemy& e, BattleSystem& bs) : player(p), enemy(e), rewardSystem(), battleSystem(bs) {}

void TurnManager::startBattle() {
    std::cout << "Battle begins between you and " << enemy.getName() << "!\n";

    while (player.getHP() > 0 && enemy.getHP() > 0) {
        startTurn();

        if (enemy.getHP() > 0) {
            enemyTurn();
        }
    }

    if (player.getHP() > 0) {
        std::cout << "You have defeated " << enemy.getName() << "!\n";
        rewardSystem.giveReward(player);
    } else {
        std::cout << "You were defeated by " << enemy.getName() << ".\n";
    }
}

void TurnManager::startTurn() {
    std::cout << "It's your turn!" << std::endl;
    player.showHand();
    std::cout << "Select a card to play (enter index): ";
    int cardIndex;
    std::cin >> cardIndex;

    if (cardIndex < 0 || cardIndex >= player.getHandSize()) {
        std::cout << "Invalid selection!" << std::endl;
        return;
    }

    const std::unique_ptr<Card>& selectedCard = player.getHand()[cardIndex];

    if (auto attackCard = dynamic_cast<AttackCard*>(selectedCard.get())) {
        std::cout << "You attack with " << attackCard->getPower() << " power!" << std::endl;
        enemy.takeDamage(attackCard->getPower());
    } else if (auto defenseCard = dynamic_cast<DefenseCard*>(selectedCard.get())) {
        std::cout << "You defend with " << defenseCard->getPower() << " defense!" << std::endl;
        player.increaseAttackPower(defenseCard->getPower());
    } else if (auto magicCard = dynamic_cast<MagicCard*>(selectedCard.get())) {
        if (player.getMana() >= magicCard->getManaCost()) {
            std::cout << "You cast a spell for " << magicCard->getManaCost() << " mana!" << std::endl;
            player.reduceMana(magicCard->getManaCost());
            enemy.takeDamage(magicCard->getPower());
        } else {
            std::cout << "Not enough mana to cast this spell!" << std::endl;
            return;
        }
    } else if (dynamic_cast<SpecialCard*>(selectedCard.get()) || dynamic_cast<StatusEffectCard*>(selectedCard.get())) {
        player.playCard(cardIndex, enemy);
    } else {
        std::cout << "Unknown card type!" << std::endl;
        return;
    }

    player.removeCard(cardIndex);
    
    if (player.getDeck()->isEmpty()) {
        std::cout << "No more cards in the deck!\n";
        refillDeck();
    }

    player.drawCards();
    rewardSystem.giveReward(player);
}

void TurnManager::enemyTurn() {
    std::cout << enemy.getName() << "'s turn!\n";
    aiController.makeMove(enemy, player);
}

void TurnManager::drawNewCardForPlayer() {
    if (!player.getDeck()) {
        std::cout << "No deck assigned to player!" << std::endl;
        return;
    }

    auto newCard = player.getDeck()->drawCard();
    if (newCard) {
        std::cout << "You drew a new card!" << std::endl;
        player.addCard(std::move(newCard));
    } else {
        std::cout << "The deck is empty!" << std::endl;
    }
}

void TurnManager::refillDeck() {
    if (!player.getDeck()) {
        std::cout << "No deck assigned to player!" << std::endl;
        return;
    }

    auto deck = player.getDeck();
    deck->addCard(std::make_unique<AttackCard>(5));
    deck->addCard(std::make_unique<DefenseCard>(5));
    deck->addCard(std::make_unique<MagicCard>(5, 5));
    deck->addCard(std::make_unique<SpecialCard>("Health Card", 0, Effect("heal", 5)));
    deck->addCard(std::make_unique<StatusEffectCard>("Stun Card", 0, Effect("Stun", 2)));

    std::cout << "Deck has been refilled with new cards!" << std::endl;
}


