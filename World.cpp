#include "World.h"
#include <iostream>

World::World() : level(1) {}

void World::load() {
    std::cout << "World loaded, level: " << level << std::endl;
}

