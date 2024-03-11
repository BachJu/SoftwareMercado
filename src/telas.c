#include "../include/telas.h"
#include "../include/vendas.h"
#include "../include/clientes.h"
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
int menuClientes(){
    
    //Limpa a tela
    limparTela();

    //Variável de controle
    int index;

    //Separador estético
    separador();

    //Opções para Clientes
    printf("1. Cadastrar Novo Cliente\n");
    printf("2. Atualizar Pontuação\n");
    printf("3. Atualizar Cliente\n");
    printf("4. Listar Clientes entre 18 e 25\n");
    printf("5. Listar Clientes acima de 1000 pontos\n");
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


int menuAtualizaProd(){
    int index;
    
    //Separador estético
    separador();

    printf("O que deseja alterar\n");
    printf("1. Setor\n");
    printf("2. Nome do produto\n");
    printf("3. Preço\n");
    printf("4. Data de validade\n");
    printf("5. Quantidade em estoque\n");
    printf("9. Sair");
    
    //Separador estético
    separador();

    scanf(" %d", &index);

    limparTela();
    
    return index;
}

int menuAtualizaC(){
    int index;
    
    //Separador estético
    separador();

    printf("O que deseja alterar\n");
    printf("1. Nome\n");
    printf("2. Idade\n");
    printf("3. Endereço\n");
    printf("4. Cidade\n");
    printf("5. Estado\n");
    printf("9. Sair");
    
    //Separador estético
    separador();

    scanf(" %d", &index);

    limparTela();
    
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

void produtoInfos(Produtos *lista, int id){
    id -= 1;
    printf("%-40s%s \n", "Nome:", lista[id].nomeProd);
    printf("%-40sR$%.2f \n", "Preço:", lista[id].preco);
    printf("%-40s%d \n", "Quantidade em estoque:", lista[id].estoque);
}

void carrinho(Produtos *listaProdutos, ItensCompra *lista, int primeiroID, int ultimoId){
    printf("%-25s %-10s %-14s %-14s\n", "NOME", "QUANTIDADE", "VALOR UNITÁRIO", "VALOR TOTAL");
    for(int i = primeiroID; i < ultimoId; i++){
        printf("%-25s %-10d %-14.2f %-14.2f\n", listaProdutos[lista[i].idProd - 1].nomeProd, lista[i].qnt, lista[i].unit, lista[i].total);
    }
}