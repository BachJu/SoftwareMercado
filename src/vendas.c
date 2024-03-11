#include "../include/telas.h"
#include "../include/clientes.h"
#include "../include/data.h"
#include "../include/vendas.h"
#include "../include/produtos.h"
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

void preencheCompras(ItensCompra *compras){
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

int contVendasCSV(){
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

void preencheVendas(Vendas *vendas) {
    FILE *csv;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    csv = fopen("planilhas/Vendas.csv", "r");
    if (csv != NULL) {
        // fim dos registros, reabrindo para ler os dados
        fseek(csv, 0, SEEK_SET);
        // lendo o cabeçalho do arquivo
        fscanf(csv, " %[^\n]s", linha);
        // alocando memoria para os registros lidos

        int i = 0;
        while (fscanf(csv, " %[^\n]s", linha) != EOF) {
            // separando os dados de uma linha
            campos = strtok(linha, s);
            int campoAtual = 0;
            while (campos != NULL) {
                switch (campoAtual) {
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

void salvaVendas(Vendas *lista, int qntVendas){
    FILE *arquivoCSV;
    arquivoCSV = fopen("planilhas/Vendas.csv", "w");
    fprintf(arquivoCSV, "Id;CPF;Data da Compra;Valor Total;Itens\n");
    
    for (int i = 0; i < qntVendas; i++)
    {
        fprintf(arquivoCSV, "%d;%s;%d/%d/%d;%.2lf;%d\n", lista[i].idVenda, lista[i].cpf, lista[i].data.dia, lista[i].data.mes, lista[i].data.ano, lista[i].valorTotal, lista[i].qtdeProd);
    }

    fclose(arquivoCSV);
}

void salvaItens(ItensCompra *lista, int qntItensCompra){
    FILE *arquivoCSV;
    arquivoCSV = fopen("planilhas/ItensCompras.csv", "w");
    fprintf(arquivoCSV, "IdVenda;CPF;IdProduto;Quantidade;Unitario;Total\n");
    
    for (int i = 0; i < qntItensCompra; i++)
    {
        fprintf(arquivoCSV, "%d;%s;%d;%d;%.2f;%.2f\n", lista[i].idVenda, lista[i].cpf, lista[i].idProd, lista[i].qnt, lista[i].unit, lista[i].total);
    }

    fclose(arquivoCSV);
}

void novaVenda(){
    limparTela();    
    int qtdeClientes = contClientesCSV();
    Clientes *listaClientes = (Clientes *)malloc(sizeof(Clientes) * qtdeClientes);
    preencheClientes(listaClientes);
    char cpf[15];
    printf("Digite o CPF do cliente: ");
    scanf("%14s[\n]", cpf);
    int i = 0;
    bool clienteExiste = false;
    Clientes cliente;
    while(!(clienteExiste) && i < qtdeClientes){
        if((strcmp(listaClientes[i].cpf, cpf)) == 0){
            clienteExiste = true;
            cliente = listaClientes[i];
        }
        i++;
    }
    if(!(clienteExiste)){
        limparTela();
        printf("Cliente não cadastrado, cadastre-se primeiro \nPara voltar ao menu principal pressione [ENTER] \n");
        getchar();
        getchar();
        return;
    }
    
    int qtdeCompras = contItensCSV();
    int iniciaEm = qtdeCompras;
    ItensCompra *compras = (ItensCompra *)malloc(sizeof(ItensCompra) * qtdeCompras);
    preencheCompras(compras);

    int qtdeProdutos = contProdutosCSV();
    Produtos *listaProdutos = (Produtos *)malloc(sizeof(Produtos) * qtdeProdutos);
    preencheLista(listaProdutos);

    int index = 0;
    ItensCompra *novoItem;
    while(true){
        limparTela();
        printf("O que deseja fazer Sr(a). %s?\n", cliente.nome);
        printf("1. Adicionar mais um item\n");
        printf("2. Ir para o carrinho\n");
        printf("9. Cancelar compra\n");
        printf("Digite a opcao: ");
        scanf("%d", &index);

        switch(index){
            case 1:
                limparTela();
                printf("Digite o ID do produto que deseja adicionar ao carrinho: ");
                int id = 0;
                int retorno = scanf("%d", &id);
                while(id > qtdeProdutos || id < 1 || retorno != 1){
                    limparTela();
                    printf("ID inválido, digite outro: ");
                    scanf("%d", &id);
                }
                limparTela();
                produtoInfos(listaProdutos, id);
                if(listaProdutos[id - 1].estoque <= 0){
                    printf("Não há estoque disponível\n Pressione [ENTER] para continuar");
                    getchar();
                    getchar();
                    break;
                }
                int unidades;
                printf("Digite quantas unidades quer: ");
                retorno = scanf("%d", &unidades);
                while(retorno != 1){
                    limparTela();
                    produtoInfos(listaProdutos, id);
                    printf("INVALIDO\nDigite quantas unidades quer: ");
                    retorno = scanf("%d", &unidades);
                }
                if(unidades > listaProdutos[id - 1].estoque){
                    limparTela();
                    produtoInfos(listaProdutos, id);
                    printf("Quantidade não disponível, pressione [ENTER] para continuar");
                    getchar();
                    getchar();
                    break;
                }
                listaProdutos[id - 1].estoque -= unidades;
                int idVenda;
                if(iniciaEm == 0){
                    idVenda = 1;
                } else {
                    idVenda = compras[iniciaEm - 1].idVenda + 1;
                }
                novoItem = (ItensCompra *)malloc(sizeof(ItensCompra));
                strcpy(novoItem->cpf, cliente.cpf);
                novoItem->idProd = id;
                novoItem->idVenda = idVenda;
                novoItem->qnt = unidades;
                novoItem->total = listaProdutos[id - 1].preco * unidades;
                novoItem->unit = listaProdutos[id - 1].preco;

                adicionaCompra(&compras, &qtdeCompras, *novoItem);
                free(novoItem);
                break;
            case 2:
                limparTela();
                carrinho(listaProdutos, compras, iniciaEm, qtdeCompras);
                printf("1. Fechar a compra\n");
                printf("2. Cancelar compra\n");
                printf("9. Voltar\n");
                printf("O que deseja fazer?\n");
                retorno = scanf("%d", &index);
                while(((index < 1 || index > 2) && index != 9) || retorno != 1){
                    limparTela();
                    carrinho(listaProdutos, compras, iniciaEm, qtdeCompras);
                    printf("1. Fechar a compra\n");
                    printf("2. Cancelar compra\n");
                    printf("9. Voltar\n");
                    printf("OPCAO INVALIDA, DIGITE OUTRA\n");
                    printf("O que deseja fazer?\n");
                    retorno = scanf("%d", &index);
                }
                double valorTotal = 0;
                int totalProdutos = 0;
                switch (index)
                {
                case 1:
                    for(int i = iniciaEm; i < qtdeCompras; i++){
                        valorTotal += compras[i].total;
                        totalProdutos += 1;
                    }
                    int qtdeVendas = contVendasCSV();
                    Vendas *listaVendas = (Vendas *)malloc(sizeof(Vendas) * (qtdeVendas + 1));
                    preencheVendas(listaVendas);
                    strcpy(listaVendas[qtdeVendas].cpf, cliente.cpf);
                    listaVendas[qtdeVendas].data = diaAtual();
                    listaVendas[qtdeVendas].idVenda = compras[iniciaEm].idVenda;
                    listaVendas[qtdeVendas].qtdeProd = totalProdutos;
                    listaVendas[qtdeVendas].valorTotal = valorTotal;
                    qtdeVendas += 1;
                    salvaItens(compras, qtdeCompras);
                    free(compras);
                    salvaVendas(listaVendas, qtdeVendas);
                    free(listaVendas);
                    atualizaArquivoCSV(listaProdutos, qtdeProdutos, 1);
                    free(listaProdutos);
                    for(int i = 0; i < qtdeClientes; i++){
                        if(strcmp(listaClientes[i].cpf, cliente.cpf) == 0){
                            index = i;
                        }
                    }
                    listaClientes[index].pontos += (int)valorTotal;

                    atualizaClientesCSV(listaClientes, qtdeClientes, 1);
                    limparTela();
                    printf("Parabéns %s!\n Sua compra no valor de %.2f foi concluida com sucesso!\n", cliente.nome, valorTotal);
                    printf("Você recebeu um total de %d pontos por essa compra! Você agora tem %d pontos!\n", (int)valorTotal, listaClientes[index].pontos);
                    free(listaClientes);
                    printf("Pressione [ENTER] para continuar...");
                    getchar();
                    getchar();
                    return;
                    break;
                case 2:
                    free(novoItem);
                    free(compras);
                    free(listaProdutos);
                    free(listaClientes);
                    return;
                    break;
                case 9:
                    break;
                default:
                    break;
                }
                break;
            case 9:
                free(novoItem);
                free(compras);
                free(listaProdutos);
                free(listaClientes);
                return;
                break;


        }
    }
}

void adicionaCompra(ItensCompra **lista, int *qtdeCompras, ItensCompra novoItem) {
    ItensCompra *novoPonteiro = (ItensCompra *)realloc(*lista, sizeof(ItensCompra) * (*qtdeCompras + 1));

    if (novoPonteiro != NULL) {
        *lista = novoPonteiro;
        (*lista)[*qtdeCompras] = novoItem;
        *qtdeCompras += 1;
    } else {
        while(true){
        printf("Erro na realocacao de memoria\n");
        }
    }
}

void mostrarCompras(){
    int qtdeClientes = contClientesCSV();
    Clientes *listaClientes = (Clientes *)malloc(sizeof(Clientes) * qtdeClientes);
    preencheClientes(listaClientes);
    int qtdeVendas = contVendasCSV();
    Vendas *listaVendas = (Vendas *)malloc(sizeof(Vendas) * qtdeVendas);
    preencheVendas(listaVendas);

    limparTela();
    char userInput[50];
    printf("Digite seu CPF ou nome completo: ");
    scanf(" %[^\n]s", userInput);
    int clienteIndex;
    bool clienteExiste = false;
    int i = 0;
    while(!(clienteExiste) && i < qtdeClientes){
        if(strcmp(listaClientes[i].cpf, userInput) == 0 || strcmp(listaClientes[i].nome, userInput) ==0) {
            clienteIndex = i;
            clienteExiste = true;
        }
        i++;
    }
    if(!(clienteExiste)){
        limparTela();
        printf("Cliente não localizado\nPressione [ENTER] para continuar...");
        getchar();
        getchar();
        return;
    }
    limparTela();
    printf("Compras de %s\n", listaClientes[clienteIndex].nome);
    printf("%-25s%-20s%-20s\n", "DATA DA COMPRA", "VALOR DA COMPRA", "QUANTIDADE DE PRODUTOS");
    for(int c = 0; c < qtdeVendas; c++){
        if(strcmp(listaVendas[c].cpf, listaClientes[clienteIndex].cpf) == 0){
            printf("%d/%d/%-19d%-20.2f%-20d\n", listaVendas[c].data.dia, listaVendas[c].data.mes, listaVendas[c].data.ano, listaVendas[c].valorTotal, listaVendas[c].qtdeProd);
        }
    }
    getchar();
    getchar();
};