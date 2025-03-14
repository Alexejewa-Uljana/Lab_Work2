#include "Boss.h"
#include "Player.h"
#include <iostream>

Boss::Boss() : Enemy("Boss", 100) {
    // Инициализация для босса, если необходимо
}

Boss::Boss(const std::string& _name, int _hp) : Enemy(_name, _hp) {
    // Инициализация для босса с заданным именем и HP
}

void Boss::useSpecialAbility(Player& player) {
    // Например, босс может применить мощную атаку или заклинание
    std::cout << "Boss is using special ability on you!" << std::endl;
    attack(player, 50);  // Босс атакует с уроном 50
}

void Boss::takeTurn(Player& player) {
    // Логика хода босса
    if (isStunned()) {
        std::cout << "Boss is stunned and cannot take action this turn." << std::endl;
        setStunned(getStunnedTurns() - 1);  // Уменьшаем количество ходов для ошеломления
        return;
    }

    // Включаем логику принятия хода
    int actionChoice = rand() % 3;  // Рандомный выбор действия (для примера)

    if (actionChoice == 0) {
        std::cout << "Boss attacks!" << std::endl;
        attack(player, 20);  // Простой атака
    } else if (actionChoice == 1) {
        std::cout << "Boss casts a spell!" << std::endl;
        castSpell(player, 30);  // Босс кастует заклинание
    } else {
        std::cout << "Boss uses special ability!" << std::endl;
        useSpecialAbility(player);  // Использует специальную способность
    }
}

void Boss::attack(Player& player, int damage) {
    std::cout << "Boss attacks you" << " for " << damage << " damage!" << std::endl;
    player.takeDamage(damage);  // Наносим урон игроку
}

void Boss::castSpell(Player& player, int spellDamage) {
    std::cout << "Boss casts a spell on you dealing " << spellDamage << " damage!" << std::endl;
    player.takeDamage(spellDamage);  // Наносим урон через заклинание
}
