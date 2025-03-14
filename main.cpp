#include <iostream>
#include "Game.h"

int main() {
    int difficulty;

    std::cout << "Welcome to the game!\n";
    std::cout << "Select difficulty level:\n";
    std::cout << "1 - Easy\n";
    std::cout << "2 - Medium\n";
    std::cout << "3 - Hard\n";
    std::cout << "Enter difficulty (1-3): ";
    
    while (true) {
        std::cin >> difficulty;

        if (difficulty >= 1 && difficulty <= 3) {
            break;
        } else {
            std::cout << "Invalid choice! Please enter 1, 2, or 3: ";
        }
    }

    Game game(difficulty);
    game.start();

    return 0;
}


