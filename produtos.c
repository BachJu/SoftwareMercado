#include "produtos.h"
#include "telas.h"
#include "data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


//Cadastra um novo produto
void novoProduto(){
    //Limpa a tela
    limparTela();

    //Separador estético
    separador();

    //Declara variáveis de contole para comparar com o que o usuário digitar
    bool hig = false, limp = false, beb = false, frio = false, pad = false, aco = false;

    //Declara variável do tipo "Produtos"
    Produtos novo;
    
    //Pede o identificador do novo produto que será cadastrado
    printf("Digite o codigo do produto: ");
    scanf(" %d", &novo.identificador);

    //Verifica se é um identificador válido
    while (novo.identificador < 0)
    {
        printf("Esse valor nao e um numero valido\n");
        printf("Digite um identificador valido");
        scanf(" %d", &novo.identificador);
    }
    
    //Pede o setor do novo produto
    printf("Digite o setor do produto: ");

    //Verifica se é um setor válido
    scanf(" %[^\n]s", novo.setor);
    while (!(hig || limp || beb || frio || pad || aco))
    {
        if (strcmp(novo.setor, "Higiene") == 0)
        {
            hig = true;
        }
        else if (strcmp(novo.setor, "Limpeza") == 0)
        {
            limp = true;
        }
        else if (strcmp(novo.setor, "Bebida") == 0)
        {
            beb = true;
        }
        else if (strcmp(novo.setor, "Frios") == 0)
        {
            frio = true;
        }
        else if (strcmp(novo.setor, "Padaria") == 0)
        {
            pad = true;
        }
        else if (strcmp(novo.setor, "Acougue") == 0)
        {
            aco = true;
        }
        
        if (!(hig || limp || beb || frio || pad || aco))
        {
            printf("O setor esta incorreta e/ou nao existe.\n");
            printf("Por gentileza, digite um setor valido.\n");
            printf("Os setores validos sao: \n");
            printf("Acougue;\n");
            printf("Bebidas;\n");
            printf("Frios;\n");
            printf("Higiene;\n");
            printf("Limpeza;\n");
            printf("Padaria;\n");
            scanf(" %[^\n]s", novo.setor);
        }
        
        
    }

    //Pede o nome do produto
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", novo.nomeProd);

    //Pede o preço do produto
    printf("Digite o preço do produto: ");
    scanf(" %lf", &novo.preco);

    //Pede a data de validade
    printf("Digite a data de validade.\n");
    printf("Dia: ");
    scanf(" %d", &novo.validade.dia);

    printf("Mes: ");
    scanf(" %d", &novo.validade.mes);

    printf("Ano: ");
    scanf(" %d", &novo.validade.ano);

    //Pede a quantidade armazenada no estoque do novo produto
    printf("Digite a quantidade no estoque: ");
    scanf(" %d", &novo.estoque);

    //Verifica se é um valor válido
    if (novo.estoque < 0)
    {
        printf("Quantidade invalida.\n");
        printf("Digite uma quantidade valida\n");
        scanf(" %d", &novo.estoque);
    }

    //Limpa tela
    limparTela();
}