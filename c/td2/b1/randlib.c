/**
* @Description: util_rand.c
* @Author: Mehdi Ghoulam<mehdi@gelk.fr>
* @Created: 2024-02-23
*/

/* Inclusion des librairies ========== */
#include <stdlib.h>

#include "randlib.h"

/* Fonction secondaires =============== */

int randint()
{
    return random();
}

int randint_max(int max)
{
    return (random() / ((double) RAND_MAX + 1)) * max;
}

int randint_range(int min, int max)
{
    return (int) (min + (random() / ((double) RAND_MAX + 1)) * (max - min));
}

float randfloat_01()
{
    return random() / ((float) RAND_MAX + 1);
}

float randfloat_range(float min, float max)
{
    return min + (random() / ((double) RAND_MAX + 1)) * (max - min);
}
