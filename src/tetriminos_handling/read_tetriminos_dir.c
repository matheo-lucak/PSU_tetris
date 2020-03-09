/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** read_tetriminos_dir.c
*/

#include <stdbool.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static bool add_tetrimino(tetrimino_t **head, const char file_name[])
{
    tetrimino_t *node = NULL;
    tetrimino_t *tmp = NULL;

    if (!head || !(*head))
        return (false);
    node = malloc(sizeof(tetrimino_t));
    if (!node)
        return (false);
    if (!get_tetrimino(node, file_name))
        return (false);
    for (tmp = (*head); tmp->next; tmp = tmp->next);
    tmp = node;
    return (true);
}

static bool add_first_tetrimino(tetrimino_t **head, const char file_name[])
{
    tetrimino_t *node = NULL;

    if (!head || (*head))
        return (false);
    node = malloc(sizeof(tetrimino_t));
    if (!node)
        return (false);
    if (!get_tetrimino(node, file_name))
        return (false);
    *head = node;
    return (true);
}

bool read_tetriminos_dir(tetrimino_t **head)
{
    struct dirent *dir_stat = NULL;
    DIR *dir = NULL;

    if (!head)
        return (false);
    dir = opendir("./tetriminos/");
    if (!dir)
        return (false);
    for (dir_stat = readdir(dir); dir_stat; dir_stat = readdir(dir)) {
        if (!my_strcmp(dir_stat->d_name, ".")
            || !my_strcmp(dir_stat->d_name, ".."))
            continue;
        if (!(*head) && !add_first_tetrimino(head, dir_stat->d_name))
            return (false);
        else if (!add_tetrimino(head, dir_stat->d_name))
            return (false);
    }
    closedir(dir);
    return ((*head)) ? true : false;
}