// Mehdi Ghoulam TP1 - Train

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_ssize_t.h>
#include "train_managment.h"

void print_menu();
void inserer_horaire(liste_horaire **liste);
liste_horaire *charger_liste_trains(const char *path);

int main()
{
    // Liste d'horaires
    liste_horaire *liste = charger_liste_trains("train.csv");

    int choice;
    char *search;
    correspondence *tgv;
    float mvm = 0.0;
    char *VD;
    char *VA;

    // ajouter_horaire(&liste, "Lille", "Paris", "8h00", "8h59", 237);
    // ajouter_horaire(&liste, "Lille", "Lyon", "7h00", "10h00", 709);
    // ajouter_horaire(&liste, "Lille", "Calais", "15h19", "18h34", 110);
    // ajouter_horaire(&liste, "Paris", "Marseille", "12h00", "18h00", 900);
    // ajouter_horaire(&liste, "Lyon", "Marseille", "10h07", "15h01", 450);
    // ajouter_horaire(&liste, "Lyon", "Marseille", "11h50", "17h00", 450);

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                inserer_horaire(&liste);
                break;

            case 1:
                afficher_liste(liste);
                break;

            case 2:
                printf("Saisie: ");
                scanf("%s", search);
                afficher_train_ville(&liste, search);
                break;

            case 3:
                mvm = determine_vitesse_moyenne_max(&liste, &tgv);
                printf("Le trajet le plus rapide est ");
                printf("%s - %s a %s ", tgv->villeDepart, tgv->villeArrivee, tgv->heureDepart);
                printf("(%d km) avec une vitesse de %f km/h !\n", tgv->distance, mvm);
                // printf("Vitesse de %f km/h !\n", mvm);
                break;

            case 4:
                trier_horaires_heures_depart_asc(&liste);
                break;

            case 5:
                printf("Ville depart: ");
                scanf("%s", VD);
                printf("Ville arrivee: ");
                scanf("%s", VA);
                determine_vd_vers_va(&liste, VD, VA);
                break;
        }
    }

    liberer_memoire_liste(liste);

    return 0;
}

void print_menu()
{
    printf("\n");
    printf("0. Insérer une horaire\n");
    printf("1. Afficher les trains\n");
    printf("2. Rechercher par ville\n");
    printf("3. Determine vitesse moyenne\n");
    printf("4. Trier liste par horaire de depart croissant\n");
    printf("5. Determine chemin plus rapide pour ville de depart et ville d'arrivee\n");
    printf("$> ");
}

void inserer_horaire(liste_horaire **liste)
{
    char *ville_depart = malloc(15 * sizeof(char));
    char *ville_arrivee = malloc(15 * sizeof(char));
    char *heure_depart = malloc(5 * sizeof(char));
    char *heure_arrivee = malloc(5 * sizeof(char));
    int distance;
    printf("Ville depart: ");
    scanf("%s", ville_depart);
    printf("Heure depart: ");
    scanf("%s", heure_depart);
    printf("Ville arrivee: ");
    scanf("%s", ville_arrivee);
    printf("Heure arrivee: ");
    scanf("%s", heure_arrivee);
    printf("Distance: ");
    scanf("%d", &distance);

    ajouter_horaire(liste, ville_depart, ville_arrivee, heure_depart, heure_arrivee, distance);
}

liste_horaire *charger_liste_trains(const char *path)
{
    liste_horaire *liste = NULL;

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir %s en lecture\n", path);
        exit(1);
    }

    char *line = NULL;
    size_t n = 0;
    ssize_t read;

    // Tant qu'il y'a des lignes a lire
    while ((read = getline(&line, &n, file)) != -1) {
        char *ville_depart = malloc(15 * sizeof(char));
        char *ville_arrivee = malloc(15 * sizeof(char));
        char *heure_depart = malloc(6 * sizeof(char));
        char *heure_arrivee = malloc(6 * sizeof(char));
        int distance;

        // printf("read %zu bytes:\n", read);
        // printf("%s", line);

        // Ce code utilise %[^,] dans le format de sscanf pour spécifier la lecture de tout caractère sauf une virgule. Cela permet de lire chaque champ correctement jusqu'à la virgule suivante.

        if (sscanf(line, "%[^,],%[^,],%[^,],%[^,],%d", ville_depart, ville_arrivee, heure_depart, heure_arrivee, &distance) == 5) {
            ajouter_horaire(&liste, ville_depart, ville_arrivee, heure_depart, heure_arrivee, distance);
        }
    }

    if (line) {
        free(line);
    }

    return liste;
}
