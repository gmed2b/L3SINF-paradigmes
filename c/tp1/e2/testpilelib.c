/**
 * @Description: TP1 - Pile
 * @Author: Mehdi Ghoulam<mehdi@gelk.fr>
 * @Created: 2024-03-16
 */

/* Inclusion des librairies =========== */
#include <stdio.h>
#include <stdlib.h>

#include "pilelib.h"

/* Déclaration des prototypes ========= */
void afficher_pile(pile_int *sommet);
void ajouter_element(pile_int **sommet);

void liberer_memoire_pile(pile_int *sommet);
void afficher_menu();
int choix_utilisateur(const char *prompt, const char *error_message);

/* Fonction principale  =============== */
int main(int argc, char *argv[])
{
    pile_int* sommet = NULL;
    int choix;
    int val_sommet;

    while (1)
    {
        afficher_menu();
        choix = choix_utilisateur("Entrer une option: ", "Invalide! Doit etre un entier entre 1..4");

        switch (choix)
        {
            case 1: // Afficher
                afficher_pile(sommet);
                break;

            case 2: // Ajouter
                ajouter_element(&sommet);
                break;

            case 3: // valeur sommet
                val_sommet = valeur_sommet(&sommet);
                printf("Valeur au sommet : %d", val_sommet);
                break;

            case 4: // valeur sommet et depile
                depiler(&sommet);
                break;

            case 5: // renverser la pile
                sommet = renverser(&sommet);
                break;
        }
    }

    liberer_memoire_pile(sommet);

    return 0;
}

/* Fonction secondaires =============== */

void afficher_pile(pile_int *sommet)
{
    if (est_vide(sommet))
    {
        printf("Vide...\n");
    }
    else
    {
        while (! est_vide(sommet))
        {
            printf("-- %d ", sommet->val);
            sommet = sommet->prec;
        }
        printf("\n");
    }
}

void ajouter_element(pile_int **sommet)
{
    pile_int *nouveau = malloc(sizeof(pile_int));
    int valeur = choix_utilisateur("Valeur: ", "Entier uniquement!");
    nouveau->val = valeur;

    empiler(sommet, nouveau);
}

void liberer_memoire_pile(pile_int *sommet)
{
    while (! est_vide(sommet))
    {
        pile_int *ancien = sommet;
        sommet = sommet->prec;
        free(ancien);
    }
}

void afficher_menu()
{
    printf("\n");
    printf("1 - Afficher la pile\n");
    printf("2 - Empiler un nouvelle element\n");
    printf("3 - Afficher la valeur au sommet\n");
    printf("4 - Depiler\n");
    printf("5 - Renverser\n");
}

int choix_utilisateur(const char* prompt, const char* error_message)
{
    int value;
    printf("%s", prompt);
    int result = scanf("%d", &value);

    if (result == EOF)
    {
        printf("End of user input stream\n");
        exit(1);
    }
    else if (result == 0)
    {
        printf("%s\n", error_message);
        exit(1);
    }

    printf("\n");
    return value;
}
