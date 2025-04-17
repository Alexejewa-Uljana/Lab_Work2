// Алексеева Ульяна st129990@student.spbu.ru
#include "../include/Artifact.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Default constructor for Artifact.
 *
 * Initializes the list of artifacts and sets up the random number generator
 * by seeding it with the current time.
 */
Artifact::Artifact()
{
    artifacts =
    {
        "A battle amulet (+5 attack)",
        "The stone of life (+10 HP)",
        "Magic ball (+3 mana)"
    };

    srand(static_cast<unsigned>(time(nullptr)));
}

/**
 * @brief Grants a random artifact to the player.
 * @param player The player who will receive the artifact.
 *
 * This method randomly selects an artifact from the list of available artifacts
 * and applies the corresponding effect to the player. The possible effects are:
 * - Increases attack power by 5.
 * - Restores 10 HP.
 * - Restores 3 mana.
 */
void Artifact::grantArtifact(Player& player)
{
    int index = rand() % 3;  ///< Randomly selects an artifact from the list.
    std::string chosenArtifact = artifacts[index];

    std::cout << "You have received an artifact: " << chosenArtifact << "!\n";

    if (index == 0)
    {
        player.increaseAttackPower(5);  ///< Grant a battle amulet (increase attack power).
    }
    else if (index == 1)
    {
        player.setHP(player.getHP() + 10);  ///< Grant the stone of life (restore HP).
    }
    else if (index == 2)
    {
        player.restoreMana(3);  ///< Grant a magic ball (restore mana).
    }
}
