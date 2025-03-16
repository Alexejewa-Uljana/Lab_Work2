#include "gtest/gtest.h"
#include "Artifact.h"
#include "Player.h"

TEST(Artifact, Constructor) {
    Artifact artifact;
    ASSERT_NO_THROW(Artifact artifact);
}

TEST(Artifact, RandomArtifactEffect) {
    Player player;
    int initialAttack = player.getAttackPower();
    int initialHP = player.getHP();
    int initialMana = player.getMana();
    Artifact artifact;
    artifact.grantArtifact(player);
    EXPECT_TRUE(player.getAttackPower() != initialAttack || player.getHP() != initialHP || player.getMana() != initialMana);
}
