// Алексеева Ульяна st129990@student.spbu.ru
#include "Game.h"
#include <iostream>

/**
 * @brief The entry point for the game.
 * Prompts the user to select a difficulty level and starts the game.
 */
int main()
{
    int difficulty;
    std::cout << "Choose difficulty (1 - easy, 2 - normal, 3 - boss fight): ";
    std::cin >> difficulty;

    Game game(difficulty);
    game.start();

    return 0;
}
