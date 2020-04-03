/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** is_tetri_list_sorted.c
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static bool free_check_list_resources(char *tmp_first, char *tmp_second,
                                        const bool return_val)
{
    if (tmp_first)
        free(tmp_first);
    if (tmp_second)
        free(tmp_second);
    return (return_val);
}

bool is_list_sorted(tetrimino_t **head)
{
    tetrimino_t *tmp = NULL;
    char *tmp_first = NULL;
    char *tmp_second = NULL;
    int cmp_reason = 0;

    if (!head || !(*head))
        return (true);
    tmp = (*head)->next;
    do {
        tmp_first = my_strdup_lowercase(tmp->prev->name);
        tmp_second = my_strdup_lowercase(tmp->name);
        cmp_reason = my_strcmp(tmp_first, tmp_second);
        if (cmp_reason > 0)
            return (free_check_list_resources(tmp_first, tmp_second, 0));
        if (cmp_reason == 0) {
            cmp_reason = my_strcmp(tmp->prev->name, tmp->name);
            if (cmp_reason > 0)
                return (free_check_list_resources(tmp_first, tmp_second, 0));
        }
        tmp = tmp->next;
    } while (tmp != (*head));
    return (free_check_list_resources(tmp_first, tmp_second, 1));
}