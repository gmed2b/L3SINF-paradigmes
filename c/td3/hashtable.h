// Mehdi Ghoulam TD3-HashTable
#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct ht_key_value_pair {
  const char *key;
  char *value;
} ht_key_value_pair;

typedef struct ht_hash_table {
  int size;
  int amount;
  ht_key_value_pair **kv_items;
} ht_hash_table;

/**
 *  Initialise un couple clé-valeur
 */
ht_key_value_pair *ht_new_key_value_pair(const char *key, const char *value);

/**
 *  Supprime et libère la mémoire d'un couple clé-valeur
 */
void ht_del_key_value_pair(ht_key_value_pair *element);

/**
 *  Initialise d'une table de hashage de size element
 */
ht_hash_table *ht_new(const int size);

/**
 *  Supprime une table de hashage
 */
void ht_del(ht_hash_table *table);

/**
 *  Affiche les elements de la table de hashage
 */
void show_hashtable(ht_hash_table *table);

/**
 *  Fonction de hashage simple
 */
double ht_hash(const char *string, const int M, const int alpha);

/**
 *  Fonction double hashage
 */
int ht_give_hash(const char *string, const int M, const int alpha_1,
                 const int alpha_2, const int attempt);

/**
 *  Insert un élément dans la table de hashage
 */
void ht_insert(ht_hash_table **table, ht_key_value_pair *item);

/**
 *  Recherche dans la table de hashage
 */
void ht_search();

#endif
