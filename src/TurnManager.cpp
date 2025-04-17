// Алексеева Ульяна st129990@student.spbu.ru
#include "../include/TurnManager.h"
#include "../include/AttackCard.h"
#include "../include/DefenseCard.h"
#include "../include/MagicCard.h"
#include "../include/SpecialCard.h"
#include "../include/StatusEffectCard.h"
#include <iostream>

/**
 * @brief Constructs a TurnManager for a battle between a player and an enemy.
 *
 * Initializes the TurnManager for a battle scenario where the player fights against an enemy.
 *
 * @param p1 The player participating in the battle.
 * @param e The enemy participating in the battle.
 * @param bs The BattleSystem managing the battle mechanics.
 */
TurnManager::TurnManager(Player& p1, Enemy& e, BattleSystem& bs)
    : bossAI(nullptr),
      player(p1),
      player2(nullptr),
      enemy(e),
      battleSystem(bs),
      aiController(),
      rewardSystem(),
      turnCounter(0),
      isPvP(false),
      isBossFight(false)
{}

/**
 * @brief Constructs a TurnManager for a player versus player battle.
 *
 * Initializes the TurnManager for a PvP battle where two players compete against each other.
 *
 * @param p1 The first player participating in the battle.
 * @param p2 The second player participating in the battle.
 * @param bs The BattleSystem managing the battle mechanics.
 */
TurnManager::TurnManager(Player& p1, Player& p2, BattleSystem& bs)
    : bossAI(nullptr),
      player(p1),
      player2(&p2),
      enemy(nullptr),
      battleSystem(bs),
      aiController(),
      rewardSystem(),
      turnCounter(0),
      isPvP(true),
      isBossFight(false)
{}


/**
 * @brief Constructs a TurnManager for a player versus boss battle.
 *
 * Initializes the TurnManager for a battle between a player and a boss, where the boss has a specialized AI.
 *
 * @param p1 The player participating in the battle.
 * @param b The boss participating in the battle.
 * @param bs The BattleSystem managing the battle mechanics.
 */
TurnManager::TurnManager(Player& p1, Boss& b, BattleSystem& bs)
    : bossAI(new BossAI(b)),
      player(p1),
      player2(nullptr),
      enemy(b),
      battleSystem(bs),
      aiController(),
      rewardSystem(),
      turnCounter(0),
      isPvP(false),
      isBossFight(true)
{}

/**
 * @brief Destructor for the TurnManager.
 *
 * Cleans up any dynamically allocated resources, specifically the BossAI instance if it exists.
 */
TurnManager::~TurnManager()
{
    if (bossAI)
    {
        delete bossAI;
    }
}

/**
 * @brief Starts the battle between the player and enemy (or player 2 in PvP mode).
 *
 * This method controls the flow of the battle, alternating turns between the player, the enemy, or both players in PvP mode.
 * It ends when one of the participants' health reaches 0.
 */
void TurnManager::startBattle()
{
    int count_turns = 0;
    while (player.getHP() > 0 && ((!isPvP and enemy.getHP()) > 0 || (player2 && player2->getHP() > 0)))
    {
        if (!isPvP)
        {
            playerTurn();
            count_turns++;
            if(count_turns % 2 == 0) player.restoreMana(5);
            if (enemy.getHP() > 0)
            {
                enemyTurn();
            }
        }
        else
        {
            pvpTurn();
            count_turns++;
            if(count_turns)
            {
                player.restoreMana(5);
                player2->restoreMana(5);
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
 * @brief Handles the turn for Player 1 and Player 2 in a PvP battle.
 *
 * This method alternates turns between Player 1 and Player 2, allowing each player to select and play cards from their hand.
 * It handles actions such as attack, defense, magic, and status effects.
 */
void TurnManager::pvpTurn()
{
    if (player.getHP() <= 0 || player2->getHP() <= 0)
    {
        std::cout << ((player.getHP() > 0) ? "Player 1 wins!" : "Player 2 wins!") << std::endl;
        return;
    }
    int cardIndex;
    bool stun_mana_1 = false;
    bool stun_mana_2 = false;
    bool player_stun = false;
    bool player2_stun = false;
    if(player.getStunned() > 0)
    {
        std::cout << "1st player is stunned!\n";
        player.setStunned(player.getStunned() - 1);
        player_stun = true;
        stun_mana_1 = true;
    }
    else
    {
        std::cout << "It's Player 1's turn!" << std::endl;
        player.showHand();
        std::cout << "Select a card to play (enter index): ";
        std::cin >> cardIndex;
    }
    if (cardIndex >= 0 && cardIndex < player.getHandSize() && !player_stun)
    {
        const std::unique_ptr<Card>& selectedCard = player.getHand()[cardIndex];

        if (auto attackCard = dynamic_cast<AttackCard*>(selectedCard.get()))
        {
            std::cout << "You attack with " << attackCard->getPower() << " power!" << std::endl;
            player2->takeDamage(attackCard->getPower());
            player.removeCard(cardIndex);
            player.drawCards();
        }
        else if (auto defenseCard = dynamic_cast<DefenseCard*>(selectedCard.get()))
        {
            std::cout << "You defend with " << defenseCard->getPower() << " defense!" << std::endl;
            player.increaseAttackPower(defenseCard->getPower());
            player.removeCard(cardIndex);
            player.drawCards();
        }
        else if (auto magicCard = dynamic_cast<MagicCard*>(selectedCard.get()))
        {
            if (player.getMana() >= magicCard->getManaCost())
            {
                std::cout << "You cast a spell for " << magicCard->getManaCost() << " mana!" << std::endl;
                player.reduceMana(magicCard->getManaCost());
                player2->takeDamage(magicCard->getPower());
                player.removeCard(cardIndex);
                player.drawCards();
            }
            else
            {
                std::cout << "Not enough mana to cast this spell!" << std::endl;
                stun_mana_1 = true;
            }
        }
        else if (StatusEffectCard* statusCard = dynamic_cast<StatusEffectCard*>(selectedCard.get()))
        {
            std::cout << "Applying status effect: " << statusCard->getName() << "\n";
            if (statusCard->getEffect().type == "stun")
            {
                player2->setStunned(statusCard->getEffect().value);
            }
            player.removeCard(cardIndex);
            player.drawCards();
        }
        else
        {
            std::cout << "You use Special Card!\n";
            player.playCard(cardIndex, enemy);
            player.removeCard(cardIndex);
            player.drawCards();
        }
        rewardSystem.giveReward(player);
        std::cout << "Player 1 HP: " << player.getHP() << ". Player 2 HP: " << player2->getHP() << std::endl;
    }
    else if(!stun_mana_1)
    {
        std::cout << "Invalid selection!" << std::endl;
    }
    if (player2->getHP() <= 0)
    {
        std::cout << "Player 1 wins!" << std::endl;
        return;
    }
    if(player2->getStunned() > 0)
    {
        std::cout << "2nd player is stunned!\n";
        player2->setStunned(player2->getStunned() - 1);
        player2_stun = true;
        stun_mana_2 = true;
    }
    else
    {
        std::cout << "It's Player 2's turn!" << std::endl;
        player2->showHand();
        std::cout << "Select a card to play (enter index): ";
        std::cin >> cardIndex;
    }
    if (cardIndex >= 0 && cardIndex < player2->getHandSize() && !player2_stun)
    {
        const std::unique_ptr<Card>& selectedCard2 = player2->getHand()[cardIndex];
        if (auto attackCard = dynamic_cast<AttackCard*>(selectedCard2.get()))
        {
            std::cout << "You attack with " << attackCard->getPower() << " power!" << std::endl;
            player.takeDamage(attackCard->getPower());
            player2->removeCard(cardIndex);
            player2->drawCards();
        }
        else if (auto defenseCard = dynamic_cast<DefenseCard*>(selectedCard2.get()))
        {
            std::cout << "You defend with " << defenseCard->getPower() << " defense!" << std::endl;
            player2->increaseAttackPower(defenseCard->getPower());
            player2->removeCard(cardIndex);
            player2->drawCards();
        }
        else if (auto magicCard = dynamic_cast<MagicCard*>(selectedCard2.get()))
        {
            if (player.getMana() >= magicCard->getManaCost())
            {
                std::cout << "You cast a spell for " << magicCard->getManaCost() << " mana!" << std::endl;
                player2->reduceMana(magicCard->getManaCost());
                player.takeDamage(magicCard->getPower());
                player2->removeCard(cardIndex);
                player2->drawCards();
            }
            else
            {
                std::cout << "Not enough mana to cast this spell!" << std::endl;
                stun_mana_2 = true;
            }
        }
        else if (StatusEffectCard* statusCard = dynamic_cast<StatusEffectCard*>(selectedCard2.get()))
        {
            std::cout << "Applying status effect: " << statusCard->getName() << "\n";
            if (statusCard->getEffect().type == "stun")
            {
                player.setStunned(statusCard->getEffect().value);
            }
            player2->removeCard(cardIndex);
            player2->drawCards();
        }
        else
        {
            std::cout << "You use Special Card!\n";
            player2->playCard(cardIndex, enemy);
            player2->removeCard(cardIndex);
            player2->drawCards();
        }
        std::cout << "Player 1 HP: " << player.getHP() << ". Player 2 HP: " << player2->getHP() << std::endl;
        rewardSystem.giveReward(*player2);
    }
    else if(!stun_mana_2)
    {
        std::cout << "Invalid selection!" << std::endl;
    }
    if (player.getHP() <= 0)
    {
        std::cout << "Player 2 wins!" << std::endl;
        return;
    }
}

/**
 * @brief Executes the enemy's turn during the battle.
 *
 * This method manages the actions performed by the enemy during their turn. It handles
 * stun effects and utilizes AI for the enemy's actions.
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
 * @brief Executes the player's turn during the battle.
 *
 * This method allows the player to choose a card to play, performs the selected action, and
 * updates the player's stats accordingly. It handles attack, defense, magic, and special cards.
 */
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
        player.removeCard(cardIndex);
        player.drawCards();
    } else if (auto defenseCard = dynamic_cast<DefenseCard*>(selectedCard.get())) {
        std::cout << "You defend with " << defenseCard->getPower() << " defense!" << std::endl;
        player.increaseAttackPower(defenseCard->getPower());
        player.removeCard(cardIndex);
        player.drawCards();
    } else if (auto magicCard = dynamic_cast<MagicCard*>(selectedCard.get())) {
        if (player.getMana() >= magicCard->getManaCost()) {
            std::cout << "You cast a spell for " << magicCard->getManaCost() << " mana!" << std::endl;
            player.reduceMana(magicCard->getManaCost());
            enemy.takeDamage(magicCard->getPower());
            player.removeCard(cardIndex);
            player.drawCards();
        } else {
            std::cout << "Not enough mana to cast this spell!" << std::endl;
        }
    } else if (StatusEffectCard* statusCard = dynamic_cast<StatusEffectCard*>(selectedCard.get())) {
        std::cout << "Applying status effect: " << statusCard->getName() << "\n";
        if (statusCard->getEffect().type == "stun") {
            enemy.setStunned(statusCard->getEffect().value);
        }
        player.removeCard(cardIndex);
        player.drawCards();
    } else if(SpecialCard* speacialCard = dynamic_cast<SpecialCard*>(selectedCard.get())){
        std::cout << "You use Special Card!\n";
        player.playCard(cardIndex, enemy);
        player.removeCard(cardIndex);
        player.drawCards();
    }
     else {
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
