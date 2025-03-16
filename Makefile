PROJECT = LABWORK2

LIBPROJECT = $(PROJECT).a

TESTPROJECT = test-$(PROJECT)

CXX = g++

A = ar

AFLAGS = rsv

CCXFLAGS = -I. -std=c++17 -Wall -g -fPIC

LDXXFLAGS = $(CCXFLAGS) -L. -l:$(LIBPROJECT)

LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -lpthread

DEPS=$(wildcard *.h)

OBJ= Artifact.o AttackCard.o DefenseCard.o MagicCard.o Card.o Game.o main.o AIController.o BattleSystem.o Boss.o BossAI.o Deck.o Effect.o Enemy.o EnemyDeck.o ManaSystem.o Player.o RewardSystem.o StoryManager.o World.o TurnManager.o StatusEffectCard.o SpecialCard.o

TEST-OBJ=Test.o TestPlayer.o TestAttackCard.o TestMagicCard.o TestDefenseCard.o TestStatusEffectCard.o TestSpecialCard.o TestDeck.o TestEnemyDeck.o TestBoss.o TestStoryManager.o TestEnemy.o TestWorld.o TestArtifact.o TestRewardSystem.o TestManaSystem.o TestEffect.o TestBossAI.o TestAIController.o


.PHONY: default

default: all;

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^

$(PROJECT): main.o $(LIBPROJECT)
	$(CXX) -o $@ main.o $(LDXXFLAGS)

test: $(TESTPROJECT)

$(TESTPROJECT): $(LIBPROJECT) $(TEST-OBJ)
	$(CXX) -o $@ $(TEST-OBJ) $(LDGTESTFLAGS)

all: $(PROJECT) test

.PHONY: clean

clean:
	rm -f *.o

cleanall: clean
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)
