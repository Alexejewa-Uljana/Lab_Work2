#include "BossAI.h"
#include "Player.h"
#include <iostream>

BossAI::BossAI(Boss& _boss): boss(_boss) {
    // Конструктор (можно инициализировать дополнительные параметры, если нужно)
}

BossAI::~BossAI() {
    // Деструктор
}

void BossAI::takeTurn(Boss& boss, Player& player) {
    if (boss.isStunned()) {
        std::cout << "Boss is stunned and cannot take action this turn." << std::endl;
        boss.setStunned(boss.getStunnedTurns() - 1);  // Уменьшаем количество ошеломленных ходов
        return;
    }

    // Вызов метода для принятия решения
    makeDecision(boss, player);
}

void BossAI::makeDecision(Boss& boss, Player& player) {
    int decision = rand() % 100;  // Рандомный выбор действия для примера

    // 1. Если здоровье игрока ниже 30%, босс пытается атаковать
    if (player.getHP() < player.getHP() * 0.3) {
        std::cout << "Player's health is low! Boss is preparing a powerful attack!" << std::endl;
        attack(boss, player);  // Босс использует атаку
    }
    // 2. Если здоровье босса ниже 30%, босс пытается защититься или лечиться
    else if (boss.getHP() < boss.getHP() * 0.3) {
        std::cout << "Boss' health is low! Boss is attempting to defend or heal!" << std::endl;
        if (decision < 50) {
            defend(boss);  // Защита
        } else {
            useSpecialAbility(boss, player);  // Использование способности для восстановления
        }
    }
    // 3. Если здоровье игрока высокое, босс использует свою специальную способность
    else if (player.getHP() > player.getHP() * 0.7) {
        std::cout << "Player's health is high! Boss uses special ability!" << std::endl;
        useSpecialAbility(boss, player);
    }
    // 4. В любом другом случае босс решает атаковать или кастовать заклинание
    else {
        if (decision < 50) {
            std::cout << "Boss decides to attack!" << std::endl;
            attack(boss, player);  // Атака
        } else {
            std::cout << "Boss decides to cast a spell!" << std::endl;
            castSpell(boss, player);  // Заклинание
        }
    }
}

void BossAI::attack(Boss& boss, Player& player) {
    int damage = 20 + rand() % 20;  // Босс наносит случайный урон
    boss.attack(player, damage);  // Вызов метода атаки из базового класса
}

void BossAI::castSpell(Boss& boss, Player& player) {
    int spellDamage = 30 + rand() % 20;  // Урон от заклинания, с небольшой случайной вариацией
    boss.castSpell(player, spellDamage);  // Вызов метода заклинания из базового класса
}

void BossAI::useSpecialAbility(Boss& boss, Player& player) {
    // Пример логики использования специальной способности
    if (rand() % 2 == 0) {
        std::cout << "Boss uses healing special ability!" << std::endl;
        boss.castSpell(player, -20);  // Босс лечится, используя способность, которая восстанавливает здоровье
    } else {
        std::cout << "Boss uses damage special ability!" << std::endl;
        boss.attack(player, 50);  // Босс использует мощную атаку
    }
}

void BossAI::defend(Boss& boss) {
    std::cout << "Boss defends this turn, reducing damage taken!" << std::endl;
    // Логика защиты, например, увеличение защиты на несколько ходов
    // Это может быть реализовано через увеличение защищенности или временное снижение урона
}


