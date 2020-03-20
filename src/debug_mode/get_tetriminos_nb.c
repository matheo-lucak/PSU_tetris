/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** get_tetriminos_nb.c
*/

#include "tetris.h"

size_t get_tetriminos_nb(tetrimino_t **head)
{
    tetrimino_t *tmp = NULL;
    size_t nb = 0;

    if (!head || !(*head))
        return (0);
    tmp = *head;
    do {
        tmp = tmp->next;
        if (tmp && !tmp->error)
            nb += 1;
    } while (tmp != *head);
    return (nb);
}