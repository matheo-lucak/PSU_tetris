/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "my.h"
#include "tetris.h"

int tetris(const int ac, char * const av[])
{
    tetrimino_t *tetrimino_list = NULL;
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    if (!parse_option(ac, av, &options))
        return (84);
    if (!(read_tetriminos_dir(&tetrimino_list)))
        return (84);
    free_tetriminos_list(tetrimino_list);
    return (0);
}

int main(const int ac, char * const av[])
{
    if (ac < 2)
        return (84);
    return (tetris(ac, av));
}