
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
