/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Gets a random integer in a given range.
*/

#include <stdbool.h>
#include "stdlib.h"

int get_randomnb(int min, int max)
{
    static bool i = false;
    int nb = 0;

    if (!i) {
        srand((size_t)&i);
        i = true;
    }
    if (max == min)
        return (rand() % max);
    nb = rand() % (max - min) + min;
    return (nb);
}