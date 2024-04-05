// Mehdi Ghoulam TP1 - Train

#ifndef TRAIN_MANAGMENT_C
#define TRAIN_MANAGMENT_C

typedef struct correspondance {
  char *villeDepart;
  char *villeArrivee;
  char *heureDepart;
  char *heureArrivee;
  int distance;
} correspondence;

typedef struct liste_horaire {
  correspondence horaire;
  struct liste_horaire *suivant;
} liste_horaire;

void ajouter_horaire(liste_horaire **liste, const char *villeDepart,
                     const char *villeArrivee, const char *heureDepart,
                     const char *heureArrivee, const int distance);

void afficher_train_ville(liste_horaire **liste, char *ville);

float determine_vitesse_moyenne_max(liste_horaire **liste,
                                    correspondence **tgv);

void trier_horaires_heures_depart_asc(liste_horaire **liste);

void determine_vd_vers_va(liste_horaire **liste, char *VD, char *VA);

void liberer_memoire_liste(liste_horaire *liste);

void afficher_liste(liste_horaire *liste);

void afficher_train(correspondence horaire);

int hours_to_seconds(int heure, int minute);

int hours_to_minutes(int heure, int minute);

#endif
