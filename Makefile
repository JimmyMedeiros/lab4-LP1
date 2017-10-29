.PHONY: all clean distclean doxy

all: dir programa01 programa02

CC = g++
CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -pg
RM = rm -rf

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

# Cria os diretórios necessários
dir:
	mkdir -p bin build

# Opção para depurar (só a questão 03)
debug: CPPFLAGS += -g -O0
debug: programa01 programa02 programa03

####	Programa 01		####
programa01: $(OBJ_DIR)/main1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -I$(INC_DIR) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel programa01 criado em $(BIN_DIR)] +++"
	@echo "============="

## Arquivos objeto
$(OBJ_DIR)/main1.o: $(SRC_DIR)/programa01/main1.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR) -o $@ $<

####	Programa 02		####
programa02: $(OBJ_DIR)/main2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel programa02 criado em $(BIN_DIR)] +++"
	@echo "============="
$(OBJ_DIR)/main2.o: $(SRC_DIR)/programa02/main2.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/ -o $@ $<

####	Programa 03		####
programa03: $(OBJ_DIR)/main3.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="
$(OBJ_DIR)/main3.o: $(SRC_DIR)/programa03/main3.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/ -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Limpar os arquivos objetos e executáveis
clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
