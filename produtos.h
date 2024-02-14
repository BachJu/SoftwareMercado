#ifndef __PRODUTOS_H__
#define __PRODUTOS_H__
#include "data.h"

typedef struct Produtos
{
    int id;
    char setor[20];
    char nomeProd[50];
    double preco;
    Data validade;
    int estoque;
} Produtos;

/**
 * Cadastra um novo produto
 * @param novoP Passa por referência uma variável do tipo "Produtos"
*/
void novoProduto(Produtos *novoP);


/**
 * Cria ou atualiza um arquivo tipo CSV
 * @param p Registro do tipo "Produtos" que será arquivada
 * @param qntP Atualiza a quantidade de produtos regitrados no arquivo
*/
int arquivoCSV(Produtos p, int *qntP);
 
int contProdutosCSV();

#endif