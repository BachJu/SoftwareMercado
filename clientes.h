#ifndef __CLIENTES_H__
#define __CLIENTES_H__
#include "data.h"

typedef struct Clientes
{
    char cpf[14];
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

/**
 * Preenche um vetor com as informações no arquivo "Clientes.csv", caso o arquivo exista
 * @param clientes Vetor de registros do tipo "Clientes" que será preenchida com as informações do arquivo "Clientes.csv"
*/
void preencheClientes(Clientes *clientes);

int atualizaCliente(Clientes *clientes, int qntC);

int atualizaPontos(Clientes *clientes, int qntC);

/**
 * Atualiza o arquivo "Clientes.csv" com as novas informações
 * @param lista Vetor de registros do tipo "Clientes" que será colocada no arquivo "Clientes.csv"
 * @param qntC Tamanho total do vetor
 * @param controle Recebe o valor "0" ou "1", caso for 1, então o arquivo será alterado
*/
void atualizaClientesCSV(Clientes *clientes, int qntC, int controle);

void idadeClientes(Clientes *clientes, int qntC);

void maisPontos(Clientes *clientes, int qntC);

#endif