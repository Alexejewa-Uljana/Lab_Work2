#include "Game.h"
#include <iostream>

int main() {
    int difficulty;
    std::cout << "Choose difficulty (1 - easy, 2 - normal, 3 - boss fight): ";
    std::cin >> difficulty;

    Game game(difficulty);
    game.start();

    return 0;
}
