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

/***************************************************/
/* Function: InsertSort    Date:                   */
/* Your comment                                    */
/***************************************************/
int InsertSort(int* array, int ip, int iu)
{
  int count=0; 
  for (int i = ip+1; i<iu;i++){
    int x = array[i]; 
    int j=i-1;
    while (j>=ip){
      count++; 
      if (array[j]>x){
        array[j+1]=array[j]; 
        j--; 
      }
    }
    array[j+1]=x; 
    
  }
  return count; 

  /* Your code */
}


/***************************************************/
/* Function: SelectSort    Date:                   */
/* Your comment                                    */
/***************************************************/
int BubbleSort(int* array, int ip, int iu)
{
  /* Your code */
}






