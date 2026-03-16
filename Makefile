SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE_DIR := include
EXEC := main

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# CFLAGS: Apenas para COMPILAÇÃO (Headers)
CXXFLAGS := -I$(INCLUDE_DIR) -Wall -g

all: $(BIN_DIR)/$(EXEC)

# 1. REGRA DE LINKAGEM (Cria o executável final)
$(BIN_DIR)/$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	g++ $(OBJS) -o $@

# Regra de Compilação
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC)

