PROJECT = LABWORK2
LIBPROJECT = $(PROJECT).a
TESTPROJECT = test-$(PROJECT)

CXX = g++
AR = ar
ARFLAGS = rsv

CXXFLAGS = -Iinclude -std=c++17 -Wall -g -fPIC
LDFLAGS = $(CXXFLAGS) -L. -l:$(LIBPROJECT)
LDGTESTFLAGS = $(LDFLAGS) -lgtest -lgtest_main -lpthread

DEPS = $(wildcard include/*.h)

SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))

TEST_DIR = test
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ = $(addprefix obj/,$(notdir $(TEST_SRCS:.cpp=.o)))

MAIN_OBJ = obj/main.o

.PHONY: default all clean cleanall test

default: all

obj/:
	mkdir -p obj

obj/%.o: $(SRC_DIR)/%.cpp $(DEPS) | obj/
	$(CXX) -c -o $@ $< $(CXXFLAGS)

obj/%.o: $(TEST_DIR)/%.cpp $(DEPS) | obj/
	$(CXX) -c -o $@ $< $(CXXFLAGS)

obj/main.o: main.cpp $(DEPS) | obj/
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(LIBPROJECT): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(PROJECT): $(MAIN_OBJ) $(LIBPROJECT)
	$(CXX) -o $@ $(MAIN_OBJ) $(LDFLAGS)

test: $(TESTPROJECT)

$(TESTPROJECT): $(LIBPROJECT) $(TEST_OBJ)
	$(CXX) -o $@ $(TEST_OBJ) $(LDGTESTFLAGS)

all: $(PROJECT) test

clean:
	rm -rf obj
	rm -f *.o

cleanall: clean
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)
