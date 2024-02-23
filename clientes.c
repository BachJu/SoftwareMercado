#include "telas.h"
#include "clientes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void novoCliente(Clientes *novoC){
    bool temLet = true;
    
    separador();
    printf("Digite o seu cpf: ");
    scanf(" %[^\n]s", novoC->cpf);
    while (temLet)
    {
        temLet = false;
        for (int i = 0; i < 13; i++)
        {
            if ((novoC->cpf[i] < '0') || (novoC->cpf[i] > '9') || (strlen(novoC->cpf) < 13) || (strlen(novoC->cpf) > 13))
            {
                printf("Cpf inválido.\nDigite o seu cpf: ");
                scanf(" %[^\n]s", novoC->cpf);
                temLet = true;
            }
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

    arqClien = fopen("Cliente.csv", "r");
    if (arqClien == NULL)
    {
        arqClien = fopen("Cliente.csv", "w");
        fprintf(arqClien, "CPF;Nome;Data de Nascimento;Idade;Endereço;Cidade;Estado;Pontos\n");
        fprintf(arqClien, "%s;%s;%d/%d/%d;%d;%s;%s;%s;%d\n", c.cpf, c.nome, c.nascimento.dia, c.nascimento.mes, c.nascimento.ano, c.idade, c.endereco, c.cidade, c.estado, c.pontos);
        fclose(arqClien);
    }
    else{
        arqClien = fopen("Cliente.csv", "a");
        fprintf(arqClien, "%s;%s;%d/%d/%d;%d;%s;%s;%s;%d\n", c.cpf, c.nome, c.nascimento.dia, c.nascimento.mes, c.nascimento.ano, c.idade, c.endereco, c.cidade, c.estado, c.pontos);
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
    arq = fopen("Cliente.csv", "r");
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