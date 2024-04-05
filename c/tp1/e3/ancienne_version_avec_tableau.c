
// int main()
// {
//     horaires_train *SNCF = calloc(1, sizeof(horaires_train));
//     if (SNCF == NULL) {
//         printf("Erreur lors de l'allocation memoire pour horaires_train");
//         exit(1);
//     }
//     // Initialisation du tableau de correspondence a NULL
//     for (int i = 0; i < INITIAL_SIZE_TRAINS_ARRAY; i++) {
//         SNCF->trains[i] = NULL;
//     }

//     ajouter_horaire(SNCF, "Bastia", "Corte", "5h30", "7h50", 122);
//     ajouter_horaire(SNCF, "Bastia", "Calvi", "17h05", "20h30", 224);
//     ajouter_horaire(SNCF, "Corte", "Ajaccio", "8h00", "10h45", 138);

//     afficher_train_ville(SNCF, "Bastia");

//     determine_vitesse_moyenne_max(SNCF);

//     liberation_memoire(SNCF);
//     return 0;
// }


// void liberation_memoire(horaires_train *SNCF)
// {
//     for (int i = 0; i < INITIAL_SIZE_TRAINS_ARRAY; i++) {
//         if (SNCF->trains[i] != NULL) {
//             free(SNCF->trains[i]->villeDepart);
//             free(SNCF->trains[i]->villeArrivee);
//             free(SNCF->trains[i]->heureDepart);
//             free(SNCF->trains[i]->heureArrivee);
//             free(SNCF->trains[i]);
//         }
//     }
//     free(SNCF);
// }


// void ajouter_horaire(horaires_train *SNCF, const char *villeDepart, const char *villeArrivee,
//                      const char *heureDepart, const char *heureArrivee,
//                      const int distance)
// {
//     correspondence *nouveau_train = malloc(sizeof(correspondence));
//     if (nouveau_train == NULL) {
//         printf("Erreur lors de l'allocation mémoire.");
//         exit(1);
//     }

//     nouveau_train->villeDepart = strdup(villeDepart);
//     nouveau_train->villeArrivee = strdup(villeArrivee);
//     nouveau_train->heureDepart = strdup(heureDepart);
//     nouveau_train->heureArrivee = strdup(heureArrivee);
//     nouveau_train->distance = distance;

//     // Verifier s'il y'a de la place dans le tableau, alloué un espace memoire.
//     SNCF->trains[SNCF->size] = nouveau_train;
//     SNCF->size++;
// }

// void afficher_train_ville(horaires_train *SNCF, char *ville)
// {
//     printf("Train au depart de %s :\n", ville);

//     for (int i = 0; i < SNCF->size; i++) {
//         correspondence *train = SNCF->trains[i];
//         if (strcmp(ville, train->villeDepart) == 0) {
//             printf("Depart: %s %s -> Arrivee: %s %s\n", train->villeDepart, train->heureDepart, train->villeArrivee, train->heureArrivee);
//         }
//     }
// }

// void determine_vitesse_moyenne_max(horaires_train *SNCF)
// {
//     for (int i = 0; i < SNCF->size; i++) {
//         correspondence *train = SNCF->trains[i];

//         int heure_depart = atoi(strtok(train->heureDepart, "h"));
//         char *minute_depart = strtok(NULL, "h");
//         printf("%d\n", heure_depart);
//         printf("%s\n", minute_depart);

//     }
// }

// void trier_horaires_heures_depart_asc();
