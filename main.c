#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "produtos.h"
#include "clientes.h"

//Inicializa o main
int main(){
    Clientes cliente;
    //Cria uma variável do tipo "Produtos" (ver "produtos.h")
    Produtos produto;

    //Cria um ponteiro do tipo "Produtos"
    Produtos *lista;
    Clientes *clientes;

    //Cria variável do tipo inteiro
    int qntProd;
    int qntC;

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

        lista = (Produtos *)malloc(sizeof(Produtos) * qntProd);
        preencheLista(lista);
        
        clientes = (Clientes *)malloc(sizeof(Clientes) * qntC);
        preencheClientes(clientes);
        //Chama o menu principal e atribui o valor da opção escolhida na variável de controle "Index"
        if (lista != NULL && clientes != NULL)
        {
            int idProd = lista[qntProd - 1].id;
            index = menuInicial();
            switch (index)
            {
            case 1:
                index = menuVendas();

                //novo case aqui

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
                    controle = atualizaPontos(clientes, qntC);
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

    return 0;
}