#include "../include/telas.h"
#include "../include/clientes.h"
#include "../include/data.h"
#include "../include/vendas.h"
#include "../include/produtos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int contItensCSV()
{
    FILE *arq;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    int contadorLinha = 0;
    arq = fopen("planilhas/ItensCompras.csv", "r");
    if (arq != NULL)
    {
        // fim dos registros, reabrindo para ler os dados
        fseek(arq, 0, SEEK_SET);
        // lendo o cabeçalho do arquivo
        fscanf(arq, " %[^\n]s", linha);
        // alocando memoria para os registros lidos

        int i = 0;
        while (fscanf(arq, " %[^\n]s", linha) != EOF)
        {
            // separando os dados de uma linha
            campos = strtok(linha, s);
            while (campos != NULL)
            {
                campos = strtok(NULL, s);
            }
            i++;
            // dados do setor;
        }
        contadorLinha = i;
        fclose(arq);
    }
    return contadorLinha;
}

void preencheCompras(ItensCompra *compras)
{
    FILE *csv;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    csv = fopen("planilhas/ItensCompras.csv", "r");
    if (csv != NULL)
    {
        // fim dos registros, reabrindo para ler os dados
        fseek(csv, 0, SEEK_SET);
        // lendo o cabeçalho do arquivo
        fscanf(csv, " %[^\n]s", linha);
        // alocando memoria para os registros lidos

        int i = 0;
        while (fscanf(csv, " %[^\n]s", linha) != EOF)
        {
            // separando os dados de uma linha
            campos = strtok(linha, s);
            int campoAtual = 0;
            while (campos != NULL)
            {
                switch (campoAtual)
                {
                case 0:
                    compras[i].idVenda = atoi(campos);
                    break;
                case 1:
                    strcpy(compras[i].cpf, campos);
                    break;
                case 2:
                    compras[i].idProd = atoi(campos);
                    break;
                case 3:
                    compras[i].qnt = atoi(campos);
                    break;
                case 4:
                    compras[i].unit = atof(campos);
                    break;
                case 5:
                    compras[i].total = atof(campos);
                    break;
                default:
                    break;
                }
                campos = strtok(NULL, s);

                campoAtual++;
            }
            i++;
            // dados do setor;
        }
    }
}

int contVendasCSV()
{
    FILE *arq;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    int contadorLinha = 0;
    arq = fopen("planilhas/Vendas.csv", "r");
    if (arq != NULL)
    {
        // fim dos registros, reabrindo para ler os dados
        fseek(arq, 0, SEEK_SET);
        // lendo o cabeçalho do arquivo
        fscanf(arq, " %[^\n]s", linha);
        // alocando memoria para os registros lidos

        int i = 0;
        while (fscanf(arq, " %[^\n]s", linha) != EOF)
        {
            // separando os dados de uma linha
            campos = strtok(linha, s);
            while (campos != NULL)
            {
                campos = strtok(NULL, s);
            }
            i++;
            // dados do setor;
        }
        contadorLinha = i;
        fclose(arq);
    }
    return contadorLinha;
}

void preencheVendas(Vendas *vendas)
{
    FILE *csv;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    csv = fopen("planilhas/Vendas.csv", "r");
    if (csv != NULL)
    {
        // fim dos registros, reabrindo para ler os dados
        fseek(csv, 0, SEEK_SET);
        // lendo o cabeçalho do arquivo
        fscanf(csv, " %[^\n]s", linha);
        // alocando memoria para os registros lidos

        int i = 0;
        while (fscanf(csv, " %[^\n]s", linha) != EOF)
        {
            // separando os dados de uma linha
            campos = strtok(linha, s);
            int campoAtual = 0;
            while (campos != NULL)
            {
                switch (campoAtual)
                {
                case 0:
                    vendas[i].idVenda = atoi(campos);
                    break;
                case 1:
                    strcpy(vendas[i].cpf, campos);
                    break;
                case 2:
                    stringParaData(campos, &vendas[i].data);
                    break;
                case 3:
                    vendas[i].valorTotal = atof(campos);
                    break;
                case 4:
                    vendas[i].qtdeProd = atoi(campos);
                    break;
                default:
                    break;
                }
                campos = strtok(NULL, s);
                campoAtual++;
            }
            i++;
            // dados do setor;
        }
    }
}

void salvaVendas(Vendas *lista, int qntVendas)
{
    FILE *arquivoCSV;
    arquivoCSV = fopen("planilhas/Vendas.csv", "w");
    fprintf(arquivoCSV, "Id;CPF;Data da Compra;Valor Total;Itens\n");

    for (int i = 0; i < qntVendas; i++)
    {
        fprintf(arquivoCSV, "%d;%s;%d/%d/%d;%.2lf;%d\n", lista[i].idVenda, lista[i].cpf, lista[i].data.dia, lista[i].data.mes, lista[i].data.ano, lista[i].valorTotal, lista[i].qtdeProd);
    }

    fclose(arquivoCSV);
}

void salvaItens(ItensCompra *lista, int qntItensCompra)
{
    FILE *arquivoCSV;
    arquivoCSV = fopen("planilhas/ItensCompras.csv", "w");
    fprintf(arquivoCSV, "IdVenda;CPF;IdProduto;Quantidade;Unitario;Total\n");

    for (int i = 0; i < qntItensCompra; i++)
    {
        fprintf(arquivoCSV, "%d;%s;%d;%d;%.2f;%.2f\n", lista[i].idVenda, lista[i].cpf, lista[i].idProd, lista[i].qnt, lista[i].unit, lista[i].total);
    }

    fclose(arquivoCSV);
}

void adicionaCompra(ItensCompra **lista, int *qtdeCompras, ItensCompra novoItem)
{
    ItensCompra *novoPonteiro = (ItensCompra *)realloc(*lista, sizeof(ItensCompra) * (*qtdeCompras + 1));

    if (novoPonteiro != NULL)
    {
        *lista = novoPonteiro;
        (*lista)[*qtdeCompras] = novoItem;
        *qtdeCompras += 1;
    }
    else
    {
        while (true)
        {
            printf("Erro na realocacao de memoria\n");
        }
    }
}