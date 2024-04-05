// Mehdi Ghoulam TP1 - Train

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_null.h>
#include "train_managment.h"

void ajouter_horaire(liste_horaire **liste, const char *villeDepart,
                     const char *villeArrivee, const char *heureDepart,
                     const char *heureArrivee, const int distance)
{
    liste_horaire *new = malloc(sizeof(liste_horaire));
    if (new == NULL) {
        printf("Erreur d'allocation mémoire lors de la creation d'un nouvelle horaire.");
        exit(1);
    }

    new->horaire.villeDepart = strdup(villeDepart);
    new->horaire.villeArrivee = strdup(villeArrivee);
    new->horaire.heureDepart = strdup(heureDepart);
    new->horaire.heureArrivee = strdup(heureArrivee);
    new->horaire.distance = distance;

    new->suivant = (*liste);
    (*liste) = new;
}

void afficher_train_ville(liste_horaire **liste, char *ville)
{
    if ((*liste) == NULL) {
        printf("La liste est vide ...");
    } else {
        printf("Train au depart de %s :\n", ville);

        liste_horaire *ptr = (*liste);
        while (ptr != NULL)
        {
            correspondence train = ptr->horaire;
            if (strcmp(ville, train.villeDepart) == 0) {
                afficher_train(train);
            }
            ptr = ptr->suivant;
        }
    }
}

float determine_vitesse_moyenne_max(liste_horaire **liste, correspondence **tgv)
{
    if ((*liste) == NULL) return 0.0;

    liste_horaire *ptr = (*liste);
    float meilleur_vitesse_moy = 0.0;

    while (ptr != NULL)
    {
        correspondence train = ptr->horaire;

        int heure_depart, minute_depart;
        sscanf(train.heureDepart, "%ih%i", &heure_depart, &minute_depart);
        int temps_depart = hours_to_seconds(heure_depart, minute_depart);

        int heure_arrivee, minute_arrivee;
        sscanf(train.heureArrivee, "%ih%i", &heure_arrivee, &minute_arrivee);
        int temps_arrivee = hours_to_seconds(heure_arrivee, minute_arrivee);

        // Calcul du temps de trajet
        int nb_secondes = temps_arrivee - temps_depart;

        // Calcul de la vitesse moyenne
        float distance_metres = train.distance * 1000.0;
        float vitesse_moyenne = distance_metres / (float) nb_secondes * 3.6;

        // Met a jour la vitesse moyenne si meilleur que le precedent
        if (vitesse_moyenne > meilleur_vitesse_moy) {
            meilleur_vitesse_moy = vitesse_moyenne;
            (*tgv) = &ptr->horaire;
        }

        ptr = ptr->suivant;
    }

    return meilleur_vitesse_moy;
}

void trier_horaires_heures_depart_asc(liste_horaire **liste)
{
    if ((*liste) == NULL) {
        printf("La liste est vide ...");
        return;
    }

    // Sommet de la liste
    liste_horaire *start = (*liste);

    liste_horaire *i;
    liste_horaire *j;
    correspondence temp;

    for (i = start; i->suivant != NULL; i = i->suivant) {
        for (j = i->suivant; j != NULL; j = j->suivant) {
            int ih, im;
            sscanf(i->horaire.heureDepart, "%ih%i", &ih, &im);
            int itime = hours_to_seconds(ih, im);

            int jh, jm;
            sscanf(j->horaire.heureDepart, "%ih%i", &jh, &jm);
            int jtime = hours_to_seconds(jh, jm);

            // Swap si heure de j plus petite que i
            if (jtime < itime) {
                temp = i->horaire;
                i->horaire = j->horaire;
                j->horaire = temp;
            }
        }
    }
}

void determine_vd_vers_va(liste_horaire **liste, char *VD, char *VA)
{
    if ((*liste) == NULL) {
        printf("La liste est vide ...");
        return;
    }

    correspondence premier_train;
    correspondence second_train;

    // Sommet de la liste
    liste_horaire *ptr = (*liste);
    while (ptr != NULL)
    {
        premier_train = ptr->horaire;

        // Filtre par ville de depart
        if (strcmp(premier_train.villeDepart, VD) == 0) {
            // S'il est possible de faire un direct
            if (strcmp(premier_train.villeArrivee, VA) == 0) {
                afficher_train(premier_train);
            } else {

                // Recherche 1 correspondance par ville d'arrivee
                liste_horaire *ptr2 = (*liste);
                while (ptr2 != NULL)
                {
                    second_train = ptr2->horaire;

                    // Filtre par ville de depart
                    if (strcmp(second_train.villeDepart, premier_train.villeArrivee) == 0) {
                        // S'il y'a une correspondance disponible avec le second train
                        if (strcmp(second_train.villeArrivee, VA) == 0) {
                            // Verifie l'ecart horaire entre l'heure d'arrivee du premier train
                            // et l'heure de depart du second (+5min et -120m)
                            // printf("premier: %s  %s\n", premier_train.villeDepart, premier_train.villeArrivee);
                            // printf("second: %s  %s\n", second_train.villeDepart, second_train.villeArrivee);

                            int heure_depart_second, minute_depart_second;
                            sscanf(second_train.heureDepart, "%ih%i", &heure_depart_second, &minute_depart_second);
                            int temps_depart_second = hours_to_minutes(heure_depart_second, minute_depart_second);
                            // printf("%d\n", temps_depart_second);

                            int heure_arrivee_premier, minute_arrivee_premier;
                            sscanf(premier_train.heureArrivee, "%ih%i", &heure_arrivee_premier, &minute_arrivee_premier);
                            int temps_arrivee_premier = hours_to_minutes(heure_arrivee_premier, minute_arrivee_premier);
                            // printf("%d\n", temps_arrivee_premier);

                            // Verifie que le second train par apres etre arrive
                            if (temps_depart_second > temps_arrivee_premier) {
                                // verifie si il y a +5min ou -120m
                                if (
                                    (temps_depart_second - temps_arrivee_premier) > 5
                                    &&
                                    (temps_depart_second - temps_arrivee_premier) < 120
                                ) {
                                    afficher_train(premier_train);
                                    afficher_train(second_train);
                                }
                            }
                        }
                    }

                    ptr2 = ptr2->suivant;
                }

            }
        }

        ptr = ptr->suivant;
    }
}

void liberer_memoire_liste(liste_horaire *liste)
{
    // Liberer la memoire
    liste_horaire *ptr = liste;
    while (ptr != NULL)
    {
        liste_horaire *next = ptr->suivant;

        // Liberer les string alloué lors de la copie à l'insertion
        free(ptr->horaire.villeDepart);
        free(ptr->horaire.villeArrivee);
        free(ptr->horaire.heureDepart);
        free(ptr->horaire.heureArrivee);

        // Liberer l'element
        free(ptr);

        // Passage au suivant
        ptr = next;
    }
}

void afficher_liste(liste_horaire *liste)
{
    // Affichage de la liste
    if (liste == NULL) {
        printf("La liste est vide ...");
    } else {
        printf("Horaires de trains : \n");
        liste_horaire *ptr = liste;
        while (ptr != NULL)
        {
            afficher_train(ptr->horaire);
            ptr = ptr->suivant;
        }
    }
}

void afficher_train(correspondence horaire)
{
    printf("%s (%s) -> ", horaire.villeDepart, horaire.heureDepart);
    printf("%s (%s)", horaire.villeArrivee, horaire.heureArrivee);
    printf(" | %d km\n", horaire.distance);
}

int hours_to_seconds(int heure, int minute)
{
    return (heure * 3600) + (minute * 60);
}

int hours_to_minutes(int heure, int minute)
{
    return hours_to_seconds(heure, minute) / 60;
}
