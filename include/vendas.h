#ifndef __VENDAS_H__
#define __VENDAS_H__
#include "data.h"

typedef struct ItensCompra
{
    int idVenda;
    char cpf[14];
    int idProd;
    int qnt;
    float unit;
    float total;
} ItensCompra;

typedef struct Vendas
{
    int idVenda;
    char cpf[14];
    Data data;
    double valorTotal;
    int qtdeProd;

} Vendas;

/**
 * Conta quantos itens o arquivo ItensCompras.csv tem
 * @return Inteiro com a quantidade de itens
*/
int contItensCSV();

/**
 * Conta quantas vendas o arquivo Vendas.csv
 * @return Inteiro com a quantidade de vendas
*/
int contVendasCSV();

/**
 * Preenche um vetor com as compras do arquivo ItensCompras.csv
 * @param compras Ponteiro para um vetor do tipo ItensCompras. ATENÇÃO: A memória deve ser previamente alocada para que o ponteiro tenha exatamente o espaço de memória necessário.
 * Use a função contItensCSV para receber a quantidade de espaço que deve ser alocado.
*/
void preencheCompras(ItensCompra *compras);

/**
 * Preenche um vetor com as compras do arquivo Vendas.csv
 * @param vendas Ponteiro para um vetor do tipo Vendas. ATENÇÃO: A memória deve ser previamente alocada para que o ponteiro tenha exatamente o espaço de memória necessário.
 * Use a função contVendasCSV para receber a quantidade de espaço que deve ser alocado.
*/
void preencheVendas(Vendas *vendas);

/**
 * Salva o arquivo Vendas.csv com os itens do vetor passado
 * @param vendas Ponteiro para um vetor de Vendas
 * @param qtdeVendas Quantidade de elementos no vetor, precisa ser exato ou pode causar problemas na memória
*/
void salvaVendas(Vendas *vendas, int qtdeVendas);

/**
 * Salva o arquivo ItensCompras.csv com os itens do vetor passado
 * @param compras Ponteiro para um vetor de ItensCompras
 * @param qtdeVendas Quantidade de elementos no vetor, precisa ser exato ou pode causar problemas na memória
*/
void salvaItens(ItensCompra *compras, int qtdeCompras);

/**
 * Adiciona mais um item a uma lista de ItensCompra
 * @param lista Ponteiro para um ponteiro para ItensCompra, passe simplesmente um ponteiro para ItensCompra como argumento como &lista
 * @param qtdeCompras Ponteiro para um intero com a quantidade de elementos em **lista, precisa ser exato ou pode causar problemas na memória
 * @param novoItem Elemento ItensCompra que deve ser adicionado ao final da lista
*/
void adicionaCompra(ItensCompra **lista, int *qtdeCompras, ItensCompra novoItem);

#endif