#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "Player.h"
#include <vector>
#include <string>

/**
 * @class Artifact
 * @brief The Artifact class manages artifacts that can be granted to a player.
 *
 * The Artifact class provides functionality to grant random artifacts to a player,
 * such as increasing attack power, restoring health, or restoring mana.
 */
class Artifact
{

public:
    /**
     * @brief Default constructor for Artifact.
     *
     * Initializes a list of possible artifacts that can be granted to the player.
     */
    Artifact();

    /**
     * @brief Destructor for Artifact.
     *
     * The destructor cleans up any resources used by the Artifact object.
     * In this case, no dynamic memory allocation is used, so it is a default destructor.
     */
    ~Artifact() = default;

    /**
     * @brief Grants a random artifact to the player.
     * @param player The player who will receive the artifact.
     *
     * This method randomly selects one of the three available artifacts:
     * - A battle amulet that increases attack power by 5.
     * - The stone of life that restores 10 HP.
     * - A magic ball that restores 3 mana.
     * The corresponding effect is then applied to the player.
     */
    void grantArtifact(Player& player);

private:
    /**
     * @brief List of possible artifact names.
     *
     * This vector holds the names of the artifacts that can be granted to the player.
     */
    std::vector<std::string> artifacts;
};

#endif // ARTIFACT_H


