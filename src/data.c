#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"

void stringParaData(char *str, Data *data){
    int i = 0, c=0;
    char tmp[5];
    while( str[i] != '/')
    {
        tmp[c++] = str[i++];        
    }
    tmp[c] = 0;
    data->dia = atoi(tmp);
    c = 0;
    i++;
    while( str[i] != '/')
    {
        tmp[c++] = str[i++];        
    }
    tmp[c] = 0;
    data->mes = atoi(tmp);
    c = 0;
    i++;
    while( str[i] != 0)
    {
        tmp[c++] = str[i++];        
    }
    tmp[c] = 0;
    data->ano = atoi(tmp);  
}

Data diaAtual(){
    Data hoje;
    time_t t = time(NULL);
    struct tm *dataAtual = localtime(&t);

    hoje.dia = dataAtual->tm_mday;
    hoje.mes = dataAtual->tm_mon + 1;
    hoje.ano = dataAtual->tm_year + 1900;

    return hoje;
}