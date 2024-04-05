#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

typedef struct maillon {
    int val;
    struct maillon* p_suiv;
}maillon_int;

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


/**
 *  Créer un nouveau maillon et initialise la valeur
 *  de l'entier entre 0 et 20.
 *  @return maillon_int * : l'element crée
 */
maillon_int* init_elt()
{
    maillon_int* p_nv_elt = malloc(sizeof(maillon_int));
    p_nv_elt->val = rand() % 21;
    p_nv_elt->p_suiv = NULL;
    return p_nv_elt;
}

/**
 *  Ajoute un maillon en tête juste avant le premier element.
 *  @param maillon_int* p_tete : pointeur vers le premier element
 *  @param maillon_int* p_nv_elt : pointeur vers le nouvelle element
 *  @return maillon_int * : l'element en tête
 */
maillon_int* ajout_tete_v1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    p_nv_elt->p_suiv = p_tete;
    p_tete = p_nv_elt;
    return p_tete;
}

/**
 *  Ajoute un maillon en tête du premier element.
 *  @param maillon_int** p_tete : pointeur de pointeur vers le premier element
 *  @param maillon_int* p_nv_elt : pointeur vers le nouvelle element
 *  @return void
 */
void ajout_tete_v2(maillon_int** p_p_tete, maillon_int* p_nv_elt)
{
    p_nv_elt->p_suiv = *p_p_tete;
    *p_p_tete = p_nv_elt;
}

/**
 *  Parcours et affiche la liste a partir du premier element
 *  @param maillon_int* p_tete : pointeur vers la tete de liste
 *  @return void
 */
void parcourir(maillon_int* p_tete)
{
    if (p_tete == NULL)
        printf("liste vide");
    else
        while (p_tete != NULL) {
            printf("%d--", p_tete->val);
            p_tete = p_tete->p_suiv;
        }
    putchar('\n');
}

/**
 *  Insere un element dans l'ordre croissant a partir
 *  de l'element p_tete
 *  @param maillon_int* p_tete : pointeur vers un maillon tete
 *  @param maillon_int* p_nv_elt : pointeur vers l'element a inserer
 */
maillon_int* inserer1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    maillon_int* n, * prec;

    if (p_tete == NULL || p_nv_elt->val <= p_tete->val) {
        p_nv_elt->p_suiv = p_tete;
        p_tete = p_nv_elt;
    }
    else {
        n = prec = p_tete;
        while (n != NULL && p_nv_elt->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        p_nv_elt->p_suiv = n;
        prec->p_suiv = p_nv_elt;
    }
    return p_tete;
}

/**
 *  Insere un element dans l'ordre croissant a partir
 *  de l'element prem
 *  @param maillon_int** prem : pointeur de pointeur vers un maillon tete
 *  @param maillon_int* e : pointeur vers l'element a inserer
 */
void inserer2(maillon_int** prem, maillon_int* e)
{
    maillon_int* n, * prec;
    if (*prem == NULL || e->val <= (*prem)->val){
        e->p_suiv = *prem;
        *prem = e;
    }
    else {
        n = prec = *prem;
        while (n != NULL && e->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        e->p_suiv = n;
        prec->p_suiv = e;
    }
}

/**
 *  Supprime le premier element de la liste
 *  en veillant a redefinir la tete de liste.
 *  Le deuxieme element devient le premier.
 *  Libere la mémoire de l'element supprimé.
 *  @param maillon_int** prem : pointeur de pointeur vers le premier element
 *  @return void
 */
void supprimer_debut(maillon_int** prem)
{
    maillon_int* n;
    if (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

/**
 *  Supprime tous les maillons dont la valeur est egale a val.
 *  @param maillon_int* prem : pointeur vers le premier element
 *  @param int val : valeur a chercher et supprimer
 *  @return maillon_int* : la nouvelle tete de liste
 */
maillon_int* critere_supp_un1(maillon_int* prem, int val)
{
    maillon_int* e = prem, * prec = NULL, * n;

    while (e != NULL) {
        n = NULL;
        if (e->val == val) {
            n = e;
            if (prec == NULL)
                prem = e->p_suiv;
            else
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        e = e->p_suiv;
        if (n != NULL)
            free(n);
    }
    return prem;

}

/**
 *  Supprime tous les maillons dont la valeur est egale a val.
 *  @param maillon_int* prem : pointeur de pointeur vers le premier element
 *  @param int val : valeur a chercher et supprimer
 *  @return void
 */
void critere_supp_un2(maillon_int** prem, int val)
{
    maillon_int* e = *prem, * prec = NULL, * n;

    while (e != NULL) {
        n = NULL;
        if (e->val == val) {
            n = e;
            if (prec == NULL)
                *prem = e->p_suiv;
            else
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        e = e->p_suiv;
        if (n != NULL)
            free(n);
    }
}

/**
 *  Meme fonction que supprimer_debut
 *  @param maillon_int** prem : pointeur de pointeur du premier element
 *  @return void
 */
void detruire_liste(maillon_int** prem)
{
    maillon_int* n;
    while (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

/**
 *  Utilise supprimer_debut mais verifie qu'il y'a un element avant
 *  de déclarer l'element temporaire.
 *  @param maillon_int** prem : pointeur de pointeur du premier element
 *  @return void
 */
void detruire_liste2(maillon_int** prem)
{
    while (*prem != NULL)
        supprimer_debut(prem);
}

/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste
                dont le premier élément est pointé par prem.
                Nota : il n'y a pas de libération de la mémoire occupée par la
                liste. Il faut donc la détruire avant d'éventuellement la recharger.
*/
void sauver_liste(maillon_int* prem)
{
    //ouvrir un fichier binaire en écriture : suffixe b
    FILE* f=fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n",f);
    // si liste non vide
    if (prem != NULL) {
        if (f==NULL)
            fprintf(stderr,"erreur création fichier :%i\n",errno);
        else // parcourir la liste jusque fin
            while (prem != NULL) {
                // écrire chaque maillon en binaire
                if (1 !=fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr,"Erreur d'écriture du maillon %p\n",prem);
                else
                // passer au maillon suivant
                prem = prem->p_suiv;
            }
            fclose(f);	// fermer le fichier
    }
    else
        fprintf(stderr,"pas de sauvegarde pour une liste vide\n");
}

/**
 *  Charge les données sérialiser dans le fichier "saveliste.bin"
 *  et alloue de la memoire pour chaque element du fichier.
 *  @return maillon_int* : pointeur vers le premier element de la liste
 */
maillon_int* load_liste()
{
    FILE* f;
    maillon_int* prem = NULL, * p, e;
    if ((f= fopen("saveliste.bin", "rb")) != NULL) {
        prem = malloc(sizeof(maillon_int));
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem;
        while (fread(&e, sizeof(maillon_int), 1, f)) {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f);
    }
    else
        printf("erreur ou fichier inexistant");
    return prem;
}

int main()
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
