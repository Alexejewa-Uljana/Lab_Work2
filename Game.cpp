#include "Game.h"
#include <iostream>

Game::Game() {
    deck.initializeDeck();
}

void Game::start() {
    std::cout << "Game has started!" << std::endl;
    showGameStatus();
    while (player.getHP() > 0 && enemy.getHP() > 0) {
        playTurn();
    }
}

void Game::playTurn() {
    playerTurn();
    if (player.getHP() > 0 && enemy.getHP() > 0) {
        enemyTurn();
    }
    showGameStatus();
}

void Game::playerTurn() {
    std::cout << "Your turn!" << std::endl;
    player.showHand();
    int cardIndex;
    std::cout << "Enter the index of the card you want to play: ";
    std::cin >> cardIndex;

    if (cardIndex >= 0 && cardIndex < player.getHandSize()) {
        player.playCard(cardIndex, enemy);
        playerClaimRewards(cardIndex);
        drawNewCardForPlayer();
    } else {
        std::cout << "Invalid card index. Skipping turn.\n";
    }
}

void Game::enemyTurn() {
    enemy.attack(player, 10);
}

void Game::addCardToDeck(std::unique_ptr<Card> newCard) {
    deck.addCard(std::move(newCard));
}

void Game::showGameStatus() const {
    std::cout << "Player HP: " << player.getHP() << ", Mana: " << player.getMana() << std::endl;
    std::cout << "Enemy HP: " << enemy.getHP() << std::endl;
    deck.display();
}

void Game::drawNewCardForPlayer() {
    auto newCard = deck.drawCard();
    if (newCard) {
        player.addCard(std::move(newCard));
    } else {
        refillDeck();
    }
}

void Game::refillDeck() {
    deck.addCard(std::make_unique<AttackCard>(5));
    deck.addCard(std::make_unique<DefenseCard>(5));
    deck.addCard(std::make_unique<MagicCard>(5, 5));
}

void Game::playerClaimRewards(int cardIndex) {
    if (cardIndex >= 0 && cardIndex < player.getHandSize()) {
        player.getHand()[cardIndex]->claimReward(player);
    } else {
        std::cout << "Invalid card index for rewards!" << std::endl;
    }
}
