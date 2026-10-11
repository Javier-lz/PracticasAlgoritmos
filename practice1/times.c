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
#include <time.h>
#include <limits.h>

/***************************************************/
/* Function: average_sorting_time Date:            */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short average_sorting_time(pfunc_sort metodo, int n_perms,
                           int N, PTIME_AA ptime)
{
    int **perms;
    int i, ret;
    int min_op, max_op;
    long long suma_ob = 0;
    clock_t ini, fin;

    if (metodo == NULL || ptime == NULL ||
        n_perms <= 0 || N <= 0)
        return ERR;

    perms = generate_permutations(n_perms, N);

    if (perms == NULL)
        return ERR;

    ini = clock();

    if (ini == (clock_t)-1) {
        for (i = 0; i < n_perms; i++)
            free(perms[i]);
        free(perms);
        return ERR;
    }

    for (i = 0; i < n_perms; i++) {
        ret = metodo(perms[i], 0, N - 1);

        if (ret < 0) {
            for (i = 0; i < n_perms; i++)
                free(perms[i]);
            free(perms);
            return ERR;
        }

        if (i == 0) {
            min_op = ret;
            max_op = ret;
        } else {
            if (ret < min_op)
                min_op = ret;

            if (ret > max_op)
                max_op = ret;
        }

        if (suma_ob > LLONG_MAX - ret) {
            for (i = 0; i < n_perms; i++)
                free(perms[i]);
            free(perms);
            return ERR;
        }

        suma_ob += ret;
    }

    fin = clock();

    if (fin == (clock_t)-1) {
        for (i = 0; i < n_perms; i++)
            free(perms[i]);
        free(perms);
        return ERR;
    }

    ptime->N = N;
    ptime->n_elems = n_perms;
    ptime->time = ((double)(fin - ini) / CLOCKS_PER_SEC)
                  / n_perms;
    ptime->average_ob = (double)suma_ob / n_perms;
    ptime->min_ob = min_op;
    ptime->max_ob = max_op;

    for (i = 0; i < n_perms; i++)
        free(perms[i]);

    free(perms);

    return OK;
}


/***************************************************/
/* Function: generate_sorting_times Date:          */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, int num_min, int num_max, int incr, int n_perms)
{
  int num, N, j;
  TIME_AA *times=NULL;

  if (method == NULL || file == NULL || num_min <= 0 || num_max < num_min ||incr <= 0 || n_perms <= 0) {
        return ERR;
    }
  
  num= (num_max-num_min)/incr+1; 

  times = malloc(sizeof(TIME_AA)*num); 
  if (!times){
    return ERR; 
  }


  for (j=0; j<num;j++){
    N = num_min + j * incr;
    if (average_sorting_time(method, n_perms, N, &times[j]) == ERR) {
          free(times);
          return ERR;
    }
  }

  if (savetimetable(file, times, num) == ERR) {
        free(times);
        return ERR;
  }

  free(times);

  return OK; 
}

/***************************************************/
/* Function: save_time_table Date:                 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short save_time_table(char* file, PTIME_AA ptime, int n_times)
{
  FILE* fp;  
  int j ; 

  if (file == NULL || ptime == NULL || n_times <= 0) 
    return ERR;

  fp=fopen(file,"W"); 
  if (!fp)
    return ERR;
  
 
  for (j=0; j<n_times;j++){
    if(fprintf(fp,"%d %d %lf %d %d %d\n", ptime[j].N,ptime[j].n_elems,ptime[j].time,ptime[j].average_ob,ptime[j].min_ob,ptime[j].max_ob)<0){
      fclose(fp);
      return ERR;
    }
  }

  if (fclose(fp) != 0) {
        return ERR;
  }

  return OK;
}


