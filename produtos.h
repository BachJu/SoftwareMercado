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
*/
void arquivoCSV(Produtos p);
 
 /**
  * Conta quantos prodtuos estão registrados no arquivo "Produtos.csv"
  * Caso arquivo não existir, retorna 0 como parâmetro
 */
int contProdutosCSV();

/**
 * Preenche um vetor com as informações no arquivo "Produtos.csv", caso o arquivo exista
 * @param lista Vetor de registros do tipo "Produtos" que será preenchida com as informações do arquivo "Produtos.csv"
*/
void preencheLista(Produtos *lista);

void atualizaProdutos(Produtos *lista, int qntProd);

#endif