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

.PHONY: all clean distclean doxy

all: dir questao01 questao02

# Cria os diretórios necessários
dir:
	mkdir -p bin build

# Opção para depurar (só a questão 03)
debug: CPPFLAGS += -g -O0
debug: questao01 questao02

####	Questão 01		####
questao01: $(OBJ_DIR)/main1.o $(OBJ_DIR)/company.o $(OBJ_DIR)/employee.o $(OBJ_DIR)/date.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel questao01 criado em $(BIN_DIR)] +++"
	@echo "============="

## Arquivos objeto
$(OBJ_DIR)/main1.o: $(SRC_DIR)/questao01/main1.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

$(OBJ_DIR)/company.o: $(SRC_DIR)/questao01/company.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

$(OBJ_DIR)/employee.o: $(SRC_DIR)/questao01/employee.cpp 
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

$(OBJ_DIR)/date.o: $(SRC_DIR)/questao01/date.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

####	Questão 02		####
questao02: $(OBJ_DIR)/main2.o $(OBJ_DIR)/dado.o $(OBJ_DIR)/player.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel questao02 criado em $(BIN_DIR)] +++"
	@echo "============="
$(OBJ_DIR)/main2.o: $(SRC_DIR)/questao02/main2.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao02 -o $@ $<
$(OBJ_DIR)/dado.o: $(SRC_DIR)/questao02/dado.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao02 -o $@ $<
$(OBJ_DIR)/player.o: $(SRC_DIR)/questao02/player.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao02 -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Limpar os arquivos objetos e executáveis
clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
