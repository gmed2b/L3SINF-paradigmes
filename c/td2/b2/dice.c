/**
 * @Description: dice.c
 * @Author: Mehdi Ghoulam<mehdi@gelk.fr>
 * @Created: 2024-02-23
 */

/* Inclusion des librairies ========== */
#include <stdbool.h>
#include <stdlib.h>
#include "dice.h"
#include "randlib.h"

/* Fonction secondaires =============== */

Dice *create_dices_array(int no_dice)
{
    Dice *arr = malloc(no_dice * sizeof(Dice));
    return arr;
}

void roll_dices(int no_dice, Dice *dices)
{
    for (int i = 0; i < no_dice; i++)
    {
        dices[i].rolledv = randint_range(1, 6);
        dices[i].in_conflict = false;
    }
}

void roll_dices_in_conflict(int no_dice, Dice *dices)
{
    for (int i = 0; i < no_dice; i++)
    {
        if (dices[i].in_conflict)
        {
            dices[i].rolledv = randint_range(1, 6);
        }
    }
}

bool verify_dice_in_conflict(int no_dice, Dice *dices)
{
    bool conflict = false;
    for (int i = 0; i < no_dice - 1; i++)
    {
        for (int j = i + 1; j < no_dice; j++)
        {
            if (dices[i].rolledv == dices[j].rolledv)
            {
                conflict = true;
                dices[i].in_conflict = true;
                dices[j].in_conflict = true;
            }
        }
    }

    return conflict;
}

int calculate_sum(int no_dice, Dice *dices)
{
    int sum = 0;
    for (int i = 0; i < no_dice; i++)
    {
        sum += dices[i].rolledv;
    }

    return sum;
}

int calculate_score(int no_dice)
{
    int max = no_dice * 6;
    return (max / 3) * 2;
}
