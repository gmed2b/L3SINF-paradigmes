/**
 * @Description: TP1 - Pile
 * @Author: Mehdi Ghoulam<mehdi@gelk.fr>
 * @Created: 2024-03-15
 */

#include <stdbool.h>
#include <stdlib.h>

#include "pilelib.h"

bool est_vide(pile_int *sommet)
{
    return sommet == NULL;
}

void empiler(pile_int **sommet, pile_int *element)
{
    element->prec = *sommet;
    *sommet = element;
}

int valeur_sommet(pile_int **sommet)
{
    if (*sommet == NULL) {
        return -1;
    }
    return (*sommet)->val;
}

int depiler(pile_int **sommet)
{
    int valeur_sommet = (*sommet)->val;
    pile_int *ancien_sommet = (*sommet);
    *sommet = (*sommet)->prec;
    free(ancien_sommet);

    return valeur_sommet;
}

pile_int *renverser(pile_int **sommet)
{
    pile_int* new_sommet = malloc(sizeof(pile_int));
    if (new_sommet == NULL) {
        exit(1);
    }

    while (! est_vide((*sommet))) {
        pile_int *nouveau = malloc(sizeof(pile_int));
        nouveau->val = depiler(sommet);
        empiler(&new_sommet, nouveau);
    }

    return new_sommet;
}
