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
SRCS             = $(wildcard $(SRC_DIR)/*.cpp)
OBJS             = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
SRC_OBJS_NO_MAIN = $(filter-out $(BUILD_DIR)/main.o,$(OBJS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.test.o)

# -----------------------------
# Règle par défaut
# -----------------------------
all: $(BUILD_DIR) $(EXEC)

$(BUILD_DIR):
    @mkdir -p $(BUILD_DIR)

# -----------------------------
# Compilation du programme principal
# -----------------------------
$(EXEC): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@


# -----------------------------
# Tests GoogleTest
# -----------------------------
tests: $(TEST_EXEC)
    @echo "✅ Tests compilés, exécution automatique :"
    ./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJS) $(SRC_OBJS_NO_MAIN)
    $(CXX) $(CXXFLAGS) -o $@ $^ -lgtest -lgtest_main -pthread

$(BUILD_DIR)/%.test.o: $(TEST_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) -I/usr/include -c $< -o $@


# -----------------------------
# Nettoyage
# -----------------------------
clean:
    rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.test.o $(EXEC) $(TEST_EXEC)
    @mkdir -p $(BUILD_DIR)

rebuild: clean all
