all: mercadoApp

mercadoApp: main.o telas.o produtos.o

	gcc -o mercadoApp main.o telas.o produtos.o -ggdb

main.o: main.c

	gcc -o main.o -c main.c -Wall -ggdb

telas.o: telas.c

	gcc -o telas.o -c telas.c -Wall -ggdb

produtos.o: produtos.c

	gcc -o produtos.o -c produtos.c -Wall -ggdb