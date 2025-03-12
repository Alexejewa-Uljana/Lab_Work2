#ifndef INVENTORY_H
#define INVENTORY_H

#include "Artifact.h"
#include <vector>

class Inventory {
public:
    void addArtifact(Artifact* artifact);
    void showInventory();

private:
    std::vector<Artifact*> artifacts;
};

#endif
