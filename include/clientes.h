#ifndef __VENDAS_H__
#include "vendas.h"
#endif
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

/**
 * Atualiza a pontuação dos clientes
 * @param clientes vetor de "Clientes" para atualizar a pontuação no arquivo csv
 * @param qntC verifica o tamanho do vetor clientes
 * @param compras vetor de "Compras" para passar o valor total da venda
 * @param qntItens verifica o tamanho do vetor compras
*/
int atualizaPontos(Clientes *clientes, int qntC, Vendas *compras, int qntItens);

/**
 * Cadastra um novo cliente
 * @param novoC uma variável do tipo "Clientes" para ser preeenchida
*/
void novoCliente(Clientes *novoC);

/**
 * Atualiza o arquivo CSV
 * @param c uma variável do tipo "Clientes" para preencher o arquivo
*/
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

/**
 * Atualiza o vetor de clientes caso usuário queira fazer alguma atualização
 * @param clientes um vetor do tipo "Clientes" que será alterado
 * @param qntC tamanho máximo do vetor
*/
int atualizaCliente(Clientes *clientes, int qntC);

/**
 * Atualiza o arquivo "Clientes.csv" com as novas informações
 * @param clientes Vetor de registros do tipo "Clientes" que será colocada no arquivo "Clientes.csv"
 * @param qntC Tamanho total do vetor
 * @param controle Recebe o valor "0" ou "1", caso for 1, então o arquivo será alterado
*/
void atualizaClientesCSV(Clientes *clientes, int qntC, int controle);

/**
 * Mostra clientes entre 18 e 25 anos
 * @param clientes Vetor de registros do tipo "Clientes" que mostrará as informações
 * @param intC Tamanho total do vetor
*/
void idadeClientes(Clientes *clientes, int qntC);

/**
 * Mostra clientes que tem mais de 1000 pontos
 * @param clientes Vetor de registros do tipo "Clientes" que mostrará as informações
 * @param intC Tamanho total do vetor
*/
void maisPontos(Clientes *clientes, int qntC);

#endif