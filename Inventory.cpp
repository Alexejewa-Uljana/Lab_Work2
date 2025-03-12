#include "Inventory.h"
#include <iostream>

void Inventory::addArtifact(Artifact* artifact) {
    artifacts.push_back(artifact);
}

void Inventory::showInventory() {
    std::cout << "Artifacts:\n";
    for (Artifact* artifact : artifacts) {
        artifact->effect();
    }
}
