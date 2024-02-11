#include "produtos.h"
#include "telas.h"
#include "data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void novoProduto(){
    limparTela();
    separador();

    char setHig[10], setLimp[10], setBeb[10], setFrio[5], setPad[10], setAco[10];
    bool hig = false, limp = false, beb = false, frio = false, pad = false, aco = false;
    
    strcpy(setHig, "Higiene");
    strcpy(setLimp, "Limpeza");
    strcpy(setBeb, "Bebidas");
    strcpy(setFrio, "Frios");
    strcpy(setPad, "Padaria");
    strcpy(setAco, "Acougue");

    Produtos novo;
    
    printf("Digite o codigo do produto: ");
    scanf(" %d", &novo.identificador);
    while (novo.identificador < 0)
    {
        printf("Esse valor nao e um numero valido\n");
        printf("Digite um identificador valido");
        scanf(" %d", &novo.identificador);
    }
    

    printf("Digite o setor do produto: ");
    scanf(" %[^\n]s", novo.setor);
    while (!(hig || limp || beb || frio || pad || aco))
    {
        if (strcmp(novo.setor, setHig) == 0)
        {
            hig = true;
        }
        else if (strcmp(novo.setor, setLimp) == 0)
        {
            limp = true;
        }
        else if (strcmp(novo.setor, setBeb) == 0)
        {
            beb = true;
        }
        else if (strcmp(novo.setor, setFrio) == 0)
        {
            frio = true;
        }
        else if (strcmp(novo.setor, setPad) == 0)
        {
            pad = true;
        }
        else if (strcmp(novo.setor, setAco) == 0)
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
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", novo.nomeProd);

    printf("Digite o preço do produto: ");
    scanf(" %lf", &novo.preco);

    printf("Digite a data de validade.\n");
    printf("Dia: ");
    scanf(" %d", &novo.validade.dia);

    printf("Mes: ");
    scanf(" %d", &novo.validade.mes);

    printf("Ano: ");
    scanf(" %d", &novo.validade.ano);

    printf("Digite a quantidade no estoque: ");
    scanf(" %d", &novo.estoque);
    if (novo.estoque < 0)
    {
        printf("Quantidade invalida.\n");
        printf("Digite uma quantidade valida\n");
        scanf(" %d", &novo.estoque);
    }
    separador();
    limparTela();
}