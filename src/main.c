/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include <unistd.h>
#include "tetris.h"

int tetris(const char * const input[])
{
    option_t options;
    int index = 0;

    if (!input)
        return (84);
    while (input[index]) {
        index += 1;
    }
}

int main(const int ac, const char * const av [])
{
    if (ac < 2)
        return (84);
    return (tetris(av + 1));
}