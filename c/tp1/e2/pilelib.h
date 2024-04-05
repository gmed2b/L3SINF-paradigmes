/**
 * @Description: TP1 - Pile
 * @Author: Mehdi Ghoulam<mehdi@gelk.fr>
 * @Created: 2024-03-15
 */

#ifndef PILELIB_H
#define PILELIB_H

#include <stdbool.h>
#include <stdio.h>

typedef struct pile {
  int val;
  struct pile *prec;
} pile_int;

/**
 *  Verifie si la pile est vide.
 *  @param pile_int *sommet : sommet de pile
 *  @return bool
 */
bool est_vide(pile_int *sommet);

/**
 *  Empile un element en sommet de pile
 *  @param pile_int **sommet : sommet de pile
 *  @param pile_int *element : element a inserer
 *  @return void
 */
void empiler(pile_int **sommet, pile_int *element);

/**
 *  Recupere la valeur au sommet
 *  @param pile_int **sommet : sommet de pile
 *  @return int
 */
int valeur_sommet(pile_int **sommet);

/**
 *  Recupere la valeur au sommet et depile
 *  @param pile_int **sommet : sommet de pile
 *  @return int
 */
int depiler(pile_int **sommet);

/**
 * Renverse la pileé
 */
pile_int *renverser(pile_int **sommet);

#endif
