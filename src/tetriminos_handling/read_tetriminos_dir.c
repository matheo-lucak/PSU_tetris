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

    if (!head || !(*head))
        return (false);
    node = malloc(sizeof(tetrimino_t));
    if (!node)
        return (false);
    get_tetrimino(node, file_name);
    node->next = *head;
    node->prev = (*head)->prev;
    (*head)->prev->next = node;
    (*head)->prev = node;
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
    get_tetrimino(node, file_name);
    node->next = node;
    node->prev = node;
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
        if (!file_extension_determ(dir_stat->d_name, ".tetrimino"))
            continue;
        if (!(*head)) {
            if (!add_first_tetrimino(head, dir_stat->d_name))
                return (false);
        } else {
            if (!add_tetrimino(head, dir_stat->d_name))
                return (false);
        }
    }
    closedir(dir);
    return ((*head)) ? true : false;
}