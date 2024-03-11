#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/telas.h"
#include "../include/produtos.h"
#include "../include/clientes.h"
#include "../include/vendas.h"

//Inicializa o main
int main(){

    //Cria uma variável do tipo "Clientes" (ver "clientes.h")
    Clientes cliente;
    //Cria uma variável do tipo "Produtos" (ver "produtos.h")
    Produtos produto;

    //Cria um ponteiro do tipo "Clientes"
    Clientes *clientes;
    //Cria um ponteiro do tipo "Produtos"
    Produtos *lista;

    ItensCompra *compras;

    //Cria variável do tipo inteiro
    int qntProd;
    int qntC;
    int qntItens;

    //Atribui valor para a variavel inteira com a quantidade de produtos cadastrados no arquivo "Produtos.csv"
    
    //Inicializa uma variável inteira com 0 para entrar no menu principal
    int index = 0;

    int controle;

    //Menu principal
    while (index != 9)
    {
        //Cria vetor de variáveis do tipo "Produtos" com a quantidade de produtos como máximo 
        qntProd = contProdutosCSV();
        qntC = contClientesCSV();
        qntItens = contItensCSV();

        lista = (Produtos *)malloc(sizeof(Produtos) * qntProd);
        
        clientes = (Clientes *)malloc(sizeof(Clientes) * qntC);

        compras = (ItensCompra *)malloc(sizeof(ItensCompra) * qntItens);
        //Chama o menu principal e atribui o valor da opção escolhida na variável de controle "Index"
        if (lista != NULL && clientes != NULL && compras != NULL)
        {
            preencheLista(lista);
            preencheClientes(clientes);
            preencheCompras(compras);
            
            int idProd = lista[qntProd - 1].id;
            limparTela();
            index = menuInicial();
            switch (index)
            {
            case 1:
                index = menuVendas();
                switch(index)
                {
                    case 1:
                        novaVenda();
                        break;
                    case 2:
                        mostrarCompras();
                    case 9:
                        index = 1;
                        break;
                }
                break;
            case 2:
                index = menuClientes();
                switch (index)
                {
                case 1:
                    novoCliente(&cliente);
                    arquivoCSVCliente(cliente);
                    break;
                case 2:
                    controle = atualizaPontos(clientes, qntC, compras, qntItens);
                    atualizaClientesCSV(clientes, qntC, controle);
                    break;
                case 3:
                    controle = atualizaCliente(clientes, qntC);
                    atualizaClientesCSV(clientes, qntC, controle);
                    break;
                case 4:
                    idadeClientes(clientes, qntC);
                    break;
                case 5:
                    maisPontos(clientes, qntC);
                    break;
                default:
                    break;
                }
                break;
            case 3:
                index = menuProdutos();
                switch (index)
                {
                case 1:
                    novoProduto(&produto, idProd);
                    arquivoCSV(produto);
                    break;
                case 2:
                    controle = atualizaProdutos(lista, qntProd);
                    atualizaArquivoCSV(lista, qntProd, controle);
                    break;
                case 3:
                    prodPorSetor(lista, qntProd);
                    break;
                case 4:
                    baixoEstoque(lista, qntProd);
                    break;
                default:
                    break;
                }
                break;
            case 9:
                printf("Saindo do programa...");
                getchar();
                getchar();
                limparTela();
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
            free(clientes);
            free(compras);
        }
        else{
            printf("Algo deu errado.");
        }   
    }

    if(lista != NULL)
    {
        free(lista);
    }

    if(clientes != NULL)
    {
        free(clientes);
    }
    if (compras != NULL)
    {
        free(compras);
    }
    


    return 0;
}