#ifndef MANASYSTEM_H
#define MANASYSTEM_H

class ManaSystem {
public:
    ManaSystem();
    void useMana(int amount);
    void restoreMana(int amount);
    int getMana() const;

private:
    int mana;
};

#endif
