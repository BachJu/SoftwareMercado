#include "telas.h"
#include "clientes.h"
#include "data.h"
#include "vendas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void novaVenda(Vendas, *novoV)
{
    printf("Digite seu CPF:\n");
    scanf("%[^\n]s", novoV->cpf);
    
}