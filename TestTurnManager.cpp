#include "gtest/gtest.h"
#include "TurnManager.h"
#include "Player.h"
#include "Enemy.h"
#include "BattleSystem.h"

TEST(TurnManager, playerTurn)
{
    Player player;
    Enemy enemy("Goblin", 100);
    BattleSystem battleSystem(1);
    TurnManager turnManager(player, enemy, battleSystem);
    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf());
    turnManager.playerTurn();
    EXPECT_TRUE(output.str().find("It's your turn!") != std::string::npos);
    std::cout.rdbuf(originalCout);
}

TEST(TurnManager, enemyTurn)
{
    Player player;
    Enemy enemy("Goblin", 100);
    BattleSystem battleSystem(1);
    TurnManager turnManager(player, enemy, battleSystem);
    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf());
    turnManager.enemyTurn();
    EXPECT_TRUE(output.str().find("Goblin's turn.") != std::string::npos);
    std::cout.rdbuf(originalCout);
}

TEST(TurnManager, startBattle)
{
    Player player;
    Enemy enemy("Goblin", 100);
    BattleSystem battleSystem(1);
    TurnManager turnManager(player, enemy, battleSystem);
    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf());
    turnManager.startBattle();
    EXPECT_TRUE(output.str().find("You win!") != std::string::npos);
    std::cout.rdbuf(originalCout);
}



