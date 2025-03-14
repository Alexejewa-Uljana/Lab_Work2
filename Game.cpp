#include "Game.h"
#include <iostream>

Game::Game(int difficulty)
    : player(), battleSystem(difficulty), turnManager(player, battleSystem.getEnemy()), storyManager(), world() {
    player.getDeck()->initializeDeck();
}

void Game::start() {
    showStoryAndWorldInfo();

    std::cout << "Game has started!" << std::endl;
    showGameStatus();

    while (player.getHP() > 0 && battleSystem.getEnemy().getHP() > 0) {
        turnManager.startTurn();
        showGameStatus();
    }

    if (player.getHP() <= 0) {
        std::cout << "You lost the game!" << std::endl;
    } else {
        std::cout << "You won the game!" << std::endl;
    }
}

void Game::showStoryAndWorldInfo() {
    storyManager.showStory();
    world.load();
    std::cout << "Current level: " << world.getLevel() << std::endl;
}

void Game::showGameStatus() const {
    std::cout << "Player HP: " << player.getHP() << ", Mana: " << player.getMana() << std::endl;
    std::cout << "Enemy HP: " << battleSystem.getEnemy().getHP() << std::endl;
    player.getDeck()->display();
}

void Game::drawNewCardForPlayer() {
    auto newCard = player.getDeck()->drawCard();
    if (newCard) {
        player.addCard(std::move(newCard));
    } else {
        refillDeck();
    }
}

void Game::refillDeck() {
    player.getDeck()->initializeDeck();
}


