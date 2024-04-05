/**
* @Description: TP1 - Exercice 1
* @Author: Mehdi Ghoulam<mehdi@gelk.fr>
* @Created: 2024-03-15
*/

/* Inclusion des librairies =========== */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "listeint.h"

/* Déclaration des prototypes ========= */
int menu();

/* Fonction principale  =============== */
int main(int argc, char *argv[])
{
    maillon_int* premier = NULL;
    maillon_int* nouveau;
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));

    while (!fin) {
        i = menu();

        switch (i) {
            case 1: //Creer une liste de taille aleatoire
                // Detruire la liste avant d'en generer une autre afin de ne pas avoir de memory leak.
                // Autrement, le premier element serai remplace et les elements qui suivent seraient perdu.
                detruire_liste2(&premier);

                // Genere une nouvelle tete de liste
                premier = init_elt();
                // genere la suite de la liste
                for (int i = 0; i < rand() % 20; i++)
                {
                    nouveau = init_elt();
                    inserer2(&premier, nouveau);
                }
                break;

            case 2: // Ajouter
                nouveau = init_elt();
                ajout_tete_v2(&premier, nouveau);
                break;

            case 3: // Inserer (ordre croissant)
                nouveau = init_elt();
                inserer2(&premier, nouveau);
                break;

            case 4: //Supprimer debut:
                supprimer_debut(&premier);
                break;

            case 5: // Supprimer un maillon d'une valeur donnee
                nb = 0;
                scanf("%d", &nb);
                critere_supp_un2(&premier, nb);
                break;

            case 6: // detruire liste
                detruire_liste2(&premier);
                break;

            case 7: // Sauver liste
                sauver_liste(premier);
                break;

            case 8: // Charger liste
                premier = load_liste();
                break;

            default:
                parcourir(premier);
                break;
        }
    }

    return 0;
}

/* Fonction secondaires =============== */

int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
        "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
        "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
        "4 Supprimer l'élément de tête\n"
        "5 Supprimer tous les maillons d'une valeur donnee\n"
        "6 Detruire liste\n"
        "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
        "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin);

    return choix;
}
