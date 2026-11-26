#include "times.h"
#include "search.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


short average_search_time(pfunc_search method,
    char order,
    int size,
    int n_perms,
    pfunc_key_generator generator,
    int n_keys,
    PTIME_AA ptime){

    int i=0,j=0; 
    int ** perms; 
    int * key; 
    PDICT* dicts;
    clock_t ini,fin;
    int ret; 
    double average; 
    int max_val,min_val;
    int pos; 

    if (!method || size<=0 || n_perms<0 || !generator || n_keys<0 || !ptime)
    {
        return ERR;
    }
    
    perms=generate_permutations(n_perms,size);
    if (!perms)
    {
        return ERR;
    }
    
    dicts=malloc(n_perms,sizeof(DICT)); 
    if(!dicts){
        return ERR; 
    }
    

    for(i = 0; i<n_perms; i++){
        dicts[i]=init_dictionary(size,order); 

        massive_insertion_dictionary(dicts[i],perms[i],size); 
    }

    for ( j = 0; j < n_perms; j++)
    {
        free(perms[j]);
    }
    free(perms);
    
    key=malloc(n_keys*sizeof(int));
    if (!key)
    {
        for ( i = 0; i < n_perms; i++)
        {
            free(dicts[i]);
        }
        free(dicts);
        return ERR;
    }

    generator(key,n_keys,size); 
    
    ini=clock();
    if (ini == (clock_t)-1)
    {
        for ( i = 0; i < n_perms; i++)
        {
            free(dicts[i]);
        }
        free(dicts);
        free(key);
        return ERR;
    }
    
    for (j=0;j<n_perms;j++){
        for (i=0; i<n_keys;i++){
            ret = search_dictionary(dicts[j],key[i],&pos,method); 
            average+=ret/n_keys/n_perms; 
            
            if (ret > max_val){
                max_val=ret;
            }
            if(ret<min_val){
                min_val=ret; 
            }
        }
    }
    fin=clock(); 
       if (fin == (clock_t)-1)
    {
        for ( i = 0; i < n_perms; i++)
        {
            free(dicts[i]);
        }
        free(dicts);
        free(key);
        return ERR;
    }
    ptime->max_ob=max_val; 
    ptime->min_ob=min_val; 
    ptime->n_elems=n_perms*n_keys; 
    ptime->size=size; 
    ptime->average_ob=average; 
    ptime->time= ((double)(fin - ini) / CLOCKS_PER_SEC) / n_perms/n_keys;

    for ( i = 0; i < n_perms; i++){
        {
            free(dicts[i]);
        }
        free(dicts);
        free(key);
    }
    
    return OK;
}


short generate_search_times(pfunc_search method,
    char order,
    char* file,
    int min_size,
    int max_size,
    int size_incr,
    int n_perms,
    pfunc_key_generator generator,
    int n_keys){

    int num, N, j;
    TIME_AA *times=NULL;

    if (method == NULL || file == NULL || min_size <= 0 || max_size < min_size ||size_incr <= 0 || n_perms <= 0) {
        return ERR;
    }
    
    num= (max_size-min_size)/size_incr+1; 

    times = malloc(sizeof(TIME_AA)*num); 
    if (!times){
        return ERR; 
    }

    for (j=0; j<num;j++){
        N = min_size + j * size_incr;
        if (average_search_time(method,order,N,n_perms,generator,n_keys,&times[j]) == ERR) {
            free(times);
            return ERR;
        }
    }

    if (save_time_table(file, times, num) == ERR) {
        free(times);
        return ERR;
    }

    free(times);

    return OK; 

}

short save_time_table(char* file, PTIME_AA ptime, int n_times)
{
  FILE* fp;  
  int j ; 

  if (file == NULL || ptime == NULL || n_times <= 0) 
    return ERR;

  fp=fopen(file,"w"); 
  if (!fp)
    return ERR;
  
 
  for (j=0; j<n_times;j++){
    if(fprintf(fp,"%d %d %f %f %d %d\n", ptime[j].size,ptime[j].n_elems,ptime[j].time,ptime[j].average_ob,ptime[j].min_ob,ptime[j].max_ob)<0){
      if(fclose(fp)!=0)
        return ERR; 
        
      return ERR;
    }
  }

  if (fclose(fp) != 0) {
        return ERR;
  }

  return OK;
}