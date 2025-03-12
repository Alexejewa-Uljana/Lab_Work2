#include "Game.h"
#include <iostream>

Game::Game() : player(), enemy("Goblin", 30) {}

void Game::start() {
    std::cout << "Game started!" << std::endl;
    battle();
}

void Game::battle() {
    std::cout << "Battle begins between Player and " << enemy.getName() << "!" << std::endl;

    while (player.getHP() > 0 && enemy.getHP() > 0) {
        std::cout << "Player's turn." << std::endl;
        player.showHand();
        if (player.getHandSize() > 0) {
            int choice;
            std::cout << "Choose a card to play (1-" << player.getHandSize() << "): ";
            std::cin >> choice;
            player.playCard(choice - 1, enemy);
        }
        if (enemy.getHP() <= 0) {
            std::cout << "Enemy defeated!" << std::endl;
            break;
        }

        std::cout << enemy.getName() << "'s turn." << std::endl;
        enemy.takeTurn(player);
        if (player.getHP() <= 0) {
            std::cout << "Player defeated!" << std::endl;
        }
    }
}
