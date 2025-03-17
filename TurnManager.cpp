#include "TurnManager.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "MagicCard.h"
#include "SpecialCard.h"
#include "StatusEffectCard.h"
#include <iostream>

TurnManager::TurnManager(Player& p1, Enemy& e, BattleSystem& bs)
    : player(p1), enemy(e), battleSystem(bs), turnCounter(0), isPvP(false), player2(nullptr), isBossFight(false), bossAI(nullptr) {}

TurnManager::TurnManager(Player& p1, Player& p2, BattleSystem& bs)
    : player(p1), player2(&p2), battleSystem(bs), turnCounter(0), isPvP(true), enemy(*new Enemy()), isBossFight(false), bossAI(nullptr) {}

TurnManager::TurnManager(Player& p1, Boss& b, BattleSystem& bs)
    : player(p1), enemy(b), battleSystem(bs), turnCounter(0), isPvP(false), player2(nullptr), isBossFight(true), bossAI(new BossAI(b)) {}

TurnManager::~TurnManager() {
    if (bossAI) {
        delete bossAI;
    }
}

void TurnManager::startBattle() {
    while (player.getHP() > 0 && ((!isPvP and enemy.getHP()) > 0 || (player2 && player2->getHP() > 0))) {
        if (!isPvP) {
            playerTurn();
            if (enemy.getHP() > 0) {
                enemyTurn();
            }
        } else {
            pvpTurn();
        }
    }

    std::cout << ((player.getHP() > 0) ? "You win!" : "You lost...") << std::endl;

    if (bossAI) {
        delete bossAI;
        bossAI = nullptr;
    }
}

void TurnManager::pvpTurn() {
    if (player.getHP() <= 0 || player2->getHP() <= 0) {
        std::cout << ((player.getHP() > 0) ? "Player 1 wins!" : "Player 2 wins!") << std::endl;
        return;
    }
    std::cout << "It's Player 1's turn!" << std::endl;
    player.showHand();
    std::cout << "Select a card to play (enter index): ";
    int cardIndex;
    std::cin >> cardIndex;

    if (cardIndex >= 0 && cardIndex < player.getHandSize()) {
        const std::unique_ptr<Card>& selectedCard = player.getHand()[cardIndex];

        if (auto attackCard = dynamic_cast<AttackCard*>(selectedCard.get())) {
            std::cout << "You attack with " << attackCard->getPower() << " power!" << std::endl;
            player2->takeDamage(attackCard->getPower());
            player.removeCard(cardIndex);
        } else if (auto defenseCard = dynamic_cast<DefenseCard*>(selectedCard.get())) {
            std::cout << "You defend with " << defenseCard->getPower() << " defense!" << std::endl;
            player.increaseAttackPower(defenseCard->getPower());
            player.removeCard(cardIndex);
        } else if (auto magicCard = dynamic_cast<MagicCard*>(selectedCard.get())) {
            if (player.getMana() >= magicCard->getManaCost()) {
                std::cout << "You cast a spell for " << magicCard->getManaCost() << " mana!" << std::endl;
                player.reduceMana(magicCard->getManaCost());
                player2->takeDamage(magicCard->getPower());
                player.removeCard(cardIndex);
            } else {
                std::cout << "Not enough mana to cast this spell!" << std::endl;
                return;
            }
        } else {
            std::cout << "You use Special Card/Status Effect Card!\n";
            player.playCard(cardIndex, enemy);
            player.removeCard(cardIndex);
        }
        rewardSystem.giveReward(player);
        player.drawCards();
    } else {
        std::cout << "Invalid selection!" << std::endl;
    }
    if (player2->getHP() <= 0) {
        std::cout << "Player 1 wins!" << std::endl;
        return;
    }
    std::cout << "It's Player 2's turn!" << std::endl;
    player2->showHand();
    std::cout << "Select a card to play (enter index): ";
    std::cin >> cardIndex;

    if (cardIndex >= 0 && cardIndex < player2->getHandSize()) {
        const std::unique_ptr<Card>& selectedCard2 = player2->getHand()[cardIndex];
        if (auto attackCard = dynamic_cast<AttackCard*>(selectedCard2.get())) {
            std::cout << "You attack with " << attackCard->getPower() << " power!" << std::endl;
            player.takeDamage(attackCard->getPower());
            player2->removeCard(cardIndex);
        } else if (auto defenseCard = dynamic_cast<DefenseCard*>(selectedCard2.get())) {
            std::cout << "You defend with " << defenseCard->getPower() << " defense!" << std::endl;
            player2->increaseAttackPower(defenseCard->getPower());
            player2->removeCard(cardIndex);
        } else if (auto magicCard = dynamic_cast<MagicCard*>(selectedCard2.get())) {
            if (player.getMana() >= magicCard->getManaCost()) {
                std::cout << "You cast a spell for " << magicCard->getManaCost() << " mana!" << std::endl;
                player2->reduceMana(magicCard->getManaCost());
                player.takeDamage(magicCard->getPower());
                player2->removeCard(cardIndex);
            } else {
                std::cout << "Not enough mana to cast this spell!" << std::endl;
                return;
            }
        } else {
            std::cout << "You use Special Card/Status Effect Card!\n";
            player2->playCard(cardIndex, enemy);
            player2->removeCard(cardIndex);
        }
        player2->drawCards();
        rewardSystem.giveReward(*player2);
    } else {
        std::cout << "Invalid selection!" << std::endl;
    }
}

void TurnManager::enemyTurn() {
    std::cout << enemy.getName() << "'s turn.\n";
    if (enemy.isStunned()) {
        std::cout << enemy.getName() << " is stunned and cannot attack this turn!\n";
        enemy.increaseStunnedTurns();
        return;
    }
    if (isBossFight && bossAI) {
        bossAI->takeTurn(dynamic_cast<Boss&>(enemy), player);
    } else {
        aiController.makeMove(enemy, player);
    }
    std::cout << "Player HP: " << player.getHP() << "\n";
}

void TurnManager::playerTurn() {
    if (player.getHP() <= 0) {
        std::cout << "You lost!" << std::endl;
        return;
    }

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
        player.removeCard(cardIndex); // Удаляем карту
    } else if (auto defenseCard = dynamic_cast<DefenseCard*>(selectedCard.get())) {
        std::cout << "You defend with " << defenseCard->getPower() << " defense!" << std::endl;
        player.increaseAttackPower(defenseCard->getPower());
        player.removeCard(cardIndex); // Удаляем карту
    } else if (auto magicCard = dynamic_cast<MagicCard*>(selectedCard.get())) {
        if (player.getMana() >= magicCard->getManaCost()) {
            std::cout << "You cast a spell for " << magicCard->getManaCost() << " mana!" << std::endl;
            player.reduceMana(magicCard->getManaCost());
            enemy.takeDamage(magicCard->getPower());
            player.removeCard(cardIndex); // Удаляем карту
        } else {
            std::cout << "Not enough mana to cast this spell!" << std::endl;
            return;
        }
    } else if (dynamic_cast<SpecialCard*>(selectedCard.get()) || dynamic_cast<StatusEffectCard*>(selectedCard.get())) {
        std::cout << "You use Special Card/Status Effect Card!\n";
        player.playCard(cardIndex, enemy);
        player.removeCard(cardIndex); // Удаляем карту
    } else {
        std::cout << "Unknown card type!" << std::endl;
        return;
    }

    if (player.getDeck()->isEmpty()) {
        std::cout << "No more cards in the deck!\n";
        refillDeck();
    }

    player.drawCards();
    turnCounter++;

    if (turnCounter % 2 == 0) {
        player.restoreMana(4);
        std::cout << "Every even move you get 4 mana!\n";
    }

    rewardSystem.giveReward(player);
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
    deck->addCard(std::make_unique<AttackCard>(5));
    deck->addCard(std::make_unique<DefenseCard>(5));
    deck->addCard(std::make_unique<MagicCard>(5, 5));
    deck->addCard(std::make_unique<SpecialCard>("Health Card", 0, Effect("heal", 5)));
    deck->addCard(std::make_unique<StatusEffectCard>("Stun Card", 0, Effect("Stun", 2)));

    std::cout << "Deck has been refilled with new cards!" << std::endl;
}
