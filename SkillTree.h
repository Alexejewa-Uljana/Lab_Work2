#ifndef SKILLTREE_H
#define SKILLTREE_H

#include <vector>

class SkillTree {
public:
    SkillTree();
    void unlockSkill(int skillID);

private:
    std::vector<bool> skills;
};

#endif

