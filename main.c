#include <stdio.h>
#include <stdlib.h>
#include "telas.h"
#include "produtos.h"


int main(){
    int index = 0;
    while (index != 9)
    {
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
                novoProduto();
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
    }
    
    return 0;
}