#include <stdio.h>
#include <stdlib.h>
#include "search.h"

PDICT init_dictionary(int size, char order){
    PDICT dic = (PDICT)malloc(sizeof(DICT)); //Crear diccionario 
    if(! dic)
        return NULL; 
    
    dic->size=size; 
    dic->order=order; 
    dic->n_data=0; 
    return dic; 

}

void free_dictionary(PDICT pdict){

    if(!pdict){
        free(pdict->table);
        free(pdict);
    }
}