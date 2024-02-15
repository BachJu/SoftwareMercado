#include "produtos.h"
#include "telas.h"
#include "data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//Cadastra um novo produto
void novoProduto(Produtos *novoP){
    //Limpa a tela
    limparTela();

    //Separador estético
    separador();

    //Declara variáveis de contole para comparar com o que o usuário digitar
    bool hig = false, limp = false, beb = false, frio = false, pad = false, aco = false;
    
    //Pede o identificador do novo produto que será cadastrado
    printf("Digite o codigo do produto: ");
    scanf(" %d", &novoP->id);

    //Verifica se é um identificador válido
    while (novoP->id < 0)
    {
        printf("Esse valor nao e um numero valido.\n");
        printf("Digite um identificador valido");
        scanf(" %d", &novoP->id);
    }
    
    //Pede o setor do novo produto
    printf("Digite o setor do produto: ");

    //Verifica se é um setor válido através de comparação de strings e usando valores booleanos para controle
    //Sendo esses setores: "Higiene", "Limpeza", "Bebidas", "Frios", "Padaria" e "Acougue"
    scanf(" %[^\n]s", novoP->setor);
    while (!(hig || limp || beb || frio || pad || aco))
    {
        if (strcmp(novoP->setor, "Higiene") == 0)
        {
            hig = true;
        }
        else if (strcmp(novoP->setor, "Limpeza") == 0)
        {
            limp = true;
        }
        else if (strcmp(novoP->setor, "Bebidas") == 0)
        {
            beb = true;
        }
        else if (strcmp(novoP->setor, "Frios") == 0)
        {
            frio = true;
        }
        else if (strcmp(novoP->setor, "Padaria") == 0)
        {
            pad = true;
        }
        else if (strcmp(novoP->setor, "Acougue") == 0)
        {
            aco = true;
        }
        
        //Caso os valores continuem falsos, pede para o usuário digitar uma nova string
        if (!(hig || limp || beb || frio || pad || aco))
        {
            printf("O setor esta incorreto e/ou nao existe.\n");
            printf("Os setores validos sao: \nAcougue;\nBebidas;\nFrios;\nHigiene;\nLimpeza;\nPadaria;\n");
            scanf(" %[^\n]s", novoP->setor);
        }  
    }

    //Pede o nome do produto
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", novoP->nomeProd);

    //Pede o preço do produto
    printf("Digite o preço do produto: ");
    scanf(" %lf", &novoP->preco);

    //Pede a data de validade, sendo a data um registro com os campos "dia", "mês" e "ano"
    printf("Digite a data de validade.\n");
    printf("Dia: ");
    scanf(" %d", &novoP->validade.dia);
    
    //Verifica se é um dia válido
    while ((novoP->validade.dia > 31) || (novoP->validade.dia < 0))
    {
        printf("Não é um dia válido.\nPor gentileza, digite o dia de validade.\nDia: ");
        scanf(" %d", &novoP->validade.dia);
    }
    
    printf("Mes: ");
    scanf(" %d", &novoP->validade.mes);

    //Varifica se é um mês válido
    while (novoP->validade.mes > 12 || novoP->validade.mes < 0)
    {
        printf("Não é um mês válido.\nPor gentileza, digite o mês de validade.\nMês: ");
        scanf(" %d", &novoP->validade.mes);
    }

    printf("Ano: ");
    scanf(" %d", &novoP->validade.ano);

    //Verifica se é um ano válido
    while (novoP->validade.ano < 2024 || novoP->validade.ano < 0)
    {
        printf("Não é um ano válido.\nPor gentileza, digite o ano de validade.\nAno: ");
        scanf(" %d", &novoP->validade.ano);
    }

    //Pede a quantidade armazenada no estoque do novoP produto
    printf("Digite a quantidade no estoque: ");
    scanf(" %d", &novoP->estoque);

    //Verifica se é um valor válido
    if (novoP->estoque < 0)
    {
        printf("Quantidade invalida.\n");
        printf("Digite uma quantidade valida\n");
        scanf(" %d", &novoP->estoque);
    }

    //Limpa tela
    limparTela();    
}

//Cria ou atualiza com novas entradas um arquivo em CSV
void arquivoCSV(Produtos p){
    
    //Cria um pontador do tipo arquivo
    FILE *arqProd;

    //Abre o arquivo CSV para leitura
    arqProd = fopen("Produtos.csv", "r");

    //Caso o arquivo não exista, cria um novo
    if (arqProd == NULL)
    {
        //Arquivo não existe
        arqProd = fopen("Produtos.csv", "a");
        //Cria cabeçalho
        fprintf(arqProd, "Id;Setor;Nome;Preço;Data de Validade;Estoque\n");
        //Escreve as informações do novo produto
        fprintf(arqProd, "%d;%s;%s;%.2lf;%d/%d/%d;%d\n", p.id, p.setor, p.nomeProd, p.preco, p.validade.dia, p.validade.mes, p.validade.ano, p.estoque);
        //Fecha e salva o arquivo
        fclose(arqProd);
    }
    else{

        //Abre o arquivo para acrescentar informações
        arqProd = fopen("Produtos.csv", "a");
        //Acrescenta as informações necessárias
        fprintf(arqProd, "%d;%s;%s;%.2lf;%d/%d/%d;%d\n", p.id, p.setor, p.nomeProd, p.preco, p.validade.dia, p.validade.mes, p.validade.ano, p.estoque);
        //Fecha e salva o arquivo
        fclose(arqProd);
    }
}

//Conta quantos produtos estão resgitrados no arquivo CSV
int contProdutosCSV(){
    //Abre o arquivo
    FILE *arq;
    //Caracter para guardar as informações lidas
    char linha[1000];
    //Ponteiro para usar a função strtok
    char *campos;
    //Caracter para sinalizar a "quebra" do token na função strtok
    const char s[2] = ";";
    //Contador de linhas
    int contadorLinha = 0;
    arq = fopen("Produtos.csv", "r");
    if (arq != NULL)
    {
        // fim dos registros, reabrindo para ler os dados
        fseek(arq, 0, SEEK_SET);
        // lendo o cabeçalho do arquivo
        fscanf(arq, " %[^\n]s", linha);
        // alocando memoria para os registros lidos

        int i = 0;
        while (fscanf(arq, " %[^\n]s", linha) != EOF)
        {
            // separando os dados de uma linha
            campos = strtok(linha, s);
            while (campos != NULL)
            {
                campos = strtok(NULL, s);
            }

            i++;
            // dados do setor;
        }
        contadorLinha = i;
        fclose(arq);
    }
    return contadorLinha;

}

void novoProdutoVetor(Produtos *lista, Produtos p,int fim){
    lista[fim].id = p.id;
    strcpy(lista[fim].setor, p.setor);
    strcpy(lista[fim].nomeProd, p.nomeProd);
    lista[fim].preco = p.preco;
    lista[fim].validade.dia = p.validade.dia;
    lista[fim].validade.mes = p.validade.mes;
    lista[fim].validade.ano = p.validade.ano;
    lista[fim].estoque = p.estoque;
}

void preencheLista(Produtos *lista){
    FILE *csv;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    csv = fopen("Produtos.csv", "r");
    if (csv != NULL)
    {
        // fim dos registros, reabrindo para ler os dados
        fseek(csv, 0, SEEK_SET);
        // lendo o cabeçalho do arquivo
        fscanf(csv, " %[^\n]s", linha);
        // alocando memoria para os registros lidos

        int i = 0;
        while (fscanf(csv, " %[^\n]s", linha) != EOF)
        {
            // separando os dados de uma linha
            campos = strtok(linha, s);
            int campoAtual = 0;
            while (campos != NULL)
            {
                switch (campoAtual)
                {
                case 0:
                    lista[i].id = atoi(campos);
                    break;
                case 1:
                    strcpy(lista[i].setor, campos);
                    break;
                case 2:
                    strcpy(lista[i].nomeProd, campos);
                    break;
                case 3:
                    lista[i].preco = atof(campos);
                    break;
                case 5:
                    lista[i].estoque = atoi(campos);
                    break;
                default:
                    break;
                }
                campos = strtok(NULL, s);

                campoAtual++;
            }

            i++;
            // dados do setor;
        }
    }
}