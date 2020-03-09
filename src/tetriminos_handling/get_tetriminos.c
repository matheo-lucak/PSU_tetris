/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** get_tetriminos.c
*/

#include <stdbool.h>
#include "tetris.h"

bool get_tetrimino(tetrimino_t *node, const char file_name[])
{
    if (!node || !file_extension_determ(file_name, ".tetrimino"))
        return (false);
    *node = (tetrimino_t){NULL, NULL, {0, 0}, 0, NULL};
    return (true);
}