#include "World.h"
#include <iostream>

World::World() : level(1) {}

void World::load() {
    std::cout << "Loading world...\n";
    std::cout << "Current level: " <<  level << ".\n";
}

int World::getLevel() const {
    return level;
}


