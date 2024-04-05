// Mehdi Ghoulam TD2-C

#include <stdio.h>
#include <stdlib.h>
#include "fourmi.h"
#include "randlib.h"

const int WIDTH = 80;
const int HEIGHT = 20;
const int COLOR_RANGE = 255;
const int SYM_RANGE_1 = 'A';
const int SYM_RANGE_2 = 'Z';

fourmi *init_fourmi()
{
    fourmi *new_fourmi = malloc(sizeof(fourmi));

    new_fourmi->x = randint_max(WIDTH);
    new_fourmi->y = randint_max(HEIGHT);
    new_fourmi->dx = randint_range(-5, 5);
    new_fourmi->dy = randint_range(-3, 3);
    new_fourmi->color = randint_max(COLOR_RANGE);
    new_fourmi->sym = (char) randint_range(SYM_RANGE_1, SYM_RANGE_2);

    return new_fourmi;
}

void avance(fourmi *fourmi)
{
    fourmi->x += fourmi->dx;
    fourmi->y += fourmi->dy;
}

void affiche_p(fourmi *fourmi)
{
    printf("Fourmi: \n");
    printf("   Position: (%d, %d)", fourmi->x, fourmi->y);
    printf("   Direction: (%d, %d)\n", fourmi->dx, fourmi->dy);
    printf("   Couleur: %d", fourmi->color);
    printf("   Symbole: %c\n", fourmi->sym);
}

void affiche_c(fourmi *fourmi)
{
    // Premiere ligne
    printf("*");
    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("*\n");

    // Lignes
    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            if (y == fourmi->y && x == fourmi->x) {
                printf("%c", fourmi->sym);
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }

    // Derniere ligne
    printf("*");
    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("*\n");
}
