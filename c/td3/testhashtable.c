// Mehdi Ghoulam TD3-Hashtable

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

void print_menu()
{
    printf("\n");
    printf("1. Afficher table\n");
    printf("2. Inserer element\n");
    printf("3. Rechercher un element\n");
    printf("4. Supprimer element\n");
}

void insert_item(ht_hash_table *table) {
    char *new_item_key = (char *) malloc(50 * sizeof(char));
    char *new_item_value = (char *) malloc(50 * sizeof(char));
    printf("Entrer une clé: ");
    scanf("%s", new_item_key);
    printf("Entrer une valeur:");
    scanf("%s", new_item_value);

    ht_key_value_pair *item = ht_new_key_value_pair(new_item_key, new_item_value);
    ht_insert(&table, item);
}

void search_item(ht_hash_table *table) {

}

int main()
{
    ht_hash_table *table = ht_new(0);
    int choice;
    char *search = (char *) malloc(50 * sizeof(char));

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                show_hashtable(table);
                break;

            case 2:
                insert_item(table);
                break;

            case 3:
                search_item(table);
                break;

            default:
                show_hashtable(table);
                break;
        }
    }

    ht_del(table);
    return 0;
}
