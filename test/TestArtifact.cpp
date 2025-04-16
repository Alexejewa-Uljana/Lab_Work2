// Алексеева Ульяна st129990@student.spbu.ru

/**
 * @file TestArtifact.cpp
 * @brief Contains test cases for the Artifact class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "../include/Artifact.h"
#include "../include/Player.h"

/**
 * @test Constructor
 * @brief Tests the constructor of the Artifact class.
 *
 * Verifies that an Artifact object is constructed without any exceptions.
 */
TEST(Artifact, Constructor)
{
    Artifact artifact;
    ASSERT_NO_THROW(Artifact artifact);
}

/**
 * @test RandomArtifactEffect
 * @brief Tests the random effect granted by the Artifact class.
 *
 * Verifies that granting an artifact to the player changes one of the player's attributes (attack, HP, or mana).
 */
TEST(Artifact, RandomArtifactEffect)
{
    Player player;
    int initialAttack = player.getAttackPower();
    int initialHP = player.getHP();
    int initialMana = player.getMana();

    Artifact artifact;
    artifact.grantArtifact(player);

    EXPECT_TRUE(player.getAttackPower() != initialAttack || player.getHP() != initialHP || player.getMana() != initialMana);
}

