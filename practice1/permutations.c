
/**
 * Description: Implementation of functions that generate permutations
 *
 * File: permutations.c
 */

#include "permutations.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * Generates a random integer between inf and sup, both included.
 * Returns ERR if the arguments are invalid.
 */
int random_num(int inf, int sup)
{
    unsigned long long interval;
    unsigned long long total;
    unsigned long long limit;
    unsigned long long r;

    if (inf < 0 || sup < inf)
        return ERR;

    total = (unsigned long long)RAND_MAX + 1ULL;
    interval = (unsigned long long)sup -
               (unsigned long long)inf + 1ULL;

    if (interval > total)
        return ERR;

    limit = total - (total % interval);

    do {
        r = (unsigned long long)rand();
    } while (r >= limit);

    return inf + (int)(r % interval);
}

/**
 * Generates a random permutation of N elements.
 * Returns NULL in case of error.
 */
int *generate_perm(int N)
{
    int *perm;
    int i;
    int rand_index;
    int temp;

    if (N <= 0)
        return NULL;

    if ((size_t)N > (size_t)-1 / sizeof(int))
        return NULL;

    perm = malloc((size_t)N * sizeof(int));

    if (perm == NULL)
        return NULL;

    for (i = 0; i < N; i++) {
        perm[i] = i + 1;
    }

    for (i = 0; i < N; i++) {
        rand_index = random_num(i, N - 1);

        if (rand_index == ERR) {
            free(perm);
            return NULL;
        }

        temp = perm[i];
        perm[i] = perm[rand_index];
        perm[rand_index] = temp;
    }

    return perm;
}

/**
 * Generates n_perms random permutations of N elements.
 * Returns NULL in case of error.
 */
int **generate_permutations(int n_perms, int N)
{
    int **perms;
    int i;
    int j;

    if (n_perms <= 0 || N <= 0)
        return NULL;

    if ((size_t)n_perms > (size_t)-1 / sizeof(int *))
        return NULL;

    perms = malloc((size_t)n_perms * sizeof(int *));

    if (perms == NULL)
        return NULL;

    for (i = 0; i < n_perms; i++) {
        perms[i] = NULL;
    }

    for (i = 0; i < n_perms; i++) {
        perms[i] = generate_perm(N);

        if (perms[i] == NULL) {
            for (j = 0; j < i; j++) {
                free(perms[j]);
            }

            free(perms);
            return NULL;
        }
    }

    return perms;
}
