#ifndef WORLD_H
#define WORLD_H

#include <iostream>

class World {
public:
    World();
    void load();
    int getLevel() const;

private:
    int level;
};

#endif
