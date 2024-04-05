# Reflexion / notes :

## Objectifs

Faire de l'ajout, de la recherche, du calcul et un trie des elements

## Structures disponibles

### Tableau

- Accès à un élément constant O(1)
- Recherche et trie efficace
- Insertion : peut etre complique lorsqu'il n'y a plus de place dans le tableau
  doit creer un nouvelle espace memoire plus grand et recopier les donnees existante

### Liste chainees

- plus de souplesse qu'un tableau
- acces / ajout / suppression en debut de liste constant O(1)
- Trie par selection possible avec un liste simplement chainee O(N²)
- Pour encore plus optimiser le programme, on peut dans le futur utiliser le trie par insertion

## Choix final

- Utilisation d'une liste chainee pour la souplesse
- Trie par selection pour le trie
- Pas a se soucier de la taille de la liste

### Reference

[Comparaison tableaux, listes](https://mpechaud.fr/scripts/donnees/listestableaux.html#tab)
[Trie liste chainee](https://www.youtube.com/watch?v=KLBlezbA2XI)
