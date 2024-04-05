#ifndef DICE_H
#define DICE_H

/**
 * rolledv - the rolled value of the dice
 * in_conflict - if the dice as the same value as another dice
 */
typedef struct Dice {
  int rolledv;
  bool in_conflict;
} Dice;

/**
 * allocate memory for dices array
 */
Dice *create_dices_array(int no_dice);

/**
 * roll all dices
 */
void roll_dices(int no_dice, Dice *dices);

/**
 * roll all dices in conflict
 */
void roll_dices_in_conflict(int no_dice, Dice *dices);

/**
 * return true if there is dices in conflict
 */
bool verify_dice_in_conflict(int no_dice, Dice *dices);

/**
 * calculate the sum of all dices
 */
int calculate_sum(int no_dice, Dice *dices);

/**
 * calculate the score needed to win
 */
int calculate_score(int no_dice);

#endif
