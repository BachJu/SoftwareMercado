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

int contItensCSV();

int contVendasCSV();

void preencheCompras(ItensCompra *compras);

void preencheVendas(Vendas *vendas);

void novaVenda();

void salvaVendas(Vendas *vendas, int qtdeVendas);

void salvaItens(ItensCompra *compras, int qtdeCompras);

void adicionaCompra(ItensCompra **lista, int *qtdeCompras, ItensCompra novoItem);

void mostrarCompras();

#endif