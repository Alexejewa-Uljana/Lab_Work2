#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "Player.h"
#include <vector>
#include <string>

class Artifact {
public:
    Artifact();
    void grantArtifact(Player& player);

private:
    std::vector<std::string> artifacts;
};

#endif // ARTIFACT_H

