/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_tetriminos
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static char **get_blank_tetrimino(size_t alloc_size)
{
    char **shape = malloc(sizeof(char *) * (alloc_size + 1));
    register size_t index = 0;

    if (!shape)
        return (NULL);
    while (index < alloc_size) {
        shape[index] = malloc(sizeof(char) * (alloc_size + 1));
        if (!(shape[index]))
            return (NULL);
        my_memset(shape[index], ' ', alloc_size);
        shape[index][alloc_size] = '\0';
        index += 1;
    }
    shape[index] = NULL;
    return (shape);
}

static bool init_oriented_shape(tetrimino_t *tetrimino, unsigned short orientation)
{
    char **new_shape = NULL;
    register size_t alloc_size = 0;
    register size_t x = 0;
    register size_t y = 0;

    if (!tetrimino || tetrimino->alloc_side < 1
        || !(tetrimino->shapes[orientation - 1]))
        return (false);
    alloc_size = tetrimino->alloc_side;
    new_shape = get_blank_tetrimino(alloc_size);
    if (!new_shape)
        return (false);
    for (y = 0; y < alloc_size; y += 1) {
        for (x = 0; x < alloc_size; x += 1) {
            if (alloc_size == 5) {
                new_shape[y][x] = tetrimino->shapes[orientation - 1][x][alloc_size - 1 - y];
            }
        }
    }
    tetrimino->shapes[orientation] = new_shape;
    return (true);
}

bool init_all_oriented_shapes(tetrimino_t *tetrimino)
{
    register unsigned short orientation = 1;

    if (!tetrimino)
        return (false);
    for (orientation = 1; orientation < 4; orientation += 1) {
        if (!init_oriented_shape(tetrimino, orientation))
            return (false);
    }
    return (true);
}