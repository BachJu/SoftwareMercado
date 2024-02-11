#ifndef __PRODUTOS_H__
#define __PRODUTOS_H__
#include "data.h"

typedef struct Produtos
{
    int identificador;
    char setor[20];
    char nomeProd[50];
    double preco;
    Data validade;
    int estoque;
} Produtos;

/**
 * Cadastra um novo produto
*/
void novoProduto();

#endif