/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** read_tetriminos_dir.c
*/

#include <stdbool.h>
#include <dirent.h>
#include "tetris.h"

bool read_tetriminos_dir(tetrimino_t **head)
{
    struct dirent *dir_stat = NULL;
    DIR *directory = NULL;

    if (!head)
        return (false);
    directory = opendir("./tetriminos/");
    if (!directory)
        return (false);
    dir_stat = readdir(directory);
    while (dir_stat) {
        if (!(*head))
            add_first_tetrimino(head);
        else
            add_tetrimino(head);
        dir_stat = readdir(directory);
    }
    return (true);
}