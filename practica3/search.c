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

int insert_dictionary(PDICT pdict, int key){
    int A=0, j;

    if (!pdict || key<0)
    {
        return ERR;
    }
    
    if (pdict->size == pdict->n_data)
    {
        return ERR;
    }
    
    pdict->table[pdict->n_data]=key;

    if (pdict->order == SORTED)
    {
        A=pdict->table[pdict->n_data];
        j= pdict->n_data -1;
        while (j>=0 && pdict->table[j]>A)
        {
            pdict->table[j+1]=pdict->table[j];
            j--;
        }
        pdict->table[j+1]=A;
    }
    
    pdict->n_data++;

    return OK;
}

int massive_insertion_dictionary(PDICT pdict, int *keys, int n_keys){
    int i;

    if (!pdict || !keys || n_keys<0)
    {
        return ERR;
    }

    for ( i = 0; i < n_keys; i++)
    {
        if(insert_dictionary(pdict, keys[i])==ERR)
            return ERR;
    }
    
    return OK;
}


int lin_search(int* table, int F, int L , int key, int*ppos){
    int i = F; 
    int count=0; 
    for (i=F;i<=L;i++){
        count++; 
        if(table[i]==key){
            *ppos=i; 
            return count;
        }
    }
    return NOT_FOUND; 
    
}