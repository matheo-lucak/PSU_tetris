/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** update_queue
*/

#include "tetris.h"

void update_queue(tetrimino_t **queue, tetrimino_t *tetrimino_list)
{
    tetrimino_t *tmp = NULL;
    size_t index = 0;

    if (!queue)
        return ;
    index = number_tetrimino(tetrimino_list);
    if (!(*queue)) {
        tmp = get_n_tetrimino(tetrimino_list, get_randomnb(0, index));
        enqueue_tetrimino(queue, tmp);
    }
    if (*queue && !((*queue)->next)) {
        tmp = get_n_tetrimino(tetrimino_list, get_randomnb(0, index));
        enqueue_tetrimino(queue, tmp);
    }
}