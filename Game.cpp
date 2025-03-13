#include "Game.h"
#include <iostream>

Game::Game()
    : player(), enemy(), deck(), battleSystem(), turnManager(player, enemy), storyManager(), world() {
    deck.initializeDeck();
}

void Game::start() {
    showStoryAndWorldInfo();

    std::cout << "Game has started!" << std::endl;
    showGameStatus();
    while (player.getHP() > 0 && enemy.getHP() > 0) {
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
    deck.addCard(std::make_unique<StatusEffectCard>("Stun Card", 0, Effect("stun", 2)));
    deck.addCard(std::make_unique<SpecialCard>("Healing Potion", 0, Effect("heal", 10)));
}


