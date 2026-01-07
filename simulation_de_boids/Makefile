# -----------------------------
# Variables
# -----------------------------
EXEC       = programme
TEST_EXEC  = tests_bin

SRC_DIR    = src
TEST_DIR   = test
BUILD_DIR  = build

CXX        = g++
CXXFLAGS   = -Wall -Wextra -std=c++17 -g

# Librairies SFML
SFML_LIBS  = -lsfml-graphics -lsfml-window -lsfml-system

# -----------------------------
# Fichiers sources et objets
# -----------------------------
SRCS = \
    $(wildcard $(SRC_DIR)/*.cpp) \
    $(wildcard $(SRC_DIR)/view/*.cpp) \
    $(wildcard $(SRC_DIR)/model/*.cpp) \
    $(wildcard $(SRC_DIR)/model/simulation/*.cpp) \
    $(wildcard $(SRC_DIR)/model/rules/*.cpp) \
    $(wildcard $(SRC_DIR)/controller/*.cpp)

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

SRC_OBJS_NO_MAIN = $(filter-out $(BUILD_DIR)/src/main.o,$(OBJS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:%.cpp=$(BUILD_DIR)/%.test.o)

# -----------------------------
# Règle par défaut
# -----------------------------
all: $(BUILD_DIR) $(EXEC)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/src
	@mkdir -p $(BUILD_DIR)/src/view
	@mkdir -p $(BUILD_DIR)/src/model
	@mkdir -p $(BUILD_DIR)/src/model/simulation
	@mkdir -p $(BUILD_DIR)/src/model/rules
	@mkdir -p $(BUILD_DIR)/src/controller

# -----------------------------
# Compilation du programme principal
# -----------------------------
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# -----------------------------
# Tests GoogleTest
# -----------------------------
tests: $(TEST_EXEC)
	@echo "✅ Tests compilés, exécution automatique :"
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJS) $(SRC_OBJS_NO_MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lgtest -lgtest_main -pthread

$(BUILD_DIR)/%.test.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I/usr/include -c $< -o $@

# -----------------------------
# Nettoyage
# -----------------------------
clean:
	rm -rf $(BUILD_DIR) $(EXEC) $(TEST_EXEC)

rebuild: clean all
