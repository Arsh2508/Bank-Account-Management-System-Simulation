CXX := g++
CXXFLAGS := -I../include 

SRC_DIR := ../src
OBJ_DIR := ../obj
BUILD_DIR := .
TEST_DIR := ../googletests

MAIN_EXE := $(BUILD_DIR)/bankapp
TEST_EXE := $(BUILD_DIR)/runtests

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES)))
MAIN_OBJ := $(OBJ_DIR)/main.o
TEST_OBJ := $(OBJ_DIR)/test.o

GTEST_FLAGS := -lgtest -lgtest_main -pthread

.PHONY: all tests clean

all: $(MAIN_EXE)

$(MAIN_EXE): $(OBJ_FILES) $(MAIN_OBJ) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

tests: $(TEST_EXE)

$(TEST_EXE): $(OBJ_FILES) $(TEST_OBJ) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/test.o: $(TEST_DIR)/test.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(BUILD_DIR)/bankapp $(BUILD_DIR)/runtests
