CXX = g++
CXXFLAGS = -std=c++20 -Iinclude

# Specify the directories
INCLUDE_DIR = include
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

# Define the target executable
TARGET = $(BUILD_DIR)/test


# check if src and test is defined
ifneq ($(MAKECMDGOALS), clean)
	ifeq ($(src),)
		$(error src variable is not defined. Please specify src=<src_filename> (e.g. src=linkedList or src=trees))
	endif
	ifeq ($(test),)
		$(error test variable is not defined. Please specify test=<test_filename> (e.g. test=linkedList_test or test=trees_test))
	endif
endif
# Define source files and object files
SRC_FILES = $(SRC_DIR)/$(src).cpp
TEST_FILES = $(TEST_DIR)/$(test).cpp
OBJS = $(SRC_FILES:.cpp=.o) $(TEST_FILES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# clean up build directory
clean:
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o $(TARGET)

.PHONY: all clean