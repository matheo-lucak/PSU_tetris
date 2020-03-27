/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** dequeue
*/

#include <stdlib.h>
#include "tetris.h"

void dequeue_tetrimino(tetrimino_t **queue)
{
    tetrimino_t *save = NULL;

    if (!queue || !(*queue))
        return ;
    save = *queue;
    *queue = (*queue)->next;
    free(save);
}