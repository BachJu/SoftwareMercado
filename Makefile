all: mercadoApp

mercadoApp: main.o telas.o produtos.o data.o clientes.o

	gcc -o mercadoApp main.o telas.o produtos.o data.o clientes.o -ggdb
main.o: main.c

	gcc -o main.o -c main.c -Wall -ggdb

telas.o: telas.c

	gcc -o telas.o -c telas.c -Wall -ggdb

produtos.o: produtos.c

	gcc -o produtos.o -c produtos.c -Wall -ggdb

data.o: data.c

	gcc -o data.o -c data.c -Wall -ggdb

clientes.o: clientes.c

	gcc -o clientes.o -c clientes.c -Wall -ggdb