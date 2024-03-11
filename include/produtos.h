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
 * @param lista Passa 
*/
void novoProduto(Produtos *novoP, int idProd);


/**
 * Cria ou atualiza um arquivo tipo CSV
 * @param p Registro do tipo "Produtos" que será arquivada
*/
void arquivoCSV(Produtos p);
 
 /**
  * Conta quantos produtos estão registrados no arquivo "Produtos.csv"
  * Caso arquivo não existir, retorna 0 como parâmetro
 */
int contProdutosCSV();

/**
 * Preenche um vetor com as informações no arquivo "Produtos.csv", caso o arquivo exista
 * @param lista Vetor de registros do tipo "Produtos" que será preenchida com as informações do arquivo "Produtos.csv"
*/
void preencheLista(Produtos *lista);

/**
 * Atualiza o produto desejado e retorna "1" ou "0"
 * @param lista Vetor de registros do tipo "Produtos" que será feita busca pelo produto que será alterado
 * @param qntProd Tamando total do vetor para que a busca seja feita até seu tamanho máximo
*/
int atualizaProdutos(Produtos *lista, int qntProd);

/**
 * Atualiza o arquivo "Produtos.csv" com as novas informações
 * @param lista Vetor de registros do tipo "Produto" que será colocada no arquivo "Produtos.csv"
 * @param qntProd Tamanho total do vetor
 * @param controle Recebe o valor "0" ou "1", caso for 1, então o arquivo será alterado
*/
void atualizaArquivoCSV(Produtos *lista, int qntProd, int controle);

/**
 * Mostra ao usuário produtos por setor
 * @param lista Vetor de registros do tipo "Produto"
 * @param qntProd Tamanho total do vetor
*/
void prodPorSetor(Produtos *lista, int qntProd);

/**
 * Mostra ao usuário produtos que tem estoque igual ou menor que 5
 * @param lista Vetor de registros do tipo "Produto"
 * @param qntProd Tamanho total do vetor
*/
void baixoEstoque(Produtos *lista, int qntProd);

#endif