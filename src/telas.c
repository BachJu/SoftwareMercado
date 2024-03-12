#include "../include/telas.h"
#include "../include/vendas.h"
#include "../include/clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#ifdef _WIN32
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

// Primeiras opções fornecidas
int menuInicial()
{
    // Variável de controle
    int index;

    // Separador estético
    separador();

    // Opções disponíveis
    printf("1. Venda\n");
    printf("2. Clientes\n");
    printf("3. Produtos\n");
    printf("4. Mudar tema (Atual: %c)\n", tema);
    printf("9. Sair");

    // Separador estético
    separador();

    // Leitura da opção escolhida pelo usuário
    scanf(" %d", &index);

    limparTela();

    // Retorna para o programa principal a opção escolhida pelo usuário
    return index;
}

// Menu de Vendas
int menuVendas()
{
    // Limpa a tela
    limparTela();

    // Variável de controle
    int index;

    // Separador estético
    separador();

    // Opções para Venda
    printf("1. Nova Venda\n");
    printf("2. Listar Venda dos Clientes\n");
    printf("9. Sair");

    // Separador estético
    separador();

    // Leitura da opção escolhida pelo usuário
    scanf(" %d", &index);

    limparTela();

    // Retorna para o programa principal a opção escolhida pelo usuário
    return index;
}

// Menu de Clientes
int menuClientes()
{

    // Limpa a tela
    limparTela();

    // Variável de controle
    int index;

    // Separador estético
    separador();

    // Opções para Clientes
    printf("1. Cadastrar Novo Cliente\n");
    printf("2. Atualizar Pontuação\n");
    printf("3. Atualizar Cliente\n");
    printf("4. Listar Clientes entre 18 e 25\n");
    printf("5. Listar Clientes acima de 1000 pontos\n");
    printf("9. Sair");

    // Separador estético
    separador();

    // Leitura da opção escolhida pelo usuário
    scanf(" %d", &index);

    limparTela();

    // Retorna para o programa principal a opção escolhida pelo usuário
    return index;
}

// Menu de Produtos
int menuProdutos()
{

    // Limpa a tela
    limparTela();

    // Variável de controle
    int index;

    // Separador estético
    separador();

    // Opções para Produtos
    printf("1. Cadastrar novo produto\n");
    printf("2. Atualizar informacoes do produto\n");
    printf("3. Estoque por setor\n");
    printf("4. Produtos com estoque baixo\n");
    printf("9. Sair");

    // Separador estético
    separador();

    // Leitura da opção escolhida pelo usuário
    scanf(" %d", &index);

    limparTela();

    // Retorna para o programa principal a opção escolhida pelo usuário
    return index;
}

int menuAtualizaProd()
{
    int index;

    // Separador estético
    separador();

    printf("O que deseja alterar\n");
    printf("1. Setor\n");
    printf("2. Nome do produto\n");
    printf("3. Preço\n");
    printf("4. Data de validade\n");
    printf("5. Quantidade em estoque\n");
    printf("9. Sair");

    // Separador estético
    separador();

    scanf(" %d", &index);

    limparTela();

    return index;
}

int menuAtualizaC()
{
    int index;

    // Separador estético
    separador();

    printf("O que deseja alterar\n");
    printf("1. Nome\n");
    printf("2. Idade\n");
    printf("3. Endereço\n");
    printf("4. Cidade\n");
    printf("5. Estado\n");
    printf("9. Sair");

    // Separador estético
    separador();

    scanf(" %d", &index);

    limparTela();

    return index;
}

// Função para Limpar a tela
void limparTela()
{

    // Para Windows "cls"
    // Para Linux "clear"
    system(LIMPAR_TELA);
}

char tema = '=';
// Função estética
void separador()
{
    int TAM = 100;
    // Cria duas linhas de "-" para separar dados e estética
    if (tema == '-')
    {
        printf("\n");
        for (int i = 0; i < TAM; i++)
        {
            printf("-");
        }
        printf("\n");
        for (int i = 0; i < TAM; i++)
        {
            printf("-");
        }
        printf("\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("=");
    }
    printf("\n");

    return;
}

void produtoInfos(Produtos *lista, int id)
{
    id -= 1;
    separador();
    printf("%-40s%-50s \n", "Nome:", lista[id].nomeProd);
    printf("%-40s R$%-50.2f \n", "Preço:", lista[id].preco);
    printf("%-40s%-50d", "Quantidade em estoque:", lista[id].estoque);
    separador();
}

void carrinho(Produtos *listaProdutos, ItensCompra *lista, int primeiroID, int ultimoId)
{
    printf("%-30s%-20s%-22s%-22s", "NOME", "QUANTIDADE", "VALOR UNITÁRIO", "VALOR TOTAL");
    separador();
    double valorTotal = 0;
    for (int i = primeiroID; i < ultimoId; i++)
    {
        printf("%-30s%-20dR$%-19.2fR$%-19.2f\n", listaProdutos[lista[i].idProd - 1].nomeProd, lista[i].qnt, lista[i].unit, lista[i].total);
        valorTotal += lista[i].total;
    }
    printf("\n%-80sR$%10.2f", "TOTAL: ", valorTotal);
    separador();
    printf("\n");
}

void novaVenda()
{
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
    while (!(clienteExiste) && i < qtdeClientes)
    {
        if ((strcmp(listaClientes[i].cpf, cpf)) == 0)
        {
            clienteExiste = true;
            cliente = listaClientes[i];
        }
        i++;
    }
    if (!(clienteExiste))
    {
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
    while (true)
    {
        limparTela();
        printf("O que deseja fazer Sr(a). %s?", cliente.nome);
        separador();
        printf("1. Adicionar mais um item\n");
        printf("2. Ir para o carrinho\n");
        printf("9. Cancelar compra");
        separador();
        scanf("%d", &index);

        switch (index)
        {
        case 1:
            limparTela();
            printf("Digite o ID do produto que deseja adicionar ao carrinho: ");
            int id = 0;
            int retorno = scanf("%d", &id);
            while (id > qtdeProdutos || id < 1 || retorno != 1)
            {
                limparTela();
                printf("ID inválido, digite outro: ");
                scanf("%d", &id);
            }
            limparTela();
            produtoInfos(listaProdutos, id);
            if (listaProdutos[id - 1].estoque <= 0)
            {
                printf("Não há estoque disponível\n Pressione [ENTER] para continuar");
                getchar();
                getchar();
                break;
            }
            int unidades;
            printf("Digite quantas unidades quer: ");
            retorno = scanf("%d", &unidades);
            while (retorno != 1)
            {
                limparTela();
                produtoInfos(listaProdutos, id);
                printf("INVALIDO\nDigite quantas unidades quer: ");
                retorno = scanf("%d", &unidades);
            }
            if (unidades > listaProdutos[id - 1].estoque)
            {
                limparTela();
                produtoInfos(listaProdutos, id);
                printf("Quantidade não disponível\nPressione [ENTER] para continuar");
                getchar();
                getchar();
                break;
            }
            listaProdutos[id - 1].estoque -= unidades;
            int idVenda;
            if (iniciaEm == 0)
            {
                idVenda = 1;
            }
            else
            {
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
            while (((index < 1 || index > 2) && index != 9) || retorno != 1)
            {
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
                for (int i = iniciaEm; i < qtdeCompras; i++)
                {
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
                for (int i = 0; i < qtdeClientes; i++)
                {
                    if (strcmp(listaClientes[i].cpf, cliente.cpf) == 0)
                    {
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

void mostrarCompras()
{
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
    while (!(clienteExiste) && i < qtdeClientes)
    {
        if (strcmp(listaClientes[i].cpf, userInput) == 0 || strcmp(listaClientes[i].nome, userInput) == 0)
        {
            clienteIndex = i;
            clienteExiste = true;
        }
        i++;
    }
    if (!(clienteExiste))
    {
        limparTela();
        printf("Cliente não localizado\nPressione [ENTER] para continuar...");
        getchar();
        getchar();
        return;
    }
    limparTela();
    printf("Compras de %s", listaClientes[clienteIndex].nome);
    separador();
    printf("%-25s%-20s%-20s", "DATA DA COMPRA", "VALOR DA COMPRA", "QUANTIDADE DE PRODUTOS");
    separador();
    for (int c = 0; c < qtdeVendas; c++)
    {
        if (strcmp(listaVendas[c].cpf, listaClientes[clienteIndex].cpf) == 0)
        {
            printf("%d/%02d/%-19d%-20.2f%-20d\n", listaVendas[c].data.dia, listaVendas[c].data.mes, listaVendas[c].data.ano, listaVendas[c].valorTotal, listaVendas[c].qtdeProd);
        }
    }
    getchar();
    getchar();
};