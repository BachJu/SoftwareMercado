//Cria a função de todos os menus necessários
#ifndef __TELAS_H__
#define __TELAS_H__
#include "produtos.h"
#include "vendas.h"

/**
 * Fornece as primeiras opções para o usuário
*/
int menuInicial();

/**
 * Apresenta as opções de venda para o usuário
*/
int menuVendas();

/**
 * Apresenta as opções de cliente para o usuário
*/
int menuClientes();

/**
 * Apresenta as opções de produto para o usuário
*/
int menuProdutos();

/**
 * Abre o menu de atualização de produtos
*/
int menuAtualizaProd();

/**
 * Abre o menu de atualização de cliente
*/
int menuAtualizaC();

/**
 * Limpa a tela
*/
void limparTela();

/**
 * Separador estético
*/
void separador();

char tema; //Controla o tema do separador

/**
 * Exibe nome, preço e quantidade em estoque de um produto
 * @param lista Ponteiro para um vetor de Produtos
 * @param id Id do produto que deseja exibir as informações
*/
void produtoInfos(Produtos *lista, int id);

/**
 * Exibe o carrinho atual
 * @param listaProdutos Ponteiro para o vetor de todos os produtos
 * @param lista Ponteiro para a lista de ItensCompra (inclusive os que ainda não foram salvos)
 * @param primeiroID Index do primeiro elemento de lista de compras que representa a compra atual
 * @param ultimoId Quantidade de elementos na lista de compras (ou index do ultimo elemento + 1)
*/
void carrinho(Produtos *listaProdutos, ItensCompra *lista, int primeiroID, int ultimoId);

/**
 * Abre o menu de nova venda
*/
void novaVenda();

/**
 * Abre o menu para ver as compras de um cliente
*/
void mostrarCompras();

#endif