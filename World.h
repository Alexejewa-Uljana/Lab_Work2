#ifndef WORLD_H
#define WORLD_H

#include <iostream>

class World {
public:
    World();
    ~World() = default;
    void load();
    int getLevel() const;

private:
    int level;
};

#endif
