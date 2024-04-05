// Mehdi Ghoulam TD2-C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fourmi.h"

char get_user_input();
void print_keybinds();

int main()
{
    srandom(time(NULL));

    fourmi *fourmi = init_fourmi();

    while (1) {
        affiche_p(fourmi);
        affiche_c(fourmi);

        print_keybinds();
        char choice = get_user_input();
        switch (choice) {
            case 'z':
                fourmi->dx = 0;
                fourmi->dy = -1;
                avance(fourmi);
                break;
            case 's':
                fourmi->dx = 0;
                fourmi->dy = 1;
                avance(fourmi);
                break;
            case 'q':
                fourmi->dx = -1;
                fourmi->dy = 0;
                avance(fourmi);
                break;
            case 'd':
                fourmi->dx = 1;
                fourmi->dy = 0;
                avance(fourmi);
                break;
        }

        // clear screen
        printf("\033[H\033[J");
    }

    return 0;
}

char get_user_input()
{
    char choice;
    printf("-> ");
    scanf("%c", &choice);

    if (choice == EOF) {
        printf("End of user input stream!");
        exit(1);
    }
    else if (choice == 0) {
        printf("Bad input!");
        exit(1);
    }

    return choice;
}

void print_keybinds()
{
    printf("Haut: z.   Bas: s.   Gauche: q.   Droite: d.\n");
}
