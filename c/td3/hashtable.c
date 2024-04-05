// Mehdi Ghoulam TD3-HashTable

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

const int HASHTABLE_ITEMS_SIZE = 53;

ht_key_value_pair *ht_new_key_value_pair(const char *key, const char *value)
{
    ht_key_value_pair *new_element = malloc(sizeof(ht_key_value_pair));
    new_element->key = strdup(key);
    new_element->value = strdup(value);
    return new_element;
}

void ht_del_key_value_pair(ht_key_value_pair *element)
{
    free((void *)element->key);
    free(element->value);
    free(element);
}

ht_hash_table *ht_new(const int size)
{
    ht_hash_table *hashtable = malloc(sizeof(ht_hash_table));
    if (hashtable == NULL) {
        printf("Can't malloc for hashtable");
        exit(1);
    }

    ht_key_value_pair **items = NULL;
    int nb_elem = size == 0 ? HASHTABLE_ITEMS_SIZE : size;

    items = calloc(nb_elem, sizeof(ht_key_value_pair));
    if (items == NULL) {
        printf("Can't calloc for hashtable");
        exit(1);
    }

    hashtable->size = nb_elem;
    hashtable->kv_items = items;
    hashtable->amount = 0;

    return hashtable;
}

void ht_del(ht_hash_table *table)
{
    for (int i = 0; i < table->size; i++) {
        ht_key_value_pair *elem = table->kv_items[i];
        if (elem != NULL) {
            ht_del_key_value_pair(elem);
        }
    }
    free(table->kv_items);
    free(table);
}

void show_hashtable(ht_hash_table *table)
{
    if (table->amount == 0) {
        printf("Le tableau est vide\n");
    } else {
        printf("Il y a %d élement(s) :\n", table->amount);
        for (int i = 0; i < table->size; i++) {
            ht_key_value_pair *item = table->kv_items[i];
            if (item == NULL) {
                continue;
            }
            printf("Idx: %d      Key: %s      Value: %s\n", i, item->key, item->value);
        }
    }
}

double ht_hash(const char *string, const int M, const int alpha)
{
    int n = strlen(string);
    double result = 0;
    for (int i = 0; i < n; i++) {
        result = result + (pow(alpha, i) * toascii(string[i]));
    }
    return fmod(result, M);
}

int ht_give_hash(const char *string, const int M,
            const int alpha_1, const int alpha_2, const int attempt)
{
    const int hash_a = ht_hash(string, M, alpha_1);
    const int hash_b = ht_hash(string, M, alpha_2);
    return fmod(hash_a + (attempt * (hash_b + 1)), M);
}

void ht_insert(ht_hash_table **table, ht_key_value_pair *item)
{
    const int ALPHA_1 = 227;
    const int ALPHA_2 = 397;
    int attempt = 0;
    int hash = ht_give_hash(item->key, (*table)->size, ALPHA_1, ALPHA_2, attempt);
    (*table)->kv_items[hash] = item;
    (*table)->amount++;
}

char *ht_search()
