#ifndef RANDLIB_H
#define RANDLIB_H

#define _DEFAULT_SOURCE

/**
 * Generate a random number
 */
int randint();

/**
 * Generate a random number between 0 and max
 * @param max
 */
int randint_max(int max);

/**
 * Generate a random number between min and max
 * @param min
 * @param max
 */
int randint_range(int min, int max);

/**
 * Generate a random floating-point number between 0 and 1
 */
float randfloat_01();

/**
 * Generate a random floating-point number between min and max
 * @param min
 * @param max
 */
float randfloat_range(float min, float max);

#endif
