
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
    /* Your code */
}
