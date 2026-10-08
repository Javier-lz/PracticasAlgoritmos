/**
 *
 * Descripcion: Implementation of time measurement functions
 *
 * Fichero: times.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "times.h"
#include "sorting.h"

/***************************************************/
/* Function: average_sorting_time Date:            */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short average_sorting_time(pfunc_sort metodo, 
                              int n_perms,
                              int N, 
                              PTIME_AA ptime)
{
  int ** perms; 
  double time; 
  double average_ob; 
  int min_op; 
  int max_op; 

  clock_t ini; 
  clock_t fin; 
  int ret; 
  ini=clock(); 
  //comprobar errores y memoria 

  perms=generate_permutations(n_perms,N); 

  for (int j = 0; j<n_perms;j++){
    ret= metodo(perms[j],0,N-1); 
    //gestionar memorya y errores 
    if (ret < min_op){
      min_op=ret; 
    }
    if(ret>max_op){
      max_op=ret; 
    }
    //comprobar max min

    average_ob+=(double)ret/n_perms; 

  }

  fin= clock(); 
  //comprobar

  ptime->average_ob=average_ob; 
  ptime->max_ob=max_op; 
  ptime->min_ob=min_op; 
  ptime->N=N; 
  ptime->n_elems=n_perms; 
  ptime->time=((fin-ini)/(float)n_perms)/CLOCK_PER_SEC;
   
  // Añadir a la estructura 
  // para time divicir por CLOCKS_PER_SEC 


  // liberar memoria 



/* Your code */
}

/***************************************************/
/* Function: generate_sorting_times Date:          */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{
  /* Your code */
}

/***************************************************/
/* Function: save_time_table Date:                 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short save_time_table(char* file, PTIME_AA ptime, int n_times)
{
  /* your code */
}


