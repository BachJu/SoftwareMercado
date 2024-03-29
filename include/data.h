#ifndef __DATA_H__
#define __DATA_H__

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

/**
 * Transforma string em registro do tipo "Data"
*/
void stringParaData(char *str, Data *data);

/**
 * @return Uma struct do tipo Data com a data de hoje
*/
Data diaAtual();

#endif