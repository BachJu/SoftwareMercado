#include "telas.h"
#include "clientes.h"
#include "data.h"
#include "vendas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int contItensCSV(){
    FILE *arq;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    int contadorLinha = 0;
    arq = fopen("ItensCompras.csv", "r");
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

void preencheCompras(ItensCompra *compras){
    FILE *csv;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    csv = fopen("ItensCompras.csv", "r");
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

void novaVenda(Vendas *novoV)
{
    printf("Digite seu CPF:\n");
    scanf("%[^\n]s", novoV->cpf);
    
}