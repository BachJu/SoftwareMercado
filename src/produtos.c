#include "../include/produtos.h"
#include "../include/telas.h"
#include "../include/data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//Cadastra um novo produto
void novoProduto(Produtos *novoP, int idProd){
    //Limpa a tela
    limparTela();

    //Separador estético
    separador();

    novoP->id = idProd + 1;
    printf("Esse é o id do produto: %d\n", novoP->id);

    //Declara variável de contole para comparar com o que o usuário digitar
    bool verifica = false;
    
    //Pede o setor do novo produto
    printf("Digite o setor do produto: ");

    //Verifica se é um setor válido através de comparação de strings e usando valores booleanos para controle
    //Sendo esses setores: "Higiene", "Limpeza", "Bebidas", "Frios", "Padaria" e "Acougue"
    scanf(" %[^\n]s", novoP->setor);
    while (!(verifica))
    {
        if (strcmp(novoP->setor, "Higiene") == 0 || strcmp(novoP->setor, "Limpeza") == 0 || strcmp(novoP->setor, "Bebidas") == 0 || strcmp(novoP->setor, "Frios") == 0 || strcmp(novoP->setor, "Padaria") == 0 || strcmp(novoP->setor, "Acougue") == 0)
        {
            verifica = true;
        }
        //Caso os valores continuem falsos, pede para o usuário digitar uma nova string
        else
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
    arqProd = fopen("planilhas/Produtos.csv", "r");

    //Caso o arquivo não exista, cria um novo
    if (arqProd == NULL)
    {
        //Arquivo não existe
        arqProd = fopen("planilhas/Produtos.csv", "a");
        //Cria cabeçalho
        fprintf(arqProd, "Id;Setor;Nome;Preço;Data de Validade;Estoque\n");
        //Escreve as informações do novo produto
        fprintf(arqProd, "%d;%s;%s;%.2lf;%d/%d/%d;%d\n", p.id, p.setor, p.nomeProd, p.preco, p.validade.dia, p.validade.mes, p.validade.ano, p.estoque);
        //Fecha e salva o arquivo
        fclose(arqProd);
    }
    else{

        //Abre o arquivo para acrescentar informações
        arqProd = fopen("planilhas/Produtos.csv", "a");
        //Acrescenta as informações necessárias
        fprintf(arqProd, "\n");
        fprintf(arqProd, "%d;%s;%s;%.2lf;%d/%d/%d;%d", p.id, p.setor, p.nomeProd, p.preco, p.validade.dia, p.validade.mes, p.validade.ano, p.estoque);
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
    arq = fopen("planilhas/Produtos.csv", "r");
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

void preencheLista(Produtos *lista){
    FILE *csv;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    csv = fopen("planilhas/Produtos.csv", "r");
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
                case 4:
                    stringParaData(campos, &lista[i].validade);
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

int atualizaProdutos(Produtos *lista, int qntProd){
    //Limpa a tela
    limparTela();

    //Separador estético
    separador();
    bool verifica = false;
    int index = 0;
    int i =0;
    int id;
    printf("Digite o id do produto que será alterado: ");
    scanf(" %d", &id);
    while (i < qntProd && id != lista[i].id)
    {
        i++;
    }
    if (i == qntProd)
    {
        printf("Não foi possível encontrar o produto.\nCadastre o produto na sessão de cadastro.\n");
        getchar();
        getchar();
        limparTela();
        return 0;
    }
    else{
        while (index != 9)
        {
            index = menuAtualizaProd();

            switch (index)
            {
            case 1:
                separador();
                verifica = false;
                printf("Digite um novo setor para o produto %s: ", lista[i].nomeProd);
                scanf(" %[^\n]s", lista[i].setor);
                while (!(verifica))
                {
                    if (strcmp(lista[i].setor, "Higiene") == 0 || strcmp(lista[i].setor, "Limpeza") == 0 || strcmp(lista[i].setor, "Bebidas") == 0 || strcmp(lista[i].setor, "Frios") == 0 || strcmp(lista[i].setor, "Padaria") == 0 || strcmp(lista[i].setor, "Acougue") == 0) 
                    {
                        verifica = true;
                    }  
                    //Caso os valores continuem falsos, pede para o usuário digitar uma nova string
                    else
                    {
                        printf("O setor esta incorreto e/ou nao existe.\n");
                        printf("Os setores validos sao: \nAcougue;\nBebidas;\nFrios;\nHigiene;\nLimpeza;\nPadaria;\n");
                        scanf(" %[^\n]s", lista[i].setor);
                    }  
                }
                printf("Esse é o novo setor: %s\nCaso esteja errado, poderá alterá-lo novamente.", lista[i].setor);
                getchar();
                getchar();
                limparTela();
                break;
            case 2:
                separador();
                printf("Digite um novo nome para o produto %s: ", lista[i].nomeProd);
                scanf(" %[^\n]s", lista[i].nomeProd);
                printf("Esse é o novo nome: %s\nCaso esteja errado, poderá alterá-lo novamente.", lista[i].nomeProd);
                getchar();
                getchar();
                limparTela();
                break;
            case 3:
                separador();
                printf("Digite um novo preco para o produto %s: ", lista[i].nomeProd);
                scanf(" %lf", &lista[i].preco);
                while (lista[i].preco < 0)
                {
                    printf("Esse não é um valor válido.\nDigite um valor válido: ");
                    scanf(" %lf", &lista[i].preco);
                } 
                printf("Esse é o novo preco: %.2lf\nCaso esteja errado, poderá alterá-lo novamente.", lista[i].preco);
                getchar();
                getchar();
                limparTela();
                break;
            case 4:
                separador();
                printf("Digite uma nova data de validade para o produto %s. \n", lista[i].nomeProd);
                printf("Dia: ");
                scanf(" %d", &lista[i].validade.dia);
                while (lista[i].validade.dia < 0 || lista[i].validade.dia > 31)
                {
                    printf("Esse não é um dia válido.\nDigite um dia válido: ");
                    scanf(" %d", &lista[i].validade.dia);
                } 
                printf("Mes: ");
                scanf(" %d", &lista[i].validade.mes);
                while (lista[i].validade.mes < 0 || lista[i].validade.mes > 12)
                {
                    printf("Esse não é um mês válido.\nDigite um mês válido: ");
                    scanf(" %d", &lista[i].validade.mes);
                }
                printf("Ano: ");
                scanf(" %d", &lista[i].validade.ano);
                while (lista[i].validade.ano < 2024)
                {
                    printf("Esse não é um ano válido.\nDigite um ano válido: ");
                    scanf(" %d", &lista[i].validade.ano);
                }
                printf("Esse é a nova data de validade: %d/%d/%d\nCaso esteja errada, poderá alterá-la novamente.", lista[i].validade.dia, lista[i].validade.mes, lista[i].validade.ano);
                getchar();
                getchar();
                limparTela();
                break;
            case 5:
                separador();
                printf("Digite uma nova quantidade no estoque para o produto %s: ", lista[i].nomeProd);
                scanf(" %d", &lista[i].estoque);
                while (lista[i].estoque < 0)
                {
                    printf("Esse não é uma quantidade válida.\nDigite uma quantidade válida: ");
                    scanf(" %d", &lista[i].estoque);
                }
                printf("Esse é o nova quantidade: %d\nCaso esteja errada, poderá alterá-la novamente.", lista[i].estoque);
                getchar();
                getchar();
                limparTela();
                break;
            case 9:
                printf("Voltando para o menu principal...");
                getchar();
                getchar();
                limparTela();
                break;
            default:
                printf("Não é um digito válido");
                getchar();
                getchar();
                break;
            }
        }
        return 1;
    }
}

void atualizaArquivoCSV(Produtos *lista, int qntProd, int controle){
    FILE *arquivoCSV;
    arquivoCSV = fopen("planilhas/Produtos.csv", "r");
    if (arquivoCSV != NULL)
    {
        if (controle == 1)
        {
            arquivoCSV = fopen("planilhas/Produtos.csv", "w");
            fprintf(arquivoCSV, "Id;Setor;Nome;Preço;Data de Validade;Estoque\n");
            for (int i = 0; i < qntProd; i++)
            {
                fprintf(arquivoCSV, "%d;%s;%s;%.2lf;%d/%d/%d;%d\n", lista[i].id, lista[i].setor, lista[i].nomeProd, lista[i].preco, lista[i].validade.dia, lista[i].validade.mes, lista[i].validade.ano, lista[i].estoque);
            }
        }
        fclose(arquivoCSV);
    }
}

void prodPorSetor(Produtos *lista, int qntProd){
    limparTela();
    if (qntProd > 0)
    {
        char setor[6][20];
        char aux[20];
        bool verifica;
        int i = 0;
        for (int i = 0; i < 6; i++)
        {
            switch (i)
            {
            case 0:
                strcpy(aux, "Acougue");
                break;
            case 1:
                strcpy(aux, "Bebidas");
                break;
            case 2:
                strcpy(aux, "Frios");
                break;
            case 3:
                strcpy(aux, "Higiene");
                break;
            case 4:
                strcpy(aux, "Padaria");
                break;
            case 5:
                strcpy(aux, "Limpeza");
                break;
            default:
                break;
            }
            strcpy(setor[i], aux);
        }
        int cont = 0;
        for (; i < 6; i++)
        {
            verifica = false;
            cont = 0;
            printf("\n%s:\n", setor[i]);
            for (int j = 0; j < qntProd; j++)
            {
                if (strcmp(lista[j].setor, setor[i]) == 0)
                {
                    printf("%d. %s;\n", cont +1, lista[j].nomeProd);
                    verifica = true;
                    cont++;
                }
                
            }
            if (!(verifica))
            {
                printf("Não há produtos cadastrados nesse setor.\n");
            } 
            getchar();
            getchar();
            limparTela();
        }
    }
    else{
        printf("Não há produtos cadastrados.\n");
        getchar();
        getchar();
        limparTela();
    }
}

void baixoEstoque(Produtos *lista, int qntProd){
    bool estoqueBaixo = false;
    if (qntProd > 0)
    {
        for (int i = 0; i < qntProd; i++)
        {
            if (lista[i].estoque <= 5)
            {
                getchar();
                printf("%s está com estoque baixo.\n", lista[i].nomeProd);
                printf("Setor: %s\n", lista[i].setor);
                estoqueBaixo = true;
            }
        }
        if (!(estoqueBaixo))
        {
            printf("Não há produtos com estoque baixo.\n");
            getchar();
            getchar();
            limparTela();
        }
        else{
            getchar();
            limparTela();
        }
    }
    else{
        printf("Não existem produtos cadastrados");
    }
    
}