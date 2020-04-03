/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_tetrimino_shape.c
*/

#include "my.h"

static void print_shape_char(const char *shape_line, size_t *x)
{
    size_t tmp = *x;
    size_t star_finder = 0;

    if (shape_line[tmp] == ' ') {
        star_finder = tmp;
        while (shape_line[star_finder] && shape_line[star_finder++] != '*');
        if (!shape_line[star_finder]) {
            *x = star_finder;
            return;
        }
    }
    my_putchar(shape_line[tmp]);
}

void print_tetrimino_shape(char **shape)
{
    register size_t y = 0;
    size_t x = 0;

    if (!shape)
        return;
    while (shape[y]) {
        for (x = 0; shape[y][x]; x += 1)
            print_shape_char(shape[y], &x);
        my_putchar('\n');
        y += 1;
    }
}