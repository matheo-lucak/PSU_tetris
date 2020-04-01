/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "my.h"
#include "tetris_usage.h"
#include "tetris.h"

static void print_usage(char *binary_name)
{
    my_printf(usage, binary_name);
}

static bool should_print_usage(const int ac, char * const av[])
{
    register int index = 0;

    for (index = 0; index < ac; index += 1) {
        if (my_mass_strcmp(av[index], "-h", "--help"))
            return (true);
    }
    return (false);
}

int main(const int ac, char * const av[])
{
    if (ac < 1 || !av || !av[0])
        return (84);
    if (should_print_usage(ac, av)) {
        print_usage(av[0]);
        return (0);
    }
    return (tetris(ac, av));
}