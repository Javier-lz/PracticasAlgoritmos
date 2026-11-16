#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sorting.h"
#include "times.h"

int main(int argc, char **argv)
{
    int i, num_min, num_max, incr, n_perms;
    char nombre[256];
    char nombre_min[256];
    char nombre_mean[256];
    char nombre_median[256];
    short ret;

    srand(time(NULL));

    if (argc != 11) {
        fprintf(stderr, "Error en los parametros\n");
        exit(-1);
    }

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-num_min") == 0)
            num_min = atoi(argv[++i]);
        else if (strcmp(argv[i], "-num_max") == 0)
            num_max = atoi(argv[++i]);
        else if (strcmp(argv[i], "-incr") == 0)
            incr = atoi(argv[++i]);
        else if (strcmp(argv[i], "-numP") == 0)
            n_perms = atoi(argv[++i]);
        else if (strcmp(argv[i], "-outputFile") == 0)
            strcpy(nombre, argv[++i]);
    }

    snprintf(nombre_min, sizeof(nombre_min), "%s.min", nombre);
    snprintf(nombre_mean, sizeof(nombre_mean), "%s.mean", nombre);
    snprintf(nombre_median, sizeof(nombre_median), "%s.median", nombre);

    ret = generate_sorting_times(QuickSort_min, nombre_min,
                                 num_min, num_max, incr, n_perms);
    if (ret == ERR) exit(-1);

    ret = generate_sorting_times(QuickSort_mean, nombre_mean,
                                 num_min, num_max, incr, n_perms);
    if (ret == ERR) exit(-1);

    ret = generate_sorting_times(QuickSort_median, nombre_median,
                                 num_min, num_max, incr, n_perms);
    if (ret == ERR) exit(-1);

    printf("Correct output\n");

    return 0;
}