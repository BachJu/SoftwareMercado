#include <stdio.h>
#include <stdlib.h>
#include "telas.h"
#include "produtos.h"


int main(){
    Produtos produto;
    Produtos *lista;
    int qntProd;

    qntProd = contProdutosCSV();
    
    int index = 0;
    while (index != 9)
    {
        lista = (Produtos *)malloc(sizeof(Produtos) * qntProd);
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
                arquivoCSV(produto, &qntProd);
                printf("Produtos cadastrados: %d\n", qntProd);
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
        free(lista);
    }
    return 0;
}