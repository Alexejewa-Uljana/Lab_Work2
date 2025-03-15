#include "Artifact.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Artifact::Artifact() {
    artifacts = {
        "Боевой амулет (+5 к атаке)",
        "Камень жизни (+10 HP)",
        "Магический шар (+3 маны за ход)"
    };

    srand(static_cast<unsigned>(time(nullptr)));
}

void Artifact::grantArtifact(Player& player) {
    int index = rand() % 3;
    std::string chosenArtifact = artifacts[index];

    std::cout << "You have received an artifact: " << chosenArtifact << "!\n";

    if (index == 0) {
        player.increaseAttackPower(5);
    }
    else if (index == 1) {
        player.setHP(player.getHP() + 10);
    }
    else if (index == 2) {
        player.restoreMana(3);
    }
}

