#include "../include/vendas.h"
#include "../include/telas.h"
#include "../include/clientes.h"
#include "../include/data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void novoCliente(Clientes *novoC){
    bool invalido = true, temLetra;
    
    separador();
    printf("Digite o seu cpf no formato XXX.XXX.XXX-XX: ");
    scanf(" %[^\n]s", novoC->cpf);
    while (invalido)
    {
        invalido = false;
        temLetra = false;
        while ((strlen(novoC->cpf) < 14) || (strlen(novoC->cpf) > 14))
        {
            printf("Cpf inválido.\nDigite o seu cpf: ");
            scanf(" %[^\n]s", novoC->cpf);
            invalido = true;
        }
        for (int i = 0; i < 14; i++)
        {
            if (i == 3 || i == 7)
            {
                while (novoC->cpf[i] != '.')
                {
                    printf("Há algo de errado no cpf.\nO formato é XXX.XXX.XXX-XX.\nEstá faltando um .\nPor gentileza, digite '.'\n");
                    scanf(" %c", &novoC->cpf[i]);
                }  
            }
            else{
                if (i == 11)
                {
                    while (novoC->cpf[i] != '-')
                    {
                        printf("Há algo de errado no cpf.\nO formato é XXX.XXX.XXX-XX.\nEstá faltando um -\nPor gentileza, digite '-'\n");
                        scanf(" %c", &novoC->cpf[i]);
                    } 
                }
                else{
                    if (novoC->cpf[i] < '0' || novoC->cpf[i] > '9')
                    {
                        temLetra = true;
                    }
                }
            }
        }
        if (temLetra)
        {
            invalido = true;
            printf("O cpf possui letras.\nDigite o cpf novamente: ");
            scanf(" %[^\n]s", novoC->cpf);
        }
    }
    printf("Digite o seu nome: ");
    scanf(" %[^\n]s", novoC->nome);
    printf("Digite sua data de nascimento.\n");
    printf("Dia: ");
    scanf(" %d", &novoC->nascimento.dia);
    while (novoC->nascimento.dia < 0 || novoC->nascimento.dia > 31)
    {
        printf("Dia invalido.\nDigite o dia: ");
        scanf(" %d", &novoC->nascimento.dia);
    }
    
    printf("Mes: ");
    scanf(" %d", &novoC->nascimento.mes);
    while (novoC->nascimento.mes < 0 || novoC->nascimento.mes > 12)
    {
        printf("Mes invalido.\nDigite o mes: ");
        scanf(" %d", &novoC->nascimento.mes);
    }
    printf("Ano: ");
    scanf(" %d", &novoC->nascimento.ano);
    while (novoC->nascimento.ano > 2023||novoC->nascimento.ano < 0)
    {
        printf("Ano invalido.\nDigite o ano: ");
        scanf(" %d", &novoC->nascimento.ano);
    }
    printf("Digite a sua idade: ");
    scanf(" %d", &novoC->idade);
    while ((2024 - novoC->nascimento.ano) != novoC->idade && ((2024 - novoC->nascimento.ano) - 1) != novoC->idade)
    {
        printf("A idade está inconsistente com o ano de nascimento.\nPor gentileza, digite a idade novamente: ");
        scanf(" %d", &novoC->idade);
    }
    
    printf("Digite seu endereço: ");
    scanf(" %[^\n]s", novoC->endereco);
    printf("Digite sua cidade: ");
    scanf(" %[^\n]s", novoC->cidade);
    printf("Digite seu estado: ");
    scanf(" %[^\n]s", novoC->estado);
    novoC->pontos = 0;
    limparTela();
}
void arquivoCSVCliente(Clientes c){
    FILE *arqClien;

    arqClien = fopen("planilhas/Clientes.csv", "r");
    if (arqClien == NULL)
    {
        arqClien = fopen("planilhas/Clientes.csv", "w");
        fprintf(arqClien, "CPF;Nome;Data de Nascimento;Idade;Endereço;Cidade;Estado;Pontos\n");
        fprintf(arqClien, "%s;%s;%d/%d/%d;%d;%s;%s;%s;%d\n", c.cpf, c.nome, c.nascimento.dia, c.nascimento.mes, c.nascimento.ano, c.idade, c.endereco, c.cidade, c.estado, c.pontos);
        fclose(arqClien);
    }
    else{
        arqClien = fopen("planilhas/Clientes.csv", "a");
        fprintf(arqClien, "\n");
        fprintf(arqClien, "%s;%s;%d/%d/%d;%d;%s;%s;%s;%d", c.cpf, c.nome, c.nascimento.dia, c.nascimento.mes, c.nascimento.ano, c.idade, c.endereco, c.cidade, c.estado, c.pontos);
        fclose(arqClien);
    }
}

//Conta quantos produtos estão resgitrados no arquivo CSV
int contClientesCSV(){
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
    arq = fopen("planilhas/Clientes.csv", "r");
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

void preencheClientes(Clientes *clientes){
    FILE *csv;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    csv = fopen("planilhas/Clientes.csv", "r");
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
                    strcpy(clientes[i].cpf, campos);
                    break;
                case 1:
                    strcpy(clientes[i].nome, campos);
                    break;
                case 2:
                    stringParaData(campos, &clientes[i].nascimento);
                    break;
                case 3:
                    clientes[i].idade = atoi(campos);
                    break;
                case 4:
                    strcpy(clientes[i].endereco, campos);
                    break;
                case 5:
                    strcpy(clientes[i].cidade, campos);
                    break;
                case 6:
                    strcpy(clientes[i].estado, campos);
                    break;
                case 7:
                    clientes[i].pontos = atoi(campos);
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
int atualizaCliente(Clientes *clientes, int qntC){
    //Limpa a tela
    limparTela();

    //Separador estético
    separador();
    int i = 0;
    int index = 0;
    char cpf[50];
    printf("Digite o cpf do cliente que será alterado: ");
    scanf(" %[^\n]s", cpf);
    while (i < qntC && strcmp(clientes[i].cpf,cpf)!=0)
    {
        i++;
    }
    
    if (i == qntC)
    {
        printf("Não foi possível encontrar o cliente.\nCadastre o cliente na sessão de cadastro.\n");
        getchar();
        getchar();
        limparTela();
        return 0;
    }
    else{
        while (index !=9)
        {
            index = menuAtualizaC();
            switch (index)
            {
            case 1:
                separador();
                printf("Digite o novo nome: ");
                scanf(" %[^\n]s", clientes[i].nome);
                printf("Esse é o novo nome %s.\nCaso esteja errado, poderá alterá-lo novamente", clientes[i].nome);
                getchar();
                getchar();
                limparTela();
                break;
            case 2:
                separador();
                printf("Digite a nova idade: ");
                scanf(" %d", &clientes[i].idade);
                while (clientes[i].idade <= 0)
                {
                    printf("Não é uma idade válida.\nPor gentileza, digite uma nova idade.\n");
                    scanf(" %d", &clientes[i].idade);
                }
                printf("Esse é a nova idade %d.\nCaso esteja errado, poderá alterá-la novamente", clientes[i].idade);
                getchar();
                getchar();
                limparTela();
                break;
            case 3:
                separador();
                printf("Digite o novo endereço: ");
                scanf(" %[^\n]s", clientes[i].endereco);
                printf("Esse é o novo endereço %s.\nCaso esteja errado, poderá alterá-lo novamente", clientes[i].endereco);
                getchar();
                getchar();
                limparTela();
                break;
            case 4:
                separador();
                printf("Digite a nova cidade: ");
                scanf(" %[^\n]s", clientes[i].cidade);
                printf("Esse é a nova cidade %s.\nCaso esteja errado, poderá alterá-la novamente", clientes[i].cidade);
                getchar();
                getchar();
                limparTela();
                break;
            case 5:
                separador();
                printf("Digite o novo estado: ");
                scanf(" %[^\n]s", clientes[i].estado);
                printf("Esse é o novo estado %s.\nCaso esteja errado, poderá alterá-lo novamente", clientes[i].estado);
                getchar();
                getchar();
                limparTela();
                break;
            case 9:
                printf("Voltando ao menu principal...");
                getchar();
                getchar();
                limparTela();
                break;
            default:
                printf("Não é um digito válido");
                break;
            }
        }
        return 1;
    }
}

int atualizaPontos(Clientes *clientes, int qntC, Vendas *compras, int qntItens){
    int i =0;
    char cpf[14];
    separador();
    printf("Digite o cpf para atualizar os pontos: ");
    scanf(" %[^\n]s", cpf);
    while (i < qntC && strcmp(clientes[i].cpf, cpf) != 0)
    {
        i++;
    }
    if (i ==  qntC)
    {
        printf("Esse cpf não existe/foi cadastrado.\nPor gentileza, efetue o cadastro antes de alterar a pontuação.");
        getchar();
        getchar();
        limparTela();
        return 0;
    }
    else{
        int idVenda;
        int j =0;
        separador();
        printf("Digite o id da compra: ");
        scanf(" %d", &idVenda);
        while (j < qntItens && compras[j].idVenda != idVenda)
        {
            j++;
        }
        if (j == qntItens || strcmp(compras[j].cpf, cpf)!=0){
            printf("Essa venda não foi efetuada ou o id da venda pertence a outro cliente.");
            getchar();
            getchar();
            limparTela();
            return 0;
        }
        else{
            int pontos = clientes[i].pontos;
            printf("Essa é a pontuação atual: %d\n", clientes[i].pontos);
            printf("Esse é a quantidade de pontos pela venda: %d\n", (int)compras[j].valorTotal);
            clientes[i].pontos = 0;
            clientes[i].pontos = pontos + (int)compras[j].valorTotal;
            printf("Essa é a nova pontuação: %d\n", clientes[i].pontos);
            getchar();
            getchar();
            limparTela();
            return 1;
        }
    }
}

void atualizaClientesCSV(Clientes *clientes, int qntC, int controle){
    FILE *arqC;
    arqC = fopen("planilhas/Clientes.csv", "r");
    if (arqC != NULL)
    {
        if (controle == 1)
        {
            arqC = fopen("planilhas/Clientes.csv", "w");
            fprintf(arqC, "CPF;Nome;Nascimento;Idade;Endereço;Cidade;Estado;pontos\n");
            for (int i = 0; i < qntC; i++)
            {
                fprintf(arqC, "%s;%s;%d/%d/%d;%d;%s;%s;%s;%d\n",
                clientes[i].cpf, clientes[i].nome, clientes[i].nascimento.dia, clientes[i].nascimento.mes, clientes[i].nascimento.ano,
                clientes[i].idade, clientes[i].endereco, clientes[i].cidade, clientes[i].estado, clientes[i].pontos);
            }    
        }
        fclose(arqC);
    }
}

void idadeClientes(Clientes *clientes, int qntC){
    int cont = 0;
    for (int i = 0; i < qntC; i++)
    {
        if (clientes[i].idade >= 18 && clientes[i].idade <=25)
        {
            separador();
            printf("O cliente %s tem entre 18 e 25 anos\n", clientes[i].nome);
            getchar();
            getchar();
            limparTela();
            cont++;
        }
    }
    separador();
    printf("No total %d clientes tem entre 18 e 25 anos.", cont);
    separador();
    getchar();
    limparTela();
}

void maisPontos(Clientes *clientes, int qntC){
    bool tem = false;
    for (int i = 0; i < qntC; i++)
    {
        if (clientes[i].pontos >= 1000)
        {
            printf("O cliente %s tem %d pontos.\n", clientes[i].nome, clientes[i].pontos);
            getchar();
            getchar();
            tem = true;
        }
    }
    if (!(tem))
    {
        separador();
        printf("Não existem clientes cadastrados com mais de 1000 pontos.\n");
        getchar();
        getchar();
        limparTela();
    }
    
}