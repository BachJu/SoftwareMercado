#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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