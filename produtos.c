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
    int aux,j;
    bool verifica = false;
    int index = 0;
    int i =0;
    char nome[50];
    printf("Digite o nome do produto que será alterado: ");
    scanf(" %[^\n]s", nome);
    while (i < qntProd && strcmp(lista[i].nomeProd, nome) !=0)
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
            index = menuAtualiza();

            switch (index)
            {
            case 1:
                separador();

                printf("Digite um novo ID para o produto %s: ", lista[i].nomeProd);
                scanf(" %d", &lista[i].id);
                verifica = false;
                while (!(verifica))
                {
                    verifica = false;
                    j = 0;
                    while (j < i && lista[j].id != lista[i].id)
                    {
                        j++;
                    }
                    if (lista[j].id == lista[i].id && i != j)
                    {
                        aux = lista[j].id;
                        while (aux == lista[i].id)
                        {
                            printf("Esse número de ID já foi utilizado.\nPor gentileza, digite um ID diferente.\n");
                            scanf(" %d", &lista[i].id);
                        }   
                    }
                    else{
                        j = i + 1;
                        while (j > i && j < qntProd && lista[i].id != lista[j].id)
                        {
                            j++;
                        }
                        if (lista[j].id == lista[i].id)
                        {
                            aux = lista[j].id;
                            while (aux == lista[i].id)
                            {
                                printf("Esse número de ID já foi utilizado.\nPor gentileza, digite um ID diferente.\n");
                                scanf(" %d", &lista[i].id);
                            } 
                        }
                        else{
                            verifica = true;
                        }
                    }
                }    
                printf("Esse é o novo ID: %d\nCaso esteja errado, poderá alterá-lo novamente.", lista[i].id);
                getchar();
                getchar();
                break;
            case 2:
                printf("Digite um novo setor para o produto %s: ", lista[i].nomeProd);
                scanf(" %[^\n]s", lista[i].setor);
                //Declara variáveis de contole para comparar com o que o usuário digitar
                bool hig = false, limp = false, beb = false, frio = false, pad = false, aco = false;
                while (!(hig || limp || beb || frio || pad || aco))
                {
                    if (strcmp(lista[i].setor, "Higiene") == 0)
                    {
                        hig = true;
                    }
                    else if (strcmp(lista[i].setor, "Limpeza") == 0)
                    {
                        limp = true;
                    }
                    else if (strcmp(lista[i].setor, "Bebidas") == 0)
                    {
                        beb = true;
                    }
                    else if (strcmp(lista[i].setor, "Frios") == 0)
                    {
                        frio = true;
                    }
                    else if (strcmp(lista[i].setor, "Padaria") == 0)
                    {
                        pad = true;
                    }
                    else if (strcmp(lista[i].setor, "Acougue") == 0)
                    {
                        aco = true;
                    }
                        
                    //Caso os valores continuem falsos, pede para o usuário digitar uma nova string
                    if (!(hig || limp || beb || frio || pad || aco))
                    {
                        printf("O setor esta incorreto e/ou nao existe.\n");
                        printf("Os setores validos sao: \nAcougue;\nBebidas;\nFrios;\nHigiene;\nLimpeza;\nPadaria;\n");
                        scanf(" %[^\n]s", lista[i].setor);
                    }  
                }
                printf("Esse é o novo setor: %s\nCaso esteja errado, poderá alterá-lo novamente.", lista[i].setor);
                getchar();
                getchar();
                break;
            case 3:
                printf("Digite um novo nome para o produto %s: ", lista[i].nomeProd);
                scanf(" %[^\n]s", lista[i].nomeProd);
                printf("Esse é o novo nome: %s\nCaso esteja errado, poderá alterá-lo novamente.", lista[i].nomeProd);
                getchar();
                getchar();
                break;
            case 4:
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
                break;
            case 5:
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
                break;
            case 6:
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
                break;
            case 9:
                printf("Saindo...");
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
    arquivoCSV = fopen("Produtos.csv", "r");
    if (arquivoCSV != NULL && controle == 1)
    {
        arquivoCSV = fopen("Produtos.csv", "w");
        fprintf(arquivoCSV, "Id;Setor;Nome;Preço;Data de Validade;Estoque\n");
        for (int i = 0; i < qntProd; i++)
        {
            fprintf(arquivoCSV, "%d;%s;%s;%.2lf;%d/%d/%d;%d\n", lista[i].id, lista[i].setor, lista[i].nomeProd, lista[i].preco, lista[i].validade.dia, lista[i].validade.mes, lista[i].validade.ano, lista[i].estoque);
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
        for (int i = 0; i < 6; i++)
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
        }
        getchar();
        getchar();
        limparTela();
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