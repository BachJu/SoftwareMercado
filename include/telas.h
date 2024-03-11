//Cria a função de todos os menus necessários
#ifndef __TELAS_H__
#define __TELAS_H__
#include "produtos.h"
#include "vendas.h"

/**
 * Fornece as primerias opções para o usuário
*/
int menuInicial();

/**
 * Apresenta as opções de venda para o usuário
*/
int menuVendas();

/**
 * Apresenta as opções cliente para o usuário
*/
int menuClientes();

/**
 * Apresenta as opções produto para o usuário
*/
int menuProdutos();

int menuAtualizaProd();

int menuAtualizaC();

/**
 * Limpa a tela
*/
void limparTela();

/**
 * Separador estético
*/
void separador();

void produtoInfos(Produtos *lista, int id);

void carrinho(Produtos *listaProdutos, ItensCompra *lista, int primeiroID, int ultimoId);

#endif