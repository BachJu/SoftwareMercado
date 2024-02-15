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
 * Preenche o vetor "lista" (ver main.c) com o novo produto
 * @param lista Passa por referência o vetor com o mesmo nome
 * @param p Variável do tipo "Produtos" que foi preenchida pelo usuário
 * @param fim Variável que aponta para o final do vetor "lista"
*/
void novoProdutoVetor(Produtos *lista, Produtos p,int fim);

void preencheLista(Produtos *lista);

#endif