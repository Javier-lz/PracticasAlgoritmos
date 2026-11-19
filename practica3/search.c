#include <stdio.h>
#include <stdlib.h>
#include "search.h"


void free_dictionary(PDICT pdict){

    if(!pdict){
        free(pdict->table);
        free(pdict);
    }
}