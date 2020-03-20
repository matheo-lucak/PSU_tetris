/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "my.h"
#include "tetris.h"

static void set_default_options(option_t *options)
{
    *options = (option_t){.level = 1,
                    .game_option = 0,
                    .map_size = (dimensions_t){20, 10},
                    .control_keys = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN},
                    .option_keys = {'q', ' '}};
}

int tetris(const int ac, char * const av[])
{
    tetrimino_t *tetrimino_list = NULL;
    option_t options;

    set_default_options(&options);
    if (!parse_option(ac, av, &options))
        return (84);
    if (!(read_tetriminos_dir(&tetrimino_list)))
        return (84);
    print_prog_stats(&tetrimino_list, options);
    free_tetriminos_list(tetrimino_list);
    return (0);
}

int main(const int ac, char * const av[])
{
    return (tetris(ac, av));
}