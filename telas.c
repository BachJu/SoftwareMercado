#include "telas.h"
#include <stdio.h>
#include <stdlib.h>

//Primeiras opções fornecidas
int menuInicial(){
    //Variável de controle
    int index;
    
    //Separador estético
    separador();

    //Opções disponíveis
    printf("1. Venda.\n");
    printf("2. Clientes.\n");
    printf("3. Produtos\n");
    printf("9. Sair");
    
    //Separador estético
    separador();

    //Leitura da opção escolhida pelo usuário
    scanf(" %d", &index);

    limparTela();

    //Retorna para o programa principal a opção escolhida pelo usuário
    return index;
}


//Menu de Vendas
int menuVendas(){
    //Limpa a tela
    limparTela();

    //Variável de controle
    int index;

    //Separador estético
    separador();

    //Opções para Venda
    printf("1. Nova Venda\n");
    printf("2. Listar Venda dos Clientes\n");
    printf("9. Sair");

    //Separador estético
    separador();
    
    //Leitura da opção escolhida pelo usuário
    scanf(" %d", &index);

    limparTela();

    //Retorna para o programa principal a opção escolhida pelo usuário
    return index;

}

//Menu de Clientes
int menuClintes(){
    
    //Limpa a tela
    limparTela();

    //Variável de controle
    int index;

    //Separador estético
    separador();

    //Opções para Clientes
    printf("1. Cadastrar Novo Cliente\n");
    printf("2. Atualizar Pontuação\n");
    printf("3. Listar Clientes entre 18 e 25\n");
    printf("4. Listar Clientes acima de 1000 pontos\n");
    printf("9. Sair");

    //Separador estético
    separador();

    //Leitura da opção escolhida pelo usuário
    scanf(" %d", &index);

    limparTela();

    //Retorna para o programa principal a opção escolhida pelo usuário
    return index;
}

//Menu de Produtos
int menuProdutos(){
    
    //Limpa a tela
    limparTela();

    //Variável de controle
    int index;

    //Separador estético
    separador();

    //Opções para Produtos
    printf("1. Cadastrar novo produto\n");
    printf("2. Atualizar informacoes do produto\n");
    printf("3. Estoque por setor\n");
    printf("4. Produtos com estoque baixo\n");
    printf("9. Sair");
    
    //Separador estético
    separador();

    //Leitura da opção escolhida pelo usuário
    scanf(" %d", &index);

    limparTela();
    
    //Retorna para o programa principal a opção escolhida pelo usuário
    return index;
}

//Função para Limpar a tela
void limparTela(){

    //Para Windows "cls"
    //Para Linuz "clear"
    system("cls");
}

//Função estética
void separador(){
    
    //Cria duas linhas de "-" para separar dados e estética
    printf("\n");
    int TAM = 40;
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
    
}