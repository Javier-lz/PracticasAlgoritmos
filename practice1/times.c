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
#include <stdlib.h>

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
  int num= (num_max-num_min)/incr+1; 
  PTIME_AA*times = malloc(sizeof(PTIME_AA)*num); 
  if (times == NULL){
    return ERR; 
  }


  for (int j=0; j<num;j++){
    average_sorting_time(method,n_perms,num_min+j*incr,&times[j]);
    //gestion errores + memoria 
    if (times[j]==NULL){
      free(times); 
      return ERR; 
    }
  }
  return OK; 
  /* Your code */
}

/***************************************************/
/* Function: save_time_table Date:                 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short save_time_table(char* file, PTIME_AA ptime, int n_times)
{

  FILE* fp; 
  fp=fopen(file,"W"); 
  //control de errores 
  int j ; 
  for (j=0; j<n_times;j++){
    fprintf(fp,"%d %d %lf %d %d %d\n", ptime[j].N,ptime[j].n_elems,ptime[j].time,ptime[j].average_ob,ptime[j].min_ob,ptime[j].max_ob);
    
  }

  /* your code */
}


