/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** free_tetriminos_list.c
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static void free_tetriminos_node(tetrimino_t *node)
{
    if (node->name)
        free(node->name);
    my_free_arr((void **)node->shape);
    free(node);
}

void free_tetriminos_list(tetrimino_t *head)
{
    tetrimino_t *tmp = NULL;

    if (!head)
        return;
    for (tmp = head; tmp; tmp = head) {
        head = head->next;
        if (tmp)
            free_tetriminos_node(tmp);
    }
    head = NULL;
}