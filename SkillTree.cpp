#include "SkillTree.h"
#include <iostream>

SkillTree::SkillTree() : skills(10, false) {}

void SkillTree::unlockSkill(int skillID) {
    if (skillID >= 0 && skillID < skills.size()) {
        skills[skillID] = true;
        std::cout << "Skill " << skillID << " unlocked!" << std::endl;
    }
}
