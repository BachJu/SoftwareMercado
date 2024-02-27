#ifndef __VENDAS_H__
#define __VENDAS_H__
#include "clientes.h"

typedef struct Vendas
{
    char cpf[14];
    int id;

} Vendas;

/*
    Inicia o cadastro de uma nova venda
*/
void novaVenda(Vendas, *novoV);






#endif