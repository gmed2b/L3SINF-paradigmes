/**
* @Description: TD2 B.1 - Libraire Random
* @Author: Mehdi Ghoulam<mehdi@gelk.fr>
* @Created: 2024-02-23
*/

/* Inclusion des librairies =========== */
#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "randlib.h"

/* Fonction principale  =============== */
int main()
{
    srandom(time(NULL));

    printf("%d\n", randint());
    printf("%d\n", randint_max(3));
    printf("%d\n", randint_range(10, 20));
    printf("%f\n", randfloat_01());
    printf("%f\n", randfloat_range(30, 40));

    return 0;
}
