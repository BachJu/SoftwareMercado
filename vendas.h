#ifndef __VENDAS_H__
#define __VENDAS_H__
#include "clientes.h"

typedef struct Vendas
{
    char cpf[14];
    int id;

} Vendas;

typedef struct ItensCompra
{
    int idVenda;
    char cpf[14];
    int idProd;
    int qnt;
    float unit;
    float total;
} ItensCompra;

int contItensCSV();

void preencheCompras(ItensCompra *compras);

/*
    Inicia o cadastro de uma nova venda
*/
void novaVenda(Vendas *novoV);






#endif