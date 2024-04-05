#ifndef LISTEINT_H
#define LISTEINT_H

typedef struct maillon {
  int val;
  struct maillon *p_suiv;
} maillon_int;

/**
 *  Créer un nouveau maillon et initialise la valeur
 *  de l'entier entre 0 et 20.
 *  @return maillon_int * : l'element crée
 */
maillon_int *init_elt();

/**
 *  Ajoute un maillon en tête juste avant le premier element.
 *  @param maillon_int* p_tete : pointeur vers le premier element
 *  @param maillon_int* p_nv_elt : pointeur vers le nouvelle element
 *  @return maillon_int * : l'element en tête
 */
maillon_int *ajout_tete_v1(maillon_int *p_tete, maillon_int *p_nv_elt);

/**
 *  Ajoute un maillon en tête du premier element.
 *  @param maillon_int** p_tete : pointeur de pointeur vers le premier element
 *  @param maillon_int* p_nv_elt : pointeur vers le nouvelle element
 *  @return void
 */
void ajout_tete_v2(maillon_int **p_p_tete, maillon_int *p_nv_elt);

/**
 *  Parcours et affiche la liste a partir du premier element
 *  @param maillon_int* p_tete : pointeur vers la tete de liste
 *  @return void
 */
void parcourir(maillon_int *p_tete);

/**
 *  Insere un element dans l'ordre croissant a partir
 *  de l'element p_tete
 *  @param maillon_int* p_tete : pointeur vers un maillon tete
 *  @param maillon_int* p_nv_elt : pointeur vers l'element a inserer
 */
maillon_int *inserer1(maillon_int *p_tete, maillon_int *p_nv_elt);

/**
 *  Insere un element dans l'ordre croissant a partir
 *  de l'element prem
 *  @param maillon_int** prem : pointeur de pointeur vers un maillon tete
 *  @param maillon_int* e : pointeur vers l'element a inserer
 */
void inserer2(maillon_int **prem, maillon_int *e);

/**
 *  Supprime le premier element de la liste
 *  en veillant a redefinir la tete de liste.
 *  Le deuxieme element devient le premier.
 *  Libere la mémoire de l'element supprimé.
 *  @param maillon_int** prem : pointeur de pointeur vers le premier element
 *  @return void
 */
void supprimer_debut(maillon_int **prem);

/**
 *  Supprime tous les maillons dont la valeur est egale a val.
 *  @param maillon_int* prem : pointeur vers le premier element
 *  @param int val : valeur a chercher et supprimer
 *  @return maillon_int* : la nouvelle tete de liste
 */
maillon_int *critere_supp_un1(maillon_int *prem, int val);

/**
 *  Supprime tous les maillons dont la valeur est egale a val.
 *  @param maillon_int* prem : pointeur de pointeur vers le premier element
 *  @param int val : valeur a chercher et supprimer
 *  @return void
 */
void critere_supp_un2(maillon_int **prem, int val);

/**
 *  Meme fonction que supprimer_debut
 *  @param maillon_int** prem : pointeur de pointeur du premier element
 *  @return void
 */
void detruire_liste(maillon_int **prem);

/**
 *  Utilise supprimer_debut mais verifie qu'il y'a un element avant
 *  de déclarer l'element temporaire.
 *  @param maillon_int** prem : pointeur de pointeur du premier element
 *  @return void
 */
void detruire_liste2(maillon_int **prem);

/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à
sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste
                dont le premier élément est pointé par prem.
                Nota : il n'y a pas de libération de la mémoire occupée par la
                liste. Il faut donc la détruire avant d'éventuellement la
recharger.
*/
void sauver_liste(maillon_int *prem);

/**
 *  Charge les données sérialiser dans le fichier "saveliste.bin"
 *  et alloue de la memoire pour chaque element du fichier.
 *  @return maillon_int* : pointeur vers le premier element de la liste
 */
maillon_int *load_liste();

#endif
