#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <string>

class Artifact {
public:
    virtual void effect() = 0;
};

class HealingArtifact : public Artifact {
public:
    void effect() override;
};

#endif
