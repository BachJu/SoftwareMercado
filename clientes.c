#include "telas.h"
#include "clientes.h"
#include "data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void novoCliente(Clientes *novoC){
    bool invalido = true, temLetra;
    
    separador();
    printf("Digite o seu cpf: ");
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
                    printf("Há algo de errado no cpf.\nO formato é XXX.XXX.XXX-XX.\nFalta um .\n");
                    scanf(" %c", &novoC->cpf[i]);
                }  
            }
            else{
                if (i == 11)
                {
                    while (novoC->cpf[i] != '-')
                    {
                        printf("Há algo de errado no cpf.\nO formato é XXX.XXX.XXX-XX.\nFalta um -\n");
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
    printf("CPF: %s", novoC->cpf);
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

    arqClien = fopen("Clientes.csv", "r");
    if (arqClien == NULL)
    {
        arqClien = fopen("Clientes.csv", "w");
        fprintf(arqClien, "CPF;Nome;Data de Nascimento;Idade;Endereço;Cidade;Estado;Pontos\n");
        fprintf(arqClien, "%s;%s;%d/%d/%d;%d;%s;%s;%s;%d\n", c.cpf, c.nome, c.nascimento.dia, c.nascimento.mes, c.nascimento.ano, c.idade, c.endereco, c.cidade, c.estado, c.pontos);
        fclose(arqClien);
    }
    else{
        arqClien = fopen("Clientes.csv", "a");
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
    arq = fopen("Clientes.csv", "r");
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
    csv = fopen("Clientes.csv", "r");
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
    int aux,j;
    bool verifica = false;
    int index = 0;
    int i =0;
    char cpf[14];
    printf("Digite o cpf do cliente: ");
    scanf(" %[^\n]s", cpf);
    while (i < qntC && strcmp(clientes[i].cpf, cpf) !=0)
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
                printf("Digite o novo cpf: ");
                scanf(" %[^\n]s", clientes->cpf);
                printf("Esse é o novo cpf %s", clientes->cpf);
                break;
            
            default:
                break;
            }
        }
        return 1;
    }
}