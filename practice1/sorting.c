
/**
 *
 * Descripcion: Implementation of sorting functions
 *
 * Fichero: sorting.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "sorting.h"
#include <stdlib.h>

/********************************************/
/* Function: InsertSort                     */
/********************************************/
int InsertSort(int *array, int ip, int iu)
{
    int count = 0;
    int i, x, j;

    if (array == NULL || ip < 0 || iu < ip)
        return ERR;

    for (i = ip + 1; i <= iu; i++) {
        x = array[i];
        j = i - 1;

        while (j >= ip) {
            count++;

            if (array[j] > x) {
                array[j + 1] = array[j];
                j--;
            }
            else {
                break;
            }
        }

        array[j + 1] = x;
    }

    return count;
}

/********************************************/
/* Function: BubbleSort                     */
/********************************************/
int BubbleSort(int *array, int ip, int iu)
{
    int i, j, aux;
    int count = 0;
    int intercambio;

    if (array == NULL || ip < 0 || iu < ip)
        return ERR;

    i = iu;

    while (i > ip) {
        intercambio = 0;

        for (j = ip; j < i; j++) {
            count++;

            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;

                intercambio = 1;
            }
        }

        if (intercambio == 0)
            break;

        i--;
    }

    return count;
}


int MergeSort(int * array, int ip, int iu){
    int m; 
   
    int count_left=0; 
    int count_right=0; 
    int count_merge=0;
    if ( ip > iu || !array || ip <0 ){
        return ERR; 
    }
    if (ip==iu){
        return OK; 
    }
    m = (ip+iu-1)/2; 
    
    count_left=MergeSort(array,ip,m);
    if(count_left==-1){
        return ERR; 
    }
    count_right=MergeSort(array,m+1,iu);
    if(count_right==-1){
        return ERR; 
    }

    count_merge= merge(array,ip,iu,m);
    if(count_merge==-1){
        return ERR; 
    }
    return count_merge+count_left+count_right; 


}


int merge(int* array , int ip, int iu, int im){
int i=0,j=0,k=0; 
int* tabla_aux;
int count=0; 
tabla_aux= malloc(sizeof(int)*(iu-ip+1));
if(! tabla_aux){
    return ERR; 
}
i=ip; 
j=im+1;
while (i<=im &&  j<=iu){
    count++;
    if(array[i]<array[j]){
        tabla_aux[k]=array[i]; 
        i++;
    }
    else{
        tabla_aux[k]=array[j]; 
        j++;
    }
    k++;

}

if (i>im){
    while ( j<=iu){
        tabla_aux[k]=array[j]; 
        j++;
        k++;
    }
}
else if ( j>iu){
    while (i<=im){
        tabla_aux[k]=array[i]; 
        i++;
        k++;
    }
}
j=0; 
for (j=0; j<(iu-ip+1);j++){
    array[ip+j]=tabla_aux[j]; 
}
free(tabla_aux); 

return count; 
}


int QuickSort_mean( int* array, int ip, int iu){
    int pos; 
    pos = ip + (iu-ip)/2; 
    if ( iu < ip ){
        return ERR; 
    }
}

int QuickSort_min(int* array, int ip, int iu){


}


int partition(int * array, int ip, int iu){
    
}

int pivot_min(int*array, int ip, int iu, int * pos){

}