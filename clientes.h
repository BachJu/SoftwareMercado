#ifndef __CLIENTES_H__
#define __CLIENTES_H__
#include "data.h"

typedef struct Clientes
{
    char cpf[13];
    Data nascimento;
    char nome[50];
    int idade;
    char endereco[100];
    char cidade[100];
    char estado[2];
    int pontos;
} Clientes;

void novoCliente(Clientes *novoC);

void arquivoCSVCliente(Clientes c);

 /**
  * Conta quantos clientes estão registrados no arquivo "Clientes.csv"
  * Caso arquivo não existir, retorna 0 como parâmetro
 */
int contClientesCSV();

#endif