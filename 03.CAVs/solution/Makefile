# DIRETORIOS
SRC_DIR = src
OBJ_DIR = build
INC_DIR = include
BIN_DIR = bin

# NOME DOS EXECUTAVEIS
PROGRAM_NAME = program
TEST_NAME = test

# CONFIGURAÇÕES DO COMPILADOR
CC = g++
LIBS = -lm
CFLAGS = --std=c++20 -O0 -Wall

# ARQUIVOS
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
PROGRAM_OBJS = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SOURCES))

# CASES
build: $(OBJ_DIR)/$(PROGRAM_NAME)

run: build
	$(BIN_DIR)/$(PROGRAM_NAME)

$(OBJ_DIR)/$(PROGRAM_NAME): $(OBJ_DIR)/$(PROGRAM_OBJS)
	$(CC) $(CFLAGS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

clean:
	rm -f $(BIN_DIR)/* $(OBJ_DIR)/* gmon.out
