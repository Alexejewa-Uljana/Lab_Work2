#include "Game.h"
#include <iostream>

int main() {
    int difficulty;
    std::cout << "Select difficulty (1 - Easy, 2 - Normal, 3 - Hard): ";
    std::cin >> difficulty;

    Game game(difficulty);
    game.start();

    return 0;
}


