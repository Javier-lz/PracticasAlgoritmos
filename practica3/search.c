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
    dic->table=(int * ) malloc(size*sizeof(int)); 
    if (!dic->table){
        free(dic); 
        return NULL; 
    }
    return dic; 

}

void free_dictionary(PDICT pdict){

    if(!pdict){
        free(pdict->table);
        free(pdict);
    }
}