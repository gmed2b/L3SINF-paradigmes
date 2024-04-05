/**
* @Description: TD2 B.2 - Dés
* @Author: Mehdi Ghoulam<mehdi@gelk.fr>
* @Created: 2024-02-23
*/

/* Inclusion des librairies =========== */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "dice.h"

/* Fonction principale  =============== */
int main(int argc, char *argv[])
{
    srandom(time(NULL));

    int no_dice = 0;
    Dice *dices = NULL;
    int total = 0;

    printf("How many dices [1-4] ?\n");
    scanf("%d", &no_dice);
    printf("You choose %d dices\n", no_dice);

    // Réserve un espace mémoire pour les dés
    dices = create_dices_array(no_dice);
    if (dices == NULL)
    {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }

    // Lancer les dés
    roll_dices(no_dice, dices);

    // Affiche les dés
    for (int i = 0; i < no_dice; i++)
    {
        printf("%d\n", dices[i].rolledv);
    }

    // Vérifier si il y a un conflit, relancer les dés si besoin
    while (verify_dice_in_conflict(no_dice, dices))
    {
        printf("There is a conflict, rerolling the dices\n");
        roll_dices_in_conflict(no_dice, dices);
    }

    printf("\nFIN\n");

    // Affiche les dés
    for (int i = 0; i < no_dice; i++)
    {
        printf("%d\n", dices[i].rolledv);
    }

    // Calculer la somme des dés
    int sum = calculate_sum(no_dice, dices);
    printf("La somme des %d dés lancés est de %d.\n", no_dice, sum);

    // Calculer le score
    int needed_score = calculate_score(no_dice);
    printf("Le score nécessaire pour gagner est de %d.\n", needed_score);

    bool win = sum >= needed_score;
    printf("Votre score est ");
    printf(win ? "supérieur" : "inférieur");
    printf(" de %d au seuil.\n", abs(sum - needed_score));

    if (win)
    {
        printf("Bravo, vous avez gagné !\n");
    }
    else
    {
        printf("Désolé, vous avez perdu !\n");
    }

    // Libère la mémoire alloué aux dés
    free(dices);

    return 0;
}

/* Fonction secondaires =============== */
