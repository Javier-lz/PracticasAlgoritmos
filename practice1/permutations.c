/**
 *
 * Descripcion: Implementation of function that generate permutations
 *
 * File: permutations.c
 * Autor: Carlos Aguirre
 * Version: 1.1
 * Fecha: 21-09-2019
 *
 */


#include "permutations.h"
#include<stdlib.h>
/***************************************************/
/* Function: random_num Date:                      */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random number           */
/* between two given numbers                       */
/*                                                 */
/* Input:                                          */
/* int inf: lower limit                            */
/* int sup: upper limit                            */
/* Output:                                         */
/* int: random number                              */
/***************************************************/
int random_num(int inf, int sup)
{
  if(inf<0 || sup >RAND_MAX)
    return ERR;
  return (rand()/(RAND_MAX+1.))*(sup-inf+1)+inf;


  /* your code */
}

/***************************************************/
/* Function: generate_perm Date:                   */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random permutation      */
/*                                                 */
/* Input:                                          */
/* int n: number of elements in the permutation    */
/* Output:                                         */
/* int *: pointer to integer array                 */
/* that contains the permitation                   */
/* or NULL in case of error                        */
/***************************************************/
int* generate_perm(int N)
{
     int i, rand, dum;
  int* perm=NULL;
  if(N<0)
    return NULL;
  perm=malloc(N*sizeof(int));
  if(!perm)
    return NULL;
  for ( i = 0; i < N; i++)
  {
  perm[i]=i+1;
  }
  for ( i = 0; i < N; i++)
  {
  rand = random_num(i, N-1);
  dum= perm[rand];
  perm[rand] = perm[i];
  perm[i] = dum;
  }
  return perm;
}

/***************************************************/
/* Function: generate_permutations Date:           */
/* Authors:                                        */
/*                                                 */
/* Function that generates n_perms random          */
/* permutations with N elements                    */
/*                                                 */
/* Input:                                          */
/* int n_perms: Number of permutations             */
/* int N: Number of elements in each permutation   */
/* Output:                                         */
/* int**: Array of pointers to integer that point  */
/* to each of the permutations                     */
/* NULL en case of error                           */
/***************************************************/
int** generate_permutations(int n_perms, int N)
{
  int** perms = malloc(sizeof(int*)*n_perms); 
  int i = 0; 
  for ( i = 0; i<n_perms;i++){
    perms[i]=generate_perm(N); 
    if (perms[i]==NULL){
      int j=0; 
      for  (j=0; j<i;j++){
        free(perms[j]); 
      }
    }
  }
  return perms; 

}
