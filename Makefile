ifeq ($(OS),Windows_NT)
	RM = del /Q /F
	MKDIR = if not exist $(BIN_DIR) mkdir
else
	RM = rm -f
	MKDIR = mkdir -p
	LINUX_DELETE = /*.o
endif

BIN_DIR = bin

all: mercadoApp

mercadoApp: main.o telas.o produtos.o data.o clientes.o vendas.o
	gcc -o mercadoApp $(BIN_DIR)/main.o $(BIN_DIR)/telas.o $(BIN_DIR)/produtos.o $(BIN_DIR)/data.o $(BIN_DIR)/clientes.o $(BIN_DIR)/vendas.o -ggdb

main.o: src/main.c
	$(MKDIR) $(BIN_DIR)
	gcc -o $(BIN_DIR)/main.o -c src/main.c -Wall -ggdb

telas.o: src/telas.c
	$(MKDIR) $(BIN_DIR)
	gcc -o $(BIN_DIR)/telas.o -c src/telas.c -Wall -ggdb

produtos.o: src/produtos.c
	$(MKDIR) $(BIN_DIR)
	gcc -o $(BIN_DIR)/produtos.o -c src/produtos.c -Wall -ggdb

data.o: src/data.c
	$(MKDIR) $(BIN_DIR)
	gcc -o $(BIN_DIR)/data.o -c src/data.c -Wall -ggdb

clientes.o: src/clientes.c
	$(MKDIR) $(BIN_DIR)
	gcc -o $(BIN_DIR)/clientes.o -c src/clientes.c -Wall -ggdb

vendas.o: src/vendas.c
	$(MKDIR) $(BIN_DIR)
	gcc -o $(BIN_DIR)/vendas.o -c src/vendas.c -Wall -ggdb

clean:
	$(RM) mercadoApp$(EXT)
	$(RM) $(BIN_DIR)$(LINUX_DELETE)