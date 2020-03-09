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
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    if (!parse_option(ac, av, &options))
        return (84);
    return (0);
}

int main(const int ac, char * const av [])
{
    if (ac < 2)
        return (84);
    return (tetris(ac, av));
}