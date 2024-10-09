# Variables
CC = g++
CFLAGS = -Wall -g
BUILD_DIR = build
ENGINE_DIR = Engine
GAME_DIR = Game
ENGINE_INCLUDE_DIR = $(ENGINE_DIR)/include
ENGINE_SRC_DIR = $(ENGINE_DIR)/src
GAME_INCLUDE_DIR = $(GAME_DIR)/include
GAME_SRC_DIR = $(GAME_DIR)/src

# Directories for object files
ENGINE_OBJ_DIR = $(BUILD_DIR)/Engine
GAME_OBJ_DIR = $(BUILD_DIR)/Game

# Source files and object files
ENGINE_SRC = $(shell find $(ENGINE_SRC_DIR) -name '*.cpp')
GAME_SRC = $(shell find $(GAME_SRC_DIR) -name '*.cpp')
ENGINE_OBJ = $(patsubst $(ENGINE_SRC_DIR)/%.cpp,$(ENGINE_OBJ_DIR)/%.o,$(ENGINE_SRC))
GAME_OBJ = $(patsubst $(GAME_SRC_DIR)/%.cpp,$(GAME_OBJ_DIR)/%.o,$(GAME_SRC))

# Create the build directories if they don't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/Engine $(BUILD_DIR)/Game

# Default target
all: $(BUILD_DIR) $(ENGINE_OBJ_DIR) $(GAME_OBJ_DIR) $(BUILD_DIR)/myprogram

# Build the executable
$(BUILD_DIR)/myprogram: $(ENGINE_OBJ) $(GAME_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Build object files for Engine
$(ENGINE_OBJ_DIR)/%.o: $(ENGINE_SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(ENGINE_INCLUDE_DIR) -c $< -o $@

# Build object files for Game
$(GAME_OBJ_DIR)/%.o: $(GAME_SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(GAME_INCLUDE_DIR) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean
