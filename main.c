#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "produtos.h"

//Inicializa o main
int main(){
    //Cria uma variável do tipo "Produtos" (ver "produtos.h")
    Produtos produto;

    //Cria um ponteiro do tipo "Produtos"
    Produtos *lista;

    //Cria variável do tipo inteiro
    int qntProd;

    //Atribui valor para a variavel inteira com a quantidade de produtos cadastrados no arquivo "Produtos.csv"
    
    //Inicializa uma variável inteira com 0 para entrar no menu principal
    int index = 0;

    //Menu principal
    while (index != 9)
    {
        //Cria vetor de variáveis do tipo "Produtos" com a quantidade de produtos como máximo 
        qntProd = contProdutosCSV();
        lista = (Produtos *)malloc(sizeof(Produtos) * qntProd);
        preencheLista(lista);
        //Chama o menu principal e atribui o valor da opção escolhida na variável de controle "Index"
        index = menuInicial();
        switch (index)
        {
        case 1:
            index = menuVendas();
            break;
        case 2:
            index = menuClintes();
            break;
        case 3:
            index = menuProdutos();
            switch (index)
            {
            case 1:
                novoProduto(&produto);
                arquivoCSV(produto);
                break;
            case 2:
                atualizaProdutos(lista, qntProd);
                break;
            default:
                break;
            }
            break;
        case 9:
            printf("Saindo do programa...");
            break;
        default:
            printf("Nao e uma opcao valida");
            getchar();
            getchar();
            limparTela();
            break;
        }
        //Limpa o vetor de "Produtos"
        free(lista);
    }
    return 0;
}